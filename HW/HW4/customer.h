#ifndef CUSTOMER
#define CUSTOMER
#include <list>
#include <iostream>
using namespace std;
class Customer{
    public:
        string customer_id, action, timestamp, quantity, item_id,name;
        Customer(string customer_id, string action, string timestamp, string quantity,
            string item_id, string name) : customer_id(customer_id), action(action),
            timestamp(timestamp),quantity(quantity), item_id(item_id), name(name){
                
            }
};
#endif