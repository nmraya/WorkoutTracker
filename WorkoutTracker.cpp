#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Exercise{
    public:
        string name;
        double weight;
        int reps;
        int sets;
};

class Workout{
    //need to make public or else by default it is set to private
    public:
        string name;
        string date;
        vector<Exercise> Exercises;

};

//either allow user to enter date like 21st, or have it be weekly, should i have it so they can go back and see any workout theyve done if so i need to make it bigger than weekly
//most likely need like months, days, years etc, also need to make it so for continue existing workout, should the user also instead of just being able to add exericses they can
//also remove or adjust exercises like reps, sets, etc, 


void addWorkout(vector<Workout> &Workouts){//this takes in vector of Workout objects and the vector is named Workouts
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

void addExercises(Workout &currentWorkout){ //this is expecting to receive the currentWorkout (aka workout we want to add an exercise to) when it is called 
    //what kind of thing is currentWorkout? - every variable needs a type for example int number; int is the type, or string name; string is the type
    //in this case - Workout &currentWorkout; Workout is the type, 
    //think about other function that have vector<Workout> &Workouts instead right, this meant the function was receiving the entire vector of workouts
    //now for this function we just want the function to receive the one workout object 

    //Workout is our class/type, 
    //currentWorkout is our object being passed by reference
    //passing by reference means this function works with the original Workout NOT the copy so exercises will stay in that Workout after function finishes
    bool addExercisesloop = false;
    string userOption;

    while(addExercisesloop == false){

        Exercise Exercise1;

        cout << "Please enter exercise name: ";
        getline(cin >> ws, Exercise1.name);

        cout << "Please enter weight: ";
        cin >> Exercise1.weight;
        cout << "Please enter reps: ";
        cin >> Exercise1.reps;
        cout << "Please enter sets: ";
        cin >> Exercise1.sets;




        currentWorkout.Exercises.push_back(Exercise1);
        //this pushes back all exercise data dont need to separate .reps, .sets, etc look at addWorkout above to confirm its same 
        //but what is currentWorkout? - remember our Workout object has three members - name, date, and exercises - so imagine we have 
        //Workout currentWorkout;
        //in memory its like this - name = "Push", date = "Monday", exercises = empty vector 
        //so when we write currentWorkout.exercises we are saying - give me the exercises vector that belongs to this workout 

        //currentWorkout is the correct workout that we want to modify, then .Exercises accesses that workout's exercise vector, then push_back(Exercise1) 
        //copies the entire Exercise1 object into that vector
        //and then Exercise1 is just essentially 1 exercise that is getting copied 

        //so theres a bug whenever i type a space it fucks up the program

        cout << "Add another exercise? (y/n): ";
        cin >> userOption;
        if(userOption == "y"){
            addExercisesloop = false;
        }
        else{
            addExercisesloop = true;
        }
    }

}


void continueWorkout(vector<Workout> &Workouts){//the parameters is what the function EXPECTS to receive when it is called !!!! 
    //we need vector<Workout> &Workouts because we need the access our entire Workouts vector of Workout objects to see which Workout object the user wants to add exercises to

    //Workouts is the name of our vector
    //we need to now replace everything in here to check and see if it matches with
    //the different objects aka correct workout name and date 
    string continuedWorkoutname;
    string continuedWorkoutdate;
    bool matchingWorkout = false;
    bool validDate = false;
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
            cout << " " << Workouts[i].date;
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
                while(validDate == false){
                    cout << "Type workout date to continue: ";
                    cin >> continuedWorkoutdate;
                    if(continuedWorkoutdate == Workouts[i].date){
                        //now here we genuinely have found the specific workout the user wants to access, so now we can use out add exercises that workout


                        cout << "Accessing workout " << Workouts[i].name << Workouts[i].date << endl;
                        //up to here everything runs fine its just here here that fucks up -----------------------------

                        addExercises(Workouts[i]);
                        //we are passing the current workout that we found in this function into our addExercises function
                        //this is not a vector, this is Workouts[i] which is the current workout we are on which reads add an exercise to the current workout we are on


       

                        
                        
                        //we are currently giving this shit the entire vector, we should only be giving it the ONE workout we found
                        //Workouts[i] is not a position of a vector, [i] is the position of the vector, so workouts[i] is the the entire workout object being stored at that index
                        //


                        //so workouts[i] is rather         string name;   string date;   vector<Exercise> Exercises;   rather than a position at a vector 
                        //the [i] is the position at a vector, but workouts[i] is the specific object which has the date, name, and vector exercises inside at that position 


                        matchingWorkout = true;
                        validDate = true; 
                    }
                if (validDate == false){
                    cout << "Please enter valid date" << endl;
                }


                }

            }
        }

        if (matchingWorkout == false){
            cout << "Please enter valid workout" << endl;
            //if no match was found, matchingWorkout stays = false and then we go
            //to top of while loop again and repeat until we find a match
        }
        
    }

    //matchingWorkout = false;

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
        //want to make sure the workout name is valid before checking date
        for (int i = 0; i < Workouts.size(); i++){
            //loops through entire vector
            if (removedWorkoutname == Workouts[i].name){
                //this means we have fully looped through vector and found a match with our user input and workout name in our vector

                bool validDate = false;
                //now that workout name is checked to be valid, check if date valid
                //also add in while loop later to keep checking if you dont want return to top
                while(validDate == false){
                    cout << "Type workout date to remove: ";
                    cin >> removedWorkoutdate;
                    if(removedWorkoutdate == Workouts[i].date){
                        Workouts.erase(Workouts.begin() + i);
                        matchingWorkout = true;
                        validDate = true; 
                    } 
                    //same thing here, we need an if statement or else it will run through and print this out even if date is fine
                    if (validDate == false){
                        cout << "Invalid date, please try again" << endl;
                    }

                }

            }
        }
        //need an if statement because if we didnt have it, while loop still runs this after it doesnt auto pop out of while loop after we set condition = true, it finishes
        //running everything inside first then pops out 
        if (matchingWorkout == false){
            cout << "Invalid workout name, please retry " << endl;
        }
 

    }


    if (matchingWorkout == false){
            cout << "Please enter valid workout" << endl;
            //if no match was found, matchingWorkout stays = false and then we go
            //to top of while loop again and repeat until we find a match
    }


    cout << "----------" << endl;

}

void viewWorkout(vector<Workout> &Workouts){
    bool validWorkout;
    string workoutName;
    cout << "Workouts: ";
    for (int i = 0; i < Workouts.size(); i++){
        if (i == 0){
           cout << Workouts[i].name << " - ";
            cout << Workouts[i].date;
            //need to separate i and j because we cannot use them for the same or else it will miss certain indexes 
            

        }
        else{
           cout << ", " << Workouts[i].name;
            cout << " - " << Workouts[i].date;

            
        }
    }
    cout << endl;

    //while()

    cout << "Enter workout name to view: ";
    cin >> workoutName;

    cout << "----------" << endl;
    //we need to check to see if user entered workoutname is valid

    for (int i = 0; i < Workouts.size(); i++){//goes through entire workouts vector 
        if(workoutName == Workouts[i].name){//if our workout name matches a workout from our workouts vector, continue
            //now we know the name of the workout 
                for (int j = 0; j < Workouts[i].Exercises.size(); j++){//now from that specific workout we matched with go through its exercises and print each data piece out
                    //at first you had it like 
                    //cout << Workouts[i].name; etc
                    cout << "Exercise: " << Workouts[i].Exercises[j].name << endl;
                    cout << "Weight: " << Workouts[i].Exercises[j].weight << endl;
                    cout << "Reps: " << Workouts[i].Exercises[j].reps << endl;
                    cout << "Sets: " << Workouts[i].Exercises[j].sets << endl;
                }

        }
        else{

        }

    }

    
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
            //addExercises(Workouts);
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