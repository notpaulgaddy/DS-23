#ifndef INVENTORY
#define INVENTORY
#include <list>
#include <iostream>
using namespace std;
class Inventory{
    public:
        Inventory(string inventoryId, int inventoryAmount, string inventoryName);
        Inventory();
        // void returnItem(Inventory& t);
        // void rentItem(const Inventory& t);
        int itemQuantity() {return itemQuant;};
        string itemIds() {return itemId;};
        string item_name() {return itemName;};
        bool setItemQuantity(int amount) { itemQuant+= amount;};
        
        // void rent_item(){};
    private:    
        int itemQuant;
        string  itemId,itemName;
};
#endif