#include "customer.h"
#include "inventory.h"
#include <iostream>

using namespace std;

Customer::Customer(string customerId, string action, int timestamp, int customerInventoryQuantity, string customerInventoryId, string name){
    custId = customerId;
    theaction = action;
    thetimestamp = timestamp;
    theactionquantity = customerInventoryQuantity;
    thecustomerInventoryId = customerInventoryId;
    thename = name;
}
Customer::Customer(){
    
}
