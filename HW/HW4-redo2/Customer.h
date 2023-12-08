#ifndef CUSTOMER
#define CUSTOMER
#include <iostream>
#include <list>

using namespace std;
//all epxlained in the custoemr cpp
class Customer {
public:
  Customer(string customerId, string action, int timestamp,
           int customerInventoryQuantity, string customerInventoryId,
           string name, int rentedNum, int pendingNum);
  Customer();

  string customer_id() { return custId; };
  string the_action() { return theaction; };
  int the_timestamp() { return thetimestamp; };
  int action_quantity() { return theactionquantity; };
  string the_cid() { return thecustomerInventoryId; };
  string the_name() { return thename; };
  string print_items();
  string wait_items();
  void numRented_items(int amtRented) { therentednum += amtRented; }
  void numPending_items(int amtPending) { thependingNum += amtPending; }
  int fullRented() { return therentednum; };
  int fullPending() { return thependingNum; };
  bool operator==(Customer &C);

private:
  string custId, theaction, thecustomerInventoryId, thename;
  int thetimestamp, theactionquantity, theAmtRented, therentednum,
      thependingNum;
};
#endif
