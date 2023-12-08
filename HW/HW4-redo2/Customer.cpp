#include "Customer.h"
#include <iostream>

using namespace std;
Customer::Customer(string customerId, string action, int timestamp,
                   int customerInventoryQuantity, string customerInventoryId,
                   string name, int rentedNum, int pendingNum) {
  custId = customerId;//the customer id
  theaction = action;//rental/return
  thetimestamp = timestamp;//timestamp
  theactionquantity = customerInventoryQuantity;
  thecustomerInventoryId = customerInventoryId;
  thename = name;
  therentednum = rentedNum;//amt of successful rentals
  thependingNum = pendingNum;//same but for pending 
}
Customer::Customer() {}

string Customer::print_items() {//priunt the items in the correct format
  string str =
      "" + custId + " " + thename + " (" + to_string(theactionquantity) + ") ";//append these strings
  return str;
}

string Customer::wait_items() {//output the data for the wait list
  string str =
      "" + custId + " " + thename + " (" + to_string(theactionquantity) + ") ";
  return str;
}

bool Customer::operator==(Customer &C) {//check to make sure the types are the same, fixed bug with rental list
  bool one = custId.compare(C.customer_id()) == 0;
  bool five = thecustomerInventoryId.compare(C.the_cid()) == 0;
  bool six = thename.compare(C.the_name()) == 0;

  if (one && five && six)
    return true;
  return false;
}