#ifndef INVENTORY
#define INVENTORY
#include <list>
#include <iostream>
using namespace std;
class Inventory{
    public:
        Inventory(string inventoryId, int inventoryAmount, string inventoryName);
        Inventory();

        int itemQuantity() {return itemQuant;};//get the num of items
        string itemIds() {return itemId;};//grab the item id
        string item_name() {return itemName;};//grab the item name

        void rent_item(int num_to_rent) {
            itemQuant-=num_to_rent;
        };//decrease the amount if rented
        void return_item(int num_to_return){
            itemQuant+=num_to_return;
        }//increase the amount if rented
    private:    
        int itemQuant;
        string  itemId,itemName;
};
#endif