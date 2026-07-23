#ifndef WORKOUTFUNCTIONS_H
#define WORKOUTFUNCTIONS_H
#include <vector>
#include "Workout.h"//need file that has has our Workout class 

void addWorkout(vector<Workout> &Workouts);
void addExercises(Workout &currentWorkout);
void removeExercises(Workout &currentWorkout);
void adjustExercises(Workout &currentWorkout);
int workoutVerification(vector<Workout> &Workouts);
void continueWorkout(vector<Workout> &Workouts);
void removeWorkout(vector<Workout> &Workouts);
void viewWorkout(vector<Workout> &Workouts);

#endif