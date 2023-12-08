// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//
// =======================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "traincar.h"
#include "traincar_prototypes.h"

// =======================================================================
// =======================================================================
//
//  HERE'S WHERE YOU SHOULD IMPLEMENT THE FUNCTIONS YOU PROTOTYPED IN
//  THE "traincar_prototypes.h" FILE.
//

float TrainPrototypes::CalculateSpeed(TrainCar* train)  {//train is each train car
    int amtOfEngines,horsepower,topHalf,freightNum,anyOtherTrainType;
    float finalSpeed,totalWeight;
    if(train->isEngine() == true){
        amtOfEngines+=1;
    }
    else if(train->isFreightCar() == true){
        freightNum+=1;
    }else if(train->isPassengerCar()==true || train->isDiningCar()==true || train->isSleepingCar()==true){
        anyOtherTrainType+=1;
    }
    horsepower = amtOfEngines*3000;
    topHalf = horsepower*550*3600;
    totalWeight = (150*amtOfEngines)+(freightNum*(train->getWeight()))+(anyOtherTrainType*50);
    finalSpeed = topHalf/(20*.02*5280*totalWeight);
    // (total horsepower*550*3600)/(20*2%grade*5280*total weight in tons)
    //emgome is only one with horsepower
    //3000 hp per engine
    return finalSpeed;
}
float TrainPrototypes::AverageDistanceToDiningCar(TrainCar* train){//points to each value before and after
    int rightCount,leftCount;
    float avgDistance;
    if(train->next!=NULL && train->prev!=NULL){//if not the first or last
        if(train->isDiningCar()==true){//go to the dining car
            //start the count and go to the right side
            if(train->next->isPassengerCar()==true){
                if(train->next->isFreightCar()==false || train->next->isEngine()==false){
                    rightCount++;
                }else{
                    //do nothing
                }
            }
            else if(train->prev->isPassengerCar()==true){
                if(train->prev->isFreightCar()==false || train->prev->isEngine()==false){
                    leftCount++;
                }else{
                    //do nothing
                }
            }   
        }
    }
    avgDistance = (rightCount+leftCount)/((rightCount+leftCount)/2);
    return avgDistance;
}//fix the formula for this

vector<TrainCar*> TrainPrototypes::ShipFreight(TrainCar* all_engines, vector<string> all_freight, float min_speed, int max_cars_per_train){
    vector<TrainCar*> completedTrains;
    //organize the train cars by heaviest weight to lowest weight
    // vector<int> sortedWeights;
    // std::size_t pos{};
    // //&pos
    // for(int i=0;i<all_freight.size();i++){
    //     sortedWeights.push_back(std::stoi(all_freight[i],&pos));
    // }
    // sort(sortedWeights.begin(),sortedWeights.end(),greater<int>());//sort in descending order
    // int amtOfEngines = sizeof(all_engines)/sizeof(all_engines[0]);
    // int minimumTrains = amtOfEngines/max_cars_per_train+(amtOfEngines%max_cars_per_train>0?1:0);//ternary 
    // while(all_engines!=NULL && sortedWeights!=NULL){
    //     int weight = sortedWeights[0];
    //     sortedWeights.erase(sortedWeights.begin());
    //     for(int i=0;i<completedTrains.size();i++){
    //         if(CalculateSpeed(completedTrains[i])>min_speed){//>= might fail tests
    //             PushBack(completedTrains[i],TrainCar::MakeFreightCar(weight));
    //             if(CalculateSpeed(completedTrains[i])>=min_speed){
    //                 break;
    //             }else{
    //                 completedTrains[i].pop_back();
    //             }
    //         }
    //     }
    // }
    vector<TrainCar*> newTrain;
    if(newTrain==NULL){//if the vector is null
        //put the engines at the front
        newTrain.insert(newTrain.begin(),all_engines);
    }else{//if already has a head
        newTrain.insert(newTrain.begin()+1,all_freight);
    }
    for(int i=0;i<newTrain.size();i++){
        if(newTrain.size()<=max_cars_per_train && CalculateSpeed(TrainCar* newTrain[i])>=min_speed){
        completedTrains.insert(completedTrains.begin(),newTrain.begin(),newTrain.end());//add the vector to the completed train vector
        }
    }
    //return the smallest vector
}