#include "FileIO.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveWorkouts(vector<Workout>& Workouts){
    //does objects -> file

    ofstream outfile("workouts.txt");//open file named this to start writing in, if it doesn't exist, workouts.txt creates it

    for(int i = 0; i < Workouts.size(); i++){//go through every Workout object in my Workouts vector 
        //vector looks like this Workouts:  [0] Chest   [1] Back

        //for first iteration of [0]
        outfile << Workouts[i].name << endl;//Writes Chest into file
        //outfile << operator means send this information into the file
        //exactly like the cout << "Hello"; -> means send this to the screen

        outfile << Workouts[i].date.month << endl;//writes month into file
        outfile << Workouts[i].date.day << endl;//writes day into file
        outfile << Workouts[i].date.year << endl;//writes year into file


        for(int j = 0; j < Workouts[i].Exercises.size(); j++){//go through every exercise inside this workout
            //lets say our it was our exercise Bench Press for example

            outfile << Workouts[i].Exercises[j].name << endl;//writes Bench Press into file
            outfile << Workouts[i].Exercises[j].weight << endl;
            outfile << Workouts[i].Exercises[j].reps << endl;
            outfile << Workouts[i].Exercises[j].sets << endl;

        }

        outfile << "END" << endl;//writes END because later when loading, we need to know where to stop reading exercises to avoid reading from a new workout

    }

    outfile.close();//closes file 

}

void loadWorkouts(vector<Workout>& Workouts){
    ifstream infile("workouts.txt");
    if (!infile.is_open()){
        return;
    }

    string line;
    while (getline(infile, line)){      // workout name (whole line)
        if (line.empty()) continue;     // skip stray blank lines

        Workout Workout1;               // fresh workout every time (fixes bug 2)
        Workout1.name = line;

        getline(infile, Workout1.date.month);
        getline(infile, Workout1.date.day);
        getline(infile, Workout1.date.year);

        string check;
        while (getline(infile, check) && check != "END"){
            Exercise Exercise1;
            Exercise1.name = check;     // whole line, so "Bench Press" works
            getline(infile, Exercise1.weight);
            getline(infile, Exercise1.reps);
            getline(infile, Exercise1.sets);
            Workout1.Exercises.push_back(Exercise1);
        }

        Workouts.push_back(Workout1);
    }

    infile.close();
}