#ifndef CUSTOMER
#define CUSTOMER
#include <list>
#include <iostream>

using namespace std;

class Customer{
    public:
        Customer(string customerId, string action, int timestamp, int theQuantity, string customerInventoryId, string name);
        Customer();

       string customer_id() {return custId;};
       string the_action() {return theaction;};
       int the_timestamp() {return thetimestamp;};
       int action_quantity() {return theactionquantity;};
       string the_cid() {return thecustomerInventoryId;};
       string the_name() {return thename;};

    //    void itemRental(Customer& c) {};
    private:
        string custId, theaction, thecustomerInventoryId, thename;
        int thetimestamp, theactionquantity;
};
#endif