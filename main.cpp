#include <iostream>
#include <vector>
#include "Workout.h"//need file that has Workout class
#include "WorkoutFunctions.h"//need the file to call these functions
using namespace std;

int main(){
    //need Workout.h as we use Workout class here in main, we do not use Exercise or Date class here though so we do not include those

    string menuInput;
    bool validNumber = false;
    
    vector<Workout> Workouts;
    //this is a vector of classes named Workouts

    while (validNumber == false){
        cout << "Welcome to Raya Fitness Tracker" << endl;
        cout << "1. Add Workout" << endl;
        cout << "2. Continue Existing Workout" << endl;
        cout << "3. Remove Workout" << endl;
        cout << "4. View Previous Workout" << endl;
        cout << "5. Exit" << endl;
        cout << "Please Enter Number: ";
        cin >> menuInput;
        cout << "----------" << endl;

        if (menuInput == "1"){
            cout << "Adding Workout" << endl;
            //add to a vector each time, basic maybe only legs, upper, push, pull, etc
            addWorkout(Workouts);
            //addExercises(Workouts);
        }
        else if (menuInput == "2"){
            cout << "Continuing Existing Workout" << endl;
            
            //allow vector to be printed out and let user see which they want to pick
            if (Workouts.empty()){
                cout << "Workout list is empty" << endl;
                cout << "----------" << endl;
            }
            else{
                continueWorkout(Workouts);
            }
        }
        else if (menuInput == "3"){
            cout << "Removing Workout" << endl;
            if (Workouts.empty()){
                cout << "Workout list is empty" << endl;
                cout << "----------" << endl;
                //could either do return 0, break, or change bool
                //i think break would work best as it breaks out of current statement
            }
            else{
                removeWorkout(Workouts);
            }
            //print vector and let user type which they want removed
        }
        else if (menuInput == "4"){
            cout << "Viewing Previous Workout" << endl;
            //same as input 2{

            
            
            if (Workouts.empty()){
                cout << "Workout list is empty" << endl;
                cout << "----------" << endl;
            }
            else{
                viewWorkout(Workouts);
            }
        }
        else if (menuInput == "5"){
            validNumber = true;
        }
        else{
            cout << "Please Enter Again" << endl;
        }
    }






    return 0;
}

