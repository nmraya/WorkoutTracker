#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include "Workout.h"//need to include this as we use Workout class in our functions

using namespace std;

void saveWorkouts(vector<Workout>& Workouts);
void loadWorkouts(vector<Workout>& Workouts);

#endif