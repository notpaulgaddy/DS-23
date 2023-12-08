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
    int custoInventoryIdCount = 0;
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
        if(inventoryId[0]!='T' || inventoryAmount<0 || inventNumCount<4){
            cerr << "Invalid inventory ID" << inventoryId << "found in the inventory file." << endl;
        }
        Inventory new_inventory(string inventoryId, int inventoryAmount, string inventoryName);
        inventoryLines.push_back(theInventory);
    }

    string customerId, action ,customerInventoryId, name;
    int timestamp, customerInventoryQuantity;
    Customer theCustomer;
    list<Customer> customerLines;
    list<Customer> customerWait;
    while(!customerInputFile.eof()){
        customerInputFile >> customerId >> action >> timestamp >> customerInventoryId >> name;
        for(int i=1;i<=4;i++){
            if(!isdigit(customerId[i])){
                custoNumCount++;
            }
            if(!isdigit(customerInventoryId[i])){
                custoInventoryIdCount++;
            }
        }
        if(customerId[0]!='C' || custoNumCount<4 || action!="rent" || action!="return" || custoInventoryIdCount<4){
            cerr << "Invalid customer information found for ID" << customerId << "in the customer file." << endl;
        }
        else
        {
            bool succed = false;
            for( std::list<Inventory>::iterator line = inventoryLines.begin(); line != inventoryLines.end(); ++line)
            {
                if(line->itemIds() == theCustomer.the_cid())
                {
                    succed = true;
                    if(theCustomer.the_action() == "rent")
                    {
                        if(line->itemQuantity() >= theCustomer.action_quantity())
                        {
                            line->setItemQuantity(-theCustomer.action_quantity());
                            customerLines.insert(customerLines.end(),theCustomer);
                        }
                        else
                        {
                            customerWait.insert(customerWait.end(),theCustomer);
                        }
                    }
                    else
                    {
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
            }      

        }
        //TODO:: sort the customersLines and inventoryLines by id.
        //TODO:: sort customerWait by id
        cout << endl;
        //TODO:: inventory output
        for(std::list<Inventory>::iterator line = inventoryLines.begin(); line != inventoryLines.end();++line)
        {
            //ex: T1001 0 available chainsaw
            cout << line->itemIds() << " " << line->itemQuantity() << " " << line->item_name() << endl;
            string output = "";
            //loop through the customers and add to output that match.
            for(std::list<Customer>::iterator theCust  = customerLines.begin(); theCust != customerLines.end(); ++theCust)
            {
                    //rentals do Rental Customers: C0009 Snoop_Dawg (1)
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
                    cout << "Pending Customers:" << output << endl;
            }
        }

        //TODO:: customer output
        //list each
        //list Rentals: T2001 (1)
        //list Pending: Pending: T1001 (1)


    }
}