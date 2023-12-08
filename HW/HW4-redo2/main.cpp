#include "Customer.h"
#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {       // take in all the command line args
  ifstream inventoryInputFile(argv[1]);  // inventory input file
  ifstream customerInputFile(argv[2]);   // customer input file
  ofstream inventoryOutputFile(argv[3]); // inventory out file
  ofstream customerOutputFile(argv[4]);  // customer out file
  // init the values from inventory input file
  string inventoryId, inventoryName;
  int inventoryAmount;
  // gather data for the classes and initialize class stuff
  list<Inventory> inventoryLines; // create list within inventory class
  Inventory theInventory;         // variable of inventory called theInventory

  if (!inventoryInputFile.good()) { // check that the first file can be opened
    std::cerr << "Can't open " << argv[1] << " to read.\n";
    exit(1);
  }
  if (!customerInputFile.good()) { // check that 2nd file can be opened
    std::cerr << "Can't open " << argv[2] << " to read.\n";
    exit(1);
  }

  while (!inventoryInputFile.eof()) {
    inventoryInputFile >> inventoryId >> inventoryAmount >>
        inventoryName; // read in all the data word by word
    // make a new object with these values
    if (inventoryId[0] != 'T' ||
        inventoryAmount <
            0) { // if it doesnt start with T or have an amount higher than 0
      cerr << "Invalid inventory ID " << inventoryId
           << " found in the inventory file." << endl; // print an error
    }
    theInventory = Inventory(inventoryId, inventoryAmount,
                             inventoryName); // give the inventory these values
    inventoryLines.insert(inventoryLines.end(),
                          theInventory); // insert the new data to the list
  }
  string customerId, action, customerInventoryId, name;
  int timestamp, customerInventoryQuantity;
  int rentedNum =
      0; // var to count the amount of successful rentals from x customer
  int pendingNum = 0;          // same thing but successful wait list
  Customer theCustomer;        // customer class
  list<Customer> customerWait; // customer list to hold the wait list
  list<Customer> rentalList;   // customer list to hold all the rentals

  while (!customerInputFile.eof()) { // read thru the customer file

    customerInputFile >> customerId >> action >> timestamp >>
        customerInventoryQuantity >> customerInventoryId >>
        name; // sift thru the customer data
    theCustomer =
        Customer(customerId, action, timestamp, customerInventoryQuantity,
                 customerInventoryId, name, rentedNum,
                 pendingNum);          // give customer these valueslist
    rentalList.push_back(theCustomer); // add the data to the rental list
    if (customerId[0] != 'C' ||
        !(action == "rent" || action == "return")) { // if has invalid items
      cerr << "Invalid customer information found for ID " << customerId
           << " in the customer file." << endl; // output this
    } else {
      bool idMatch = false; // var to check if tehres a match
      std::list<Inventory>::iterator inventory_line = inventoryLines.begin();
      for (; inventory_line != inventoryLines.end(); // inventory data loop
           ++inventory_line) {                       // lines iterator
        if (inventory_line->itemIds() ==
            theCustomer.the_cid()) { // check if the item ids match
          // theInventory = *inventory_line;
          idMatch = true; // set to true
          break;          // break and go to next item
        } else {
          idMatch = false; // set to false
        }
      }
      if (idMatch == false) { // if theyre not a match
        cerr << "Customer " << theCustomer.customer_id() << "requested item "
             << theCustomer.the_cid() << " which is not in the inventory."
             << endl; // item not in inventory
      }
      if (theCustomer.the_action() == "rent" &&
          (inventory_line->itemQuantity() >= theCustomer.action_quantity()) &&
          idMatch == true) { // if they wanna rent and the item quant is greater
                             // than the request amoutn
        // cout << "doing the rent " << theCustomer.the_cid() << endl;
        // do the rent
        inventory_line->rent_item(
            theCustomer.action_quantity()); // attempt to set the new value to
                                            // newInventoryValue
        theCustomer.numRented_items(theCustomer.action_quantity());
        // give it to them in rental list
        rentalList.insert(rentalList.begin(), theCustomer);
        // keep track of everyone thats ever rented
      } else if (theCustomer.the_action() == "rent" &&
                 (inventory_line->itemQuantity() <
                  theCustomer.action_quantity()) &&
                 idMatch == true) { // add to the pending list
        theCustomer.numPending_items(
            theCustomer
                .action_quantity()); // add a successful pending transaction
        customerWait.insert(
            customerWait.begin(),
            theCustomer); // add the data to the customer wait list
      }
      if (theCustomer.the_action() == "return" &&
          idMatch == true) { // if its a match and they wanna return it
        // do the return
        inventory_line->return_item(
            theCustomer.action_quantity()); // attempt to set the new value to
                                            // newInventoryValue
        // take them off the wait list
        for (std::list<Inventory>::iterator line = inventoryLines.begin();
             line != inventoryLines.end(); ++line) {
          for (std::list<Customer>::iterator wait = customerWait.begin();
               wait != customerWait.end(); ++wait) {
            if (wait->the_cid() == line->itemIds() &&
                wait->action_quantity() <= line->itemQuantity()) {
              // line->return_item(-wait->action_quantity());
              customerWait.erase(wait); // renmove them from the wait list if
                                        // the transaction completed
              break;                    // end loop
            }
          }
        }
        rentalList.pop_back(); // remove them from the end of the lsit
        for (list<Customer>::iterator perCust = rentalList.begin();
             perCust != rentalList.end(); ++perCust) {
          // perCust->print_items();
          if ((*perCust) == theCustomer) { // pointer to the customer and check
                                           // if they're the same person
            rentalList.erase(perCust);     // if so, remove
            break;
          }
        }
      }
    }
  }
  rentalList.pop_back(); // remove them from rental list after return

  list<Inventory> newInventory; // list of new inventories
  for (std::list<Inventory>::iterator line = inventoryLines.begin();
       line != inventoryLines.end(); ++line) {
    std::list<Inventory>::iterator subline = newInventory.begin();
    for (; subline != newInventory.end(); ++subline) {
      if (subline->itemIds() > line->itemIds()) {
        break;
      }
    }
    newInventory.insert(subline, *line);
  }

  for (std::list<Inventory>::iterator line = newInventory.begin();
       line != newInventory.end(); ++line) {
    cout << line->itemIds() << " " << line->itemQuantity() << " "
         << "available " << line->item_name() << endl;
    inventoryOutputFile << line->itemIds() << " " << line->itemQuantity() << " "
                        << "available " << line->item_name() << endl;

    string rentalPrint = "Rental Customers: ";
    string pendingPrint = "Pending Customers: ";
    int rented = 0;
    int waited = 0;
    for (list<Customer>::iterator perCust = rentalList.begin();
         perCust != rentalList.end(); ++perCust) {
      // cout << "Rental Customers: ";
      // perCust->print_items();
      if (line->itemIds() == perCust->the_cid()) {
        rented = 1;
        string newString;
        newString = perCust->print_items();
        rentalPrint += newString;
        // break;
      }
    }

    if (rented) {
      cout << rentalPrint << endl;
      inventoryOutputFile << rentalPrint << endl;
    }
    for (list<Customer>::iterator perWait = customerWait.begin();
         perWait != customerWait.end(); ++perWait) {
      if (line->itemIds() ==
          perWait->the_cid()) { // if its the same person by user id
        waited = 1;
        string newString;
        newString = perWait->wait_items();
        pendingPrint += newString;
      }
    }
    if (waited) {
      cout << pendingPrint << endl;
      inventoryOutputFile << pendingPrint << endl; // output to file
    }
    inventoryOutputFile << "\n" << endl;
  }
  cout << "\n" << endl;
  inventoryOutputFile << "\n" << endl;
  rentalList.insert(rentalList.end(), customerWait.begin(), customerWait.end());
  list<Customer> orderCustomerList;
  for (list<Customer>::iterator perCust = rentalList.begin();
       perCust != rentalList.end(); ++perCust) {
    list<Customer>::iterator subCust = orderCustomerList.begin();
    for (; subCust != orderCustomerList.end(); ++subCust) {
      if (subCust->customer_id() > perCust->customer_id()) {
        break;
      }
    }
    orderCustomerList.insert(subCust, *perCust);
  }
  for (list<Customer>::iterator perCust = orderCustomerList.begin();
       perCust != orderCustomerList.end(); ++perCust) {
    if ((perCust->the_action() == "rent" ||
         perCust->the_action() == "return") &&
        (perCust->fullRented() >= 1 ||
         perCust->fullPending() >=
             1)) { // check to see if rentals or pending should be printed
      customerOutputFile << perCust->customer_id() << " " << perCust->the_name()
                         << endl;
      if (perCust->fullRented() >= 1) { // if the val is greater than 1
        customerOutputFile << "Rentals: " << perCust->the_cid() << " ("
                           << perCust->fullRented() << ")" << endl;
      } else if (perCust->fullPending() >=
                 1) { // else if this is greater than one
        customerOutputFile << "Pending: " << perCust->the_cid() << " ("
                           << perCust->fullPending() << ")" << endl;
      }
      customerOutputFile << "\n" << endl;
    }
  }
}