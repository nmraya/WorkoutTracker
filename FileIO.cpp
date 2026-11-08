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
    //does file -> objects 

    ifstream infile("workouts.txt");//opens workouts.txt to read from it 
    //ifstream means input file while ofstream means output file 

    if (!infile.is_open()){//did the file actually open? if not return bc theres nothing to load
        return;
    }
    Workout Workout1;//creates one temporary Workout object 

    while(infile >> Workout1.name){// read next workout name, did it work? if yes keep going, if no stop
        //suppose first thing in file is Chest
        //Workout1.name = "Chest"
        

        // load workout information

        infile >> Workout1.date.month;
        infile >> Workout1.date.day;
        infile >> Workout1.date.year;


        string check;//used to see what comes next 

        // load exercises until END
        while(infile >> check && check != "END"){//infile >> check -> reads the next word, suppose the file says Bench, check = "Bench"
            //then for check != "END" -> is this word END? -> if not keep loading exercises till we reach END

            Exercise Exercise1;//create an exercise, looks like 
            //name = ""
            //weight = ""
            //reps = ""
            //sets = ""

            
            Exercise1.name = check;//remember check already was the name of the exercise so just set it to this 

            infile >> Exercise1.weight; //weight = 135
            infile >> Exercise1.reps; //reps = 8
            infile >> Exercise1.sets; //sets = 3


            Workout1.Exercises.push_back(Exercise1);//add exercise to workout
        }


        // after workout is fully built, add it to vector
        Workouts.push_back(Workout1);

    }
    //then go to next workout 


    infile.close();

}