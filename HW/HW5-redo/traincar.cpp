// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//
// =======================================================================

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "traincar.h"
#include "traincar_prototypes.h"

using namespace std;

// =======================================================================
// =======================================================================
//
//  HERE'S WHERE YOU SHOULD IMPLEMENT THE FUNCTIONS YOU PROTOTYPED IN
//  THE "traincar_prototypes.h" FILE.
//

void PushBack(TrainCar *&first, TrainCar *theNextTrain) {
  if (first == NULL) {
    first = theNextTrain;
    return;
  }
  // pointer that points to the last train
  // then null, instead null, set to next train/2nd arg
  // then pointing prev in back direction
  // set new last pointer to null
  TrainCar *newTrainCar = first;
  while (newTrainCar->next != NULL) {
    newTrainCar = newTrainCar->next;
  } // then pointer before null
  // add to end of the list
  newTrainCar->next = theNextTrain;
  // set nextTrain to point to prev end of the list
  theNextTrain->prev = newTrainCar;
}
TrainCar *PopBack(TrainCar *&first) {
  if (first == NULL) {
    return NULL;
  }
  // pointer that points to the last train
  // then null, instead null, set to next train/2nd arg
  // then pointing prev in back direction
  // set new last pointer to null
  TrainCar *newTrainCar = first;
  while (newTrainCar->next != NULL) {
    newTrainCar = newTrainCar->next;
  } // then pointer before null
  newTrainCar->prev->next = NULL;
  newTrainCar->prev = NULL;

  return newTrainCar;
}

void DeleteAllCars(TrainCar *firstVal) {
  while (firstVal != NULL) {
    // temp pointing to current location
    // set where i am to next one
    // delete temporary
    TrainCar *temp = firstVal;
    firstVal = firstVal->next;
    delete temp;
  }
}
int CalculateMaxWaitForSpeed(float speed) {
  //use formula defined on the page
  double bottom = 20 * .02f * 5280 * speed;
  double top = 3000 * 550 * 3600l;
  return top / bottom;
}
float CalculateSpeed(TrainCar *train) {
  //all the variables needed to keep track of the speeds
  float amtOfEngines, horsepower, topHalf, freightNum, anyOtherTrainType,
      finalSpeed, totalWeight;
  amtOfEngines = 0;
  horsepower = 0;
  freightNum = 0;
  anyOtherTrainType = 0;

  // loop through all traincars and add up
  while (train != NULL) {
    if (train->isEngine() == true) {//check if engine
      amtOfEngines += 1;//count number of engines
    } else if (train->isFreightCar() == true) {//check if freight
      freightNum += train->getWeight();//add the weight to total
    } else if (train->isPassengerCar() == true ||
               train->isDiningCar() == true || train->isSleepingCar() == true) {//check if passenger, dining, 
      anyOtherTrainType += 1;//add to any other type of train
    }
    train = train->next;
  }
  horsepower = amtOfEngines * 3000;
  topHalf = horsepower * 550 * 3600;
  totalWeight = (150 * amtOfEngines) + (freightNum) + (anyOtherTrainType * 50);
  finalSpeed = (topHalf / (20 * .02 * 5280 * totalWeight)) / 100;
  // (total horsepower*550*3600)/(20*2%grade*5280*total weight in tons)
  // emgome is only one with horsepower
  // 3000 hp per engine
  return finalSpeed;
}
vector<TrainCar *> ShipFreight(TrainCar *&all_engines, TrainCar *&all_freight,
                               float min_speed, int max_cars_per_train) {
  vector<TrainCar *> completedTrains;
  int loadPerEngine = CalculateMaxWaitForSpeed(min_speed);//get the min speed per engine
  int totalcars = 0;//count the number of cars
  while (all_engines != NULL && all_freight != NULL) {//loop through these
    TrainCar *freight = all_freight;//pointer to freight
    totalcars++;//increment num of cars
    all_freight = all_freight->next;
    freight->next = NULL;
    if (all_freight != NULL) {
      all_freight->prev = NULL;//set previous to null
    }
    TrainCar *engine = all_engines;//point to the engines
    all_engines = all_engines->next;
    engine->next = NULL;//set te next engine to null
    if (all_engines != NULL) {
      all_engines->prev = NULL;
    }
    int currentWeight = loadPerEngine - engine->getWeight();//get the current weight
    int currentTrains = 1;
    bool secondEngine = false;
    while (all_freight != NULL &&
           (currentWeight > all_freight->getWeight() ||
            (secondEngine == false && all_engines != NULL && currentTrains))) {
      if (currentWeight < all_freight->getWeight()) {

        engine->prev = all_engines;//update the previous enigne value
        all_engines = all_engines->next;//now update all engines
        engine->prev->next = engine;
        currentWeight -= engine->getWeight();
        currentWeight += loadPerEngine;//add to the total current weight per train
        if (all_engines != NULL) {//loop thru all the engines
          all_engines->prev = NULL;
        }
      }
      PushBack(engine, freight);//add the engine and freight to the train
      totalcars++;//add more cars
      if (CalculateSpeed(engine) < min_speed) {//check if speed is high enough
        freight = PopBack(engine);//then remove the engine
        break;//end
      }
      freight = all_freight;
      currentTrains++;
      all_freight = all_freight->next;
      freight->next = NULL;
      if (all_freight != NULL) {//loop thru all freight
        all_freight->prev = NULL;//set previous freight to null
      }
    }
    if (currentTrains > 1) {//if its not empty and has more than 1
      completedTrains.insert(completedTrains.end(), engine);
    } else {
      PushBack(all_engines, engine);
    }
  }
  return completedTrains;
  return completedTrains;

}

void TotalWeightAndCountCars(TrainCar *train, int &total_weight,
                             int &num_engines, int &num_freight_cars,
                             int &num_passenger_cars, int &num_dining_cars,
                             int &num_sleeping_cars) {
  TrainCar *currentTrain = train;
  total_weight = 0;
  num_engines = 0;
  num_freight_cars = 0;
  num_passenger_cars = 0;
  num_dining_cars = 0;
  num_sleeping_cars = 0;
  while (currentTrain != NULL) {
    total_weight += currentTrain->getWeight();
    if (currentTrain->isEngine()) {
      num_engines += 1;
    } else if (currentTrain->isDiningCar()) {
      num_dining_cars += 1;
    } else if (currentTrain->isFreightCar()) {
      num_freight_cars += 1;
    } else if (currentTrain->isPassengerCar()) {
      num_passenger_cars += 1;
    } else if (currentTrain->isSleepingCar()) {
      num_sleeping_cars += 1;
    }
    currentTrain = currentTrain->next;
  }
}

float AverageDistanceToDiningCar(TrainCar *train) {
  int numPassCars = 0;
  float totalDistance = 0.0;
  TrainCar *dining_car = train;
  while (dining_car && !dining_car->isDiningCar()) {//start from a dining car
    dining_car = dining_car->next;//go to the next car
  }
  TrainCar *current = train;//set it to current train
  while (current) {
    if (current->isPassengerCar()) {//check if its a passenger car
      numPassCars++;//increase num of passenger cars
      TrainCar *temp = current->next;
      while (temp && temp->isDiningCar()) {
        totalDistance++;
        temp = temp->next;
      }
      if (temp) {
        totalDistance++;
      } else {
        totalDistance = -1.0;
        break;
      }
    }
    current = current->next;
  }
  if (numPassCars == 0) {
    return -1.0;
  } else {
    return totalDistance / numPassCars;
  }
  // return 0;
} // got it working, showing 1.3 as avg dining dist :)

// redoing the engine function, copy pasted it, cant use vectors

int ClosestEngineToSleeperCar(TrainCar *train) {
  // do engines first, count the amount of engines, loop and add a var for each
  // engine. traverse thru it and add 1 each time it doesnt find one
  
  // while loop thru each train car and create new pointer for each train car

  // loop through  cars, make list of sleep, walk each path from sleep to
  // engine, output smallest value

  // start from front of train
  // temp pointer
  // keep counter for position
  // if its sleeper or engine
  // if either is true, start increment distance variable
  // when find the next, stop it, compare distance to last closest distance
  // if smaller, replace

  int counter = 0;
  int minimum = 250;
  TrainCar *temp = train;
  vector<TrainCar *> sleepers;
  while (temp != NULL) {

    if (temp->isSleepingCar()) {
      sleepers.insert(sleepers.end(), temp);
    }
    temp = temp->next;
  }
  int size = sleepers.size();
  for (int i = 0; i < size; i++) {
    TrainCar *left = sleepers[i]->prev;
    TrainCar *right = sleepers[i]->next;
    counter = 0;

    while (left != NULL || right != NULL) {
      counter++;
      if (left != NULL) {
        left = left->prev;
        if(left != NULL)
        {
        bool isEngine = left->isEngine();
        if (isEngine) {
          break;
        }
          }
      }
      if (right != NULL) {
        right = right->next;
        if(right != NULL)
        {
        bool isEngine = right->isEngine();
        if (isEngine) {
          { break; }
        }
          }
      }
    }
    minimum = min(minimum, counter);
  }

  return minimum;
}


void Separate(TrainCar *&train1, TrainCar *&train2, TrainCar *&train3) {
  TrainCar *engines = NULL;//set engines to null
  TrainCar *others = NULL;//other parts to null
  TrainCar *temp;//temp for each temporary item in train
  int engineCount = 0;
  int otherCount = 0;
  float speed = CalculateSpeed(train1);//get the speed of train1
  while (train1 != NULL) {//loop thru train1
    temp = train1->next;//set it to next
    train1->next = NULL;
    train1->prev = NULL;
    if (train1->isEngine()) {//check if its an engine
      PushBack(engines, train1);//then add it to the train
      engineCount++;//increment num of engines
    } else {
      PushBack(others, train1);
      otherCount++;
    }
    train1 = temp;
  }
  int train1Cap;
  int train2Cap;
  if (engineCount == 2) {//the 2 engine test case
    train2 = engines;
    train3 = engines->next;
    train1Cap = CalculateMaxWaitForSpeed(speed);//check the max speed
    train2Cap = train1Cap;//set it equal to each other
  } else {
    if (engines->next->getID() - engines->getID() <
        engines->next->next->getID() - engines->next->getID()) {//do a comparison of the ids
      train2 = engines;
      train3 = engines->next->next;//go 2 ahead
      train1Cap = CalculateMaxWaitForSpeed(speed) * 2;//multiply the max speed num by 2
      train2Cap = CalculateMaxWaitForSpeed(speed);
    } else {
      train2 = engines;
      train3 = engines->next;
      train1Cap = CalculateMaxWaitForSpeed(speed);
      train2Cap = CalculateMaxWaitForSpeed(speed) * 2;
    }
  }
  train2->next = NULL;
  train3->prev = NULL;
  while (others != NULL) {
    temp = others->next;
    others->next = NULL;
    if(CalculateSpeed(train2) < speed)//check if the speeds can match or get close enough
    {
      PushBack(train2,others);//then make train2
      if(CalculateSpeed(train2) > speed)//check if train2's speed is higher
      {
        others = PopBack(train2);
        PushBack(train3,others);
      }
      else
      {
        PushBack(train3,others);//add train3
      }
    }
    others = temp;
  }
}

void Separateold(TrainCar *&train1, TrainCar *&train2, TrainCar *&train3) {
  // train 1 is original
  // 2 and 3 are the splits
  // get length of train1
  int count = 0;
  TrainCar *temp = train1;
  while (temp != NULL) {
    if (temp->prev == NULL) {
      // START HERE
      count++;
      temp = temp->next;
    }
    int train2Length = count / 2;//whole number
    int train3Length = train2Length + (count % 2);//in case its an odd number
    train2 = train1;
    int i = 0;
    while (train1 != NULL && i < train3Length) {//loop thru train 1 and again and make train 3 have x length
      train1 = train1->next;//go to the next item
      i++;//add to the i count
    }
    if (train1 != NULL) {//if its not empty
      train3 = train1->next;//make copies from x starting point
      train1->next = NULL;//set next to null to delete as we move along
      if (train3 != NULL) {
        train3->prev = NULL;
      }
    }
    if (train2 != NULL) {
      train2->prev = NULL;
    }
  }
  train1 = NULL;
}