#include <iostream>
#include "Inventory.h"

#include <string>
using namespace std;

Inventory::Inventory(string inventoryId, int inventoryAmount, string inventoryName){//data being taken in
    itemId = inventoryId;
    itemQuant = inventoryAmount;
    itemName = inventoryName;
}
Inventory::Inventory(){
}