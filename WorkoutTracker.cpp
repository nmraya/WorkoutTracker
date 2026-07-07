#include <iostream>
#include <string>
#include <vector>
using namespace std;

void addWorkout(vector<string> &Workouts){
    string Workout;
    cout << "Please enter workout to add: ";
    cin >> Workout;
    Workouts.push_back(Workout);
    cout << "----------" << endl;
}

void continueWorkout(vector<string> &Workouts){

}

void removeWorkout(vector<string> &Workouts){
    string removedWorkout;
    cout << "Workouts: ";
    for (int i = 0; i < Workouts.size(); i++){
        if (i == 0){
            cout << Workouts[i];
        }
        else{
            cout << ", " << Workouts[i];
        }
    }
    cout << endl;
    cout << "Type workout to remove: ";
    cin >> removedWorkout;
    //maybe we can go by position in vector, for ex i = 0, i = 1, user enters #
    // of position they want to remvoe
    for (int i = 0; i < Workouts.size(); i++){
        //go through each element in vector
        if (removedWorkout == Workouts[i]){
            //if removedWorkout matches with Workouts[i]
            Workouts.erase(Workouts.begin() + i);
            // erase item at vector position i 
        }
    }

    cout << "----------" << endl;

}

void viewWorkout(vector<string> &Workouts){
    cout << "Workouts: ";
    for (int i = 0; i < Workouts.size(); i++){
        if (i == 0){
            cout << Workouts[i];
        }
        else{
            cout << ", " << Workouts[i];
        }
    }
    cout << endl;
    cout << "----------" << endl;
}



int main(){

    string menuInput;
    bool validNumber = false;
    vector<string> Workouts;



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
        }
        else if (menuInput == "2"){
            cout << "Continuing Existing Workout" << endl;
            //allow vector to be printed out and let user see which they want to pick
        }
        else if (menuInput == "3"){
            cout << "Removing Workout" << endl;
            //print vector and let user type which they want removed
            removeWorkout(Workouts);
        }
        else if (menuInput == "4"){
            cout << "Viewing Previous Workout" << endl;
            //same as input 2
            viewWorkout(Workouts);
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