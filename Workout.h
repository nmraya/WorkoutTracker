#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>
#include <vector>
#include "Exercise.h"
#include "Date.h"

using namespace std;

class Workout{
    public:
        string name;
        Date date;
        vector<Exercise> Exercises;
        //include Exercise.h and Date.h as we need those files for our Workout class
};


#endif