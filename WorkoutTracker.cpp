#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Workout{
    //need to make public or else by default it is set to private
    public:
        string name;
        string date;
};

class Exercises{
    public:
        string name;
        double weight;
        int reps;
        int sets;
};

void addWorkout(vector<Workout> &Workouts){
    //Workouts is the name of the vector
    //Workouts vector stores objects of type Workout which consists of a name and a date
    //need to essentially do
    // Workout Workout1;   --> this is the main thing we need to figure out
    //Workout1.name = push
    //Workout1.date = monday
    //well no this shit is just temporary so literally just create it here and it can fuck off after function ends
    Workout Workout1;
    cout << "Please enter workout name to add: ";
    cin >> Workout1.name;
     cout << "Please enter workout date to add: ";
    cin >> Workout1.date;
    //now after doing Workout1.name & Workout1.date we temporarily are storing those
    //Workout1
    //------------
    //name = Push
    //date = Monday
    //into the Workout1 object, but then we push it back onto Workouts below
    cout << endl;
    Workouts.push_back(Workout1);
    //this above will push whole workout into the vector which looks now like this
    //index 0
    //------------
    //name = Push
    //date = Monday
    //now we are able to push the Workout class objects in this case which are
    //then name and date 

    cout << "----------" << endl;
}

void continueWorkout(vector<Workout> &Workouts){
    //Workouts is the name of our vector
    //we need to now replace everything in here to check and see if it matches with
    //the different objects aka correct workout name and date 
    string continuedWorkoutname;
    bool matchingWorkout = false;
    cout << "Workouts: ";
    for (int i = 0; i < Workouts.size(); i++){//loop through size of vector
        if (i == 0){
            //cout << Workouts[i];
            //remember though the temp Workout Workout1 object is gone but we pushed
            //the copy into the vector so we still have that 
            cout << Workouts[i].name;
            cout << Workouts[i].date;
        }
        else{
            cout << ", " << Workouts[i].name;
            cout << ", " << Workouts[i].date;
        }
    }
    //this will print out the elements in our vector

    
    cout << endl;

    while (matchingWorkout == false){
        cout << "Type workout to continue: ";
        cin >> continuedWorkoutname;
        for (int i = 0; i < Workouts.size(); i++){
        //go through each element in vector
            if (continuedWorkoutname == Workouts[i].name){
                //if removedWorkout matches with Workouts[i]
                cout << "Accessing workout " << Workouts[i].name << endl;
                // erase item at vector position i
                matchingWorkout = true; 
                //matchingWorkout = true, so when we check next if statement
                //it skips it
            }
        }
        if (matchingWorkout == false){
            cout << "Please enter valid workout" << endl;
            //if no match was found, matchingWorkout stays = false and then we go
            //to top of while loop again and repeat until we find a match
        }
        
    }


    cout << "----------" << endl;

}

void removeWorkout(vector<Workout> &Workouts){
    string removedWorkoutname;
    string removedWorkoutdate;
    bool matchingWorkout = false;
    //NOT bool matchingWorkout false; must set = false
    cout << "Workouts: ";
    for (int i = 0; i < Workouts.size(); i++){
        if (i == 0){
            cout << Workouts[i].name;//must use Workouts[i].name or .date etc, can no longer just do Workouts[i]
            cout << Workouts[i].date;
        }
        else{
            cout << ", " << Workouts[i].name;
            cout << " " << Workouts[i].date;
        }
    }
    cout << endl;
    //this prints out each workout name and date at each position in our vector 
    
    while (matchingWorkout == false){
        cout << "Type workout to remove: ";
        cin >> removedWorkoutname;
        cout << "Type workout date to remove: ";
        cin >> removedWorkoutdate;
        for (int i = 0; i < Workouts.size(); i++){
        //go through each element in vector
            if (removedWorkoutname == Workouts[i].name){ //need to account also for date this only checks if workout name matched need to check if date matches too
                if(removedWorkoutdate == Workouts[i].date){
                    Workouts.erase(Workouts.begin() + i);//why do we not need to erase the .name & .date why can we just remove the workout as posiition i?
                    //is it because the name and date are both stored at the index i so we just need to remove that specific index
                    //if thats the case why cant we just check if removedWorkoutname == Workouts[i] why do we need Workouts[i].name
                    //the reason we can do the erase is because its erasing both the objects stored at that position i so its fine
                    //but however we cant compare removedWorkoutdate and Workouts[i] because of types, removedWorkoutname is a string and 
                    //Workouts[i] is the objectso we cant compare those two its like trying to compare a string == Workout object, so we need to get more specific
                    //which is like string == string 
                    //Workouts[i] is one specific Workout object stored at index i
                    //Workouts is the vector that stores many Workout objects
                    //Workout is the class/type
                    
                    matchingWorkout = true; 
                }
                
            }
        }
        if (matchingWorkout == false){
            cout << "Please enter valid workout" << endl;
            //if no match was found, matchingWorkout stays = false and then we go
            //to top of while loop again and repeat until we find a match
        }

        
    }


    cout << "----------" << endl;

}

void viewWorkout(vector<Workout> &Workouts){
    cout << "Workouts: ";
    for (int i = 0; i < Workouts.size(); i++){
        if (i == 0){
            cout << Workouts[i].name;
            cout << Workouts[i].date;
        }
        else{
            cout << ", " << Workouts[i].name;
            cout << " " << Workouts[i].date;
        }
    }
    cout << endl;
    cout << "----------" << endl;
}



int main(){

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
        }
        else if (menuInput == "2"){
            cout << "Continuing Existing Workout" << endl;
            //allow vector to be printed out and let user see which they want to pick
            if (Workouts.empty()){
                cout << "Workout list is empty" << endl;
            }
            else{
                continueWorkout(Workouts);
            }
        }
        else if (menuInput == "3"){
            cout << "Removing Workout" << endl;
            if (Workouts.empty()){
                cout << "Workout list is empty" << endl;
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