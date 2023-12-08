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
#ifndef train_prots
#define train_prots

#include <vector>
using namespace std;

class TrainPrototypes{
    public:
        void PushBack(TrainCar* simple, TrainCar* func());
        float CalculateSpeed(TrainCar* train) {return theTrainSpeed;}; 
        float AverageDistanceToDiningCar(TrainCar* train) {return avgDistanceToDining;};
        vector<TrainCar*> ShipFreight(TrainCar* all_engines, vector<string> all_freight, float min_speed, int max_cars_per_train) {return trainDataVec;};
        //int TotalWeightAndCountCars() const {};

    private:
        float theTrainSpeed,avgDistanceToDining;
        vector<TrainCar*> trainDataVec;
};
#endif