#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <list>
#include "customer.h"
using namespace std;

int main(int argc, char *argv[]){
    ifstream inventoryInputFile(argv[1]);
    ifstream customerInputFile(argv[2]);
    string inventoryOutputFile = argv[3];
    string customerOutputFile = argv[4];
    if (!inventoryInputFile.good() || !customerInputFile.good()) {
        std::cerr << "Can't open " << argv[3] << " to read.\n";
        exit(1);
    }
    char c;
    string line;
    list<string> inventoryLines;
    list<string> customerLines;
    while(getline(inventoryInputFile,line)){
        inventoryLines.push_back(line);
    }
    inventoryInputFile.close();
    int inventNumCount = 0;
    for (const string& l : inventoryLines) {
        for(int i=1;i<=4;i++){
            if(!isdigit(l[i])){
                inventNumCount++;
            }
        }
        if(l[0] != 'T' || l[6]<1 || inventNumCount>0){
            cerr << "Invalid inventory ID" << l.substr(1,4) << "found in the inventory file." << endl;
        }
    }


    string customer_id, action, timestamp, quantity, item_id, name;
    int custoNumCount = 0;
    int custoNumCountStamp = 0;
    int custoINumCountId = 0;
    while(!customerInputFile.eof()){
        customerInputFile >> customer_id >> action >> timestamp >> quantity >> item_id >> name;
        if(customer_id[0]=='C' && (action=="rent" || action=="return") && stoi(quantity)>=1 && item_id[0]=='T'){
            for(int i=1;i<=4;i++){
                if(!isdigit(customer_id[i])){
                    custoNumCount++;
                }
                if(!isdigit(item_id[i])){
                    custoINumCountId++;
                }
            }
            for(int i=0;i<=4;i++){
                if(!isdigit(timestamp[i])){
                    custoNumCountStamp++;
                }
            }
        }
    if(custoNumCount>4 && custoINumCountId<4 && custoNumCountStamp<4){
        cerr << "Invalid customer information found for ID " << customer_id << "in the customer file." << endl;
    }
    }
    customerInputFile.close();
    return 0;
}