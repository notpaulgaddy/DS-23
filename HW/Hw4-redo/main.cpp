#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <list>
#include "inventory.h"
#include "customer.h"

using namespace std;

int main(int argc, char *argv[]){
    //command line args
    ifstream inventoryInputFile(argv[1]);
    ifstream customerInputFile(argv[2]);
    string inventoryOutputFile = argv[3];
    string customerOutputFile = argv[4];
    //init the values from inventory input file
    string inventoryId, inventoryName;
    int inventoryAmount;
    //gather data for the classes and initialize class stuff
    inventoryInputFile >> inventoryId >> inventoryAmount >> inventoryName;
    list<Inventory> inventoryLines;
    Inventory theInventory;

    int inventNumCount = 0;//count amount of numbers in the id 
    int custoNumCount = 0;//count amount of numbers in the id 
    int custoInventoryIdCount = 0;//count amount of numbers in inventory id
    //while not eof inventoryInputFile >> inventoryId >> inventoryAmount >> inventoryName; then do checks
    // while(theInventory.read(inventoryInputFile,inventoryId, inventoryAmount, inventoryName)){
    while(!inventoryInputFile.eof()){
        inventoryInputFile >> inventoryId >> inventoryAmount >> inventoryName;
        //make a new object with these values
        for(int i=1;i<=4;i++){
            if(!isdigit(inventoryId[i])){
                inventNumCount++;
            }
        }
        if(inventoryId[0]!='T' || inventoryAmount<0 || inventNumCount>0){
            cerr << "Invalid inventory ID " << inventoryId << " found in the inventory file." << endl;
        }
        theInventory = Inventory(inventoryId, inventoryAmount, inventoryName);
        //Inventory new_inventory(string inventoryId, int inventoryAmount, string inventoryName);
        inventoryLines.insert(inventoryLines.end(),theInventory);
    }

    string customerId, action ,customerInventoryId, name;
    int timestamp, customerInventoryQuantity;
    Customer theCustomer;
    list<Customer> customerLines;
    list<Customer> customerWait;
    list<string> rentalList;
    while(!customerInputFile.eof()){
        customerInputFile >> customerId >> action >> timestamp >> customerInventoryQuantity >> customerInventoryId >> name;
        for(int i=1;i<=4;i++){
            if(!isdigit(customerId[i])){
                custoNumCount++;
            }
            if(!isdigit(customerInventoryId[i])){
                custoNumCount++;
            }
        }
        if(customerId[0]!='C' || custoNumCount>0 || !(action=="rent" || action=="return")){
        // || custoNumCount!=4 || !(action=="rent" || action=="return") || custoInventoryIdCount!=4){
            cerr << "Invalid customer information found for ID " << customerId << " in the customer file." << endl;
        }
        else
        {
            cout << theCustomer.the_action() << endl;
            bool succed = false;
            for( std::list<Inventory>::iterator line = inventoryLines.begin(); line != inventoryLines.end(); ++line)
            {   
                if(line->itemIds() == theCustomer.the_cid())
                {
                    succed = true;
                    if(theCustomer.the_action() == "rent")//if the action IS rent
                    {
                        //cout << "no" << endl;
                        // string rentalString = theCustomer.customer_id() + " " + theCustomer.the_name() + " (" + to_string(theCustomer.action_quantity()) + ")"; 
                        // cout << "rent" << rentalString << endl;
                        // rentalList.insert(rentalList.begin(),rentalString);
                        if(line->itemQuantity() >= theCustomer.action_quantity())
                        {
                            line->setItemQuantity(-theCustomer.action_quantity());//subtract the requested amount
                            customerLines.insert(customerLines.end(),theCustomer);
                        }
                        else
                        {
                            customerWait.insert(customerWait.end(),theCustomer);
                        }
                    }else{//return function
                        //
                        line->setItemQuantity(theCustomer.action_quantity());
                        for(std::list<Customer>::iterator wait = customerWait.begin();wait != customerWait.end(); ++wait)
                        {
                            if(wait->the_cid() == line->itemIds() && wait->action_quantity() <= line->itemQuantity())
                            {
                                line->setItemQuantity(-wait->action_quantity());
                                customerLines.insert(customerLines.end(),*wait);
                                customerWait.erase(wait);
                                break;
                            }
                        }
                    }
                    break;
                }                                                                                                         
            }
            if(succed == false)
            {
                //TODO:: put error message if tool didn't exist;
                //cerr << "output error text";
                //cerr << "Customer " << theCustomer.customer_id() << "requested item " << theCustomer.the_cid() << " which is not in the inventory." << endl;
            }      

        }
    }
        //TODO:: sort the customersLines and inventoryLines by id.
        //TODO:: sort customerWait by id
        cout  << endl;
        //TODO:: inventory output
        for(std::list<Inventory>::iterator line = inventoryLines.begin(); line != inventoryLines.end();++line){//iterate through inventory list
            //ex: T1001 0 available chainsaw
            cout << line->itemIds() << " " << line->itemQuantity() << " " << "available " << line->item_name() << endl; 
            string output = "";
    //the ones with 0 not showing up
            //loop through the customers and add to output that match.
            for(std::list<Customer>::iterator theCust  = customerLines.begin(); theCust != customerLines.end(); ++theCust)
            {       
                // cout << line->itemIds() << " " << theCustomer.action_quantity() << " " << "available " << line->item_name() << endl; 
                    //rentals do Rental Customers: C0009 Snoop_Dawg (1)
                    //cout << theCustomer.the_action() << endl;
                    if(theCust->the_cid() == line->itemIds())
                    {
                        output += " " + theCust->customer_id() + " " + theCust->the_name() + " (" + std::to_string(theCust->action_quantity()) + "}"; 
                    }
            }
            if(output.length() > 0)
            {
                    cout << "Rental Customers:" << output << endl;
            }
            output = "";
            for(std::list<Customer>::iterator theCust  = customerWait.begin(); theCust != customerWait.end(); ++theCust)
            {
                    //rentals do Rental Customers: C0009 Snoop_Dawg (1)
                    if(theCust->the_cid() == line->itemIds())
                    {
                        output += " " + theCust->customer_id() + " " + theCust->the_name() + " (" + std::to_string(theCust->action_quantity()) + "}"; 
                    }
            }
            
            if(output.length() > 0)
            {
                    cout << "Pending Customers:" << "cheese" << output << endl;
            }
        }
        //TODO:: customer output
        //list each
        //list Rentals: T2001 (1)
        //list Pending: Pending: T1001 (1)
    }
//waitlist is the current step, put waitlist in correct order