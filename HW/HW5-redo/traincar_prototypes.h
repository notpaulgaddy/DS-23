// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//                 This file is #include'd from traincar.h and main.cpp
//
// =======================================================================
//
// There are a number of additional functions used in main.cpp that
// you need to declare and implement.  Study main.cpp and the provided
// output to determine the arguments, return type, and overall
// behavior.
//
// Add all required additional function prototypes here
// (you may also add your own helper function prototypes here too)
//
// Implement these functions in "traincar.cpp"
//
#include "traincar.h"
#include <string>
#include <vector>
using namespace std;
void PushBack(TrainCar *&first, TrainCar *theNextTrain);//function to add the trains
TrainCar *PopBack(TrainCar *&first);//function to delete the trains
void DeleteAllCars(TrainCar *nullVal);//function to delete the cars
float CalculateSpeed(TrainCar *train);//function to find the speed
void TotalWeightAndCountCars(TrainCar *train, int &total_weight,
                             int &num_engines, int &num_freight_cars,
                             int &num_passenger_cars, int &num_dining_cars,
                             int &num_sleeping_cars);//function to count all the numerical data

vector<TrainCar *> ShipFreight(TrainCar *&all_engines, TrainCar *&all_freight,
                               float min_speed, int max_cars_per_train);//ship freight function
float AverageDistanceToDiningCar(TrainCar *train);//avg distance to dining car
int ClosestEngineToSleeperCar(TrainCar *train);//function to find the engine closest to the sleeping cars
void Separate(TrainCar *&train1, TrainCar *&train2, TrainCar *&train3);//function to seperate each train