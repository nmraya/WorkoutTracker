#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Exercise{
    public:
        string name;
        string weight;
        string reps;
        string sets;
};

class Date{
    public:
        string day;
        string month;
        string year;
};

class Workout{
    //need to make public or else by default it is set to private
    public:
        string name;
        //string date;//think about this now, we probably want a class Date to hold day, month, year so how do we implement that
        //also should we in here in this class have vector<Date> Dates or Date date; whats the difference between each one?
        //vector<Date> Dates holds a bunch of Dates , think about the exercises vector we have right below, its like that, it holds a bunch of exercises for a workout object
        //all we need however is one date for a workout object, so we just need Date date;
        Date date;//Date is the type like string or int, and date is the object 
        vector<Exercise> Exercises;

};




void addWorkout(vector<Workout> &Workouts){//this takes in vector of Workout objects and the vector is named Workouts
    //Workouts is the name of the vector
    //Workouts vector stores objects of type Workout which consists of a name and a date
    //need to essentially do
    // Workout Workout1;   --> this is the main thing we need to figure out
    //Workout1.name = push
    bool validWorkout = false;
    bool validWorkoutname = false;
    

    //Workout1.date = monday
    //well no this shit is just temporary so literally just create it here and it can fuck off after function ends

    Date Date1;

    Workout Workout1;

    while(validWorkout == false){
            if (Workouts.empty()){
                cout << "Please enter workout name to add: ";
                cin >> Workout1.name;
                cout << "Please enter workout month to add: ";
                cin >> Date1.month;
                cout << "Please enter workout day to add: ";
                cin >> Date1.day;
                cout << "Please enter workout year to add: ";
                cin >> Date1.year;
                validWorkout = true;
            }
            else{
                        while(validWorkoutname == false){
                            cout << "Please enter workout name to add: ";
                            cin >> Workout1.name;
                            bool foundDupe = false;

                            for(int i = 0; i < Workouts.size(); i++){
                                //we need to search through ENTIRE vector to see if we get a match
                                //only use this shit to search, if you try to put ur logic in here it just gets confused because if u put an else after the if,
                                //its basically telling it ok after the first element, go to else where we need to go through WHOLE thing
                                
                                if(Workout1.name == Workouts[i].name){
                                    foundDupe = true;
                                }
                                
                            }
                            if(foundDupe == true){
                                cout << "Error already used name" << endl;
                            }
                            if(foundDupe == false){
                                 cout << "Please enter workout month to add: ";
                                cin >> Date1.month;
                                cout << "Please enter workout day to add: ";
                                cin >> Date1.day;
                                cout << "Please enter workout year to add: ";
                                cin >> Date1.year;
                                validWorkoutname = true;
                                validWorkout = true;
                            }

                    }
                

            }
        
    }




    //Workout1.dates = Date1; cannot have this before we input data for day,month, and year or else nothing is copied into Workout1.dates
    
    //by doing this we assign the Date object to Workout objects Date member 



    Workout1.date = Date1;
    //this copies the entire Date1 object into the dates member of Workout1, we need this after we assign values to day,month, and year

    //now after doing Workout1.name & Workout1.date we temporarily are storing those
    //Workout1
    //------------
    //name = Push
    //date = Monday
    //into the Workout1 object, but then we push it back onto Workouts below


    Workouts.push_back(Workout1);



    //Workouts.push_back(Date1); cannot do this as our vector only accepts workout objects 
    //think about it, Workouts is a vector that holds workouts
    //the reason why we can do this currentWorkout.Exercises.push_back(Exercise1);
    //is because Exercises is a vector
    //we don't have a vector named Dates we can push data into


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

void removeExercises(Workout &currentWorkout, vector<Workout> &Workouts){
    string removedExercise;
    cout << "Please select exercise to remove" << endl;

    for (int i = 0; i < Workouts.size(); i++){
                for (int j = 0; j < Workouts[i].Exercises.size(); j++){

                    cout << "Exercise: " << Workouts[i].Exercises[j].name << endl;

                    getline(cin >> ws, removedExercise);

                    if(removedExercise == Workouts[i].Exercises[j].name){//
                        cout << "matched" << endl;

                        //Workouts[i].Exercises[j].name.erase();
                        //Workouts[i].Exercises[j].weight.erase(); cannot .erase or .clear a double, must set = 0 ;
                        //Workouts[i].Exercises[j].reps.clear();
                        //Workouts[i].Exercises[j].sets.clear();

                        currentWorkout.Exercises.erase(currentWorkout.Exercises.begin() + j);
                        //inside currentWorkout, inside Exercises, erase exercise at position j

                    }


                }
    }




}



void adjustExercises(Workout &currentWorkout, vector<Workout> &Workouts){
    string userOptionname;
    string userOptionitem;
    string adjustedName;
    string adjustedWeight;
    string adjustedReps;
    string adjustedSets;
    bool validOption = false;
    bool validWorkout = false;

    for (int i = 0; i < Workouts.size(); i++){
        for (int j = 0; j < Workouts[i].Exercises.size(); j++){
            if (j == 0){
                cout << "Exercise: " << Workouts[i].Exercises[j].name;
            }
            else{
                cout << ", " << Workouts[i].Exercises[j].name;
            }
        }
    }
    cout << endl;

    while(validWorkout == false){
        cout << "Please enter workout to adjust: ";
        //cin >> userOptionname
        getline(cin >> ws, userOptionname);//must use getline cin or else if you tried one above, it wouldnt work bc of space in bench press if space was there for ex
        //bc for Exercise.name, getline is used not cin

        //cout << "user option name: " << userOptionname << endl;
        
        for (int i = 0; i < Workouts.size(); i++){
            for (int j = 0; j < Workouts[i].Exercises.size(); j++){
                //cout << "current workout name: " << currentWorkout.Exercises[j].name << endl;
                if(userOptionname == currentWorkout.Exercises[j].name){
                        cout << "----------" << endl;
                        cout << "1. Name - current name: " << currentWorkout.Exercises[j].name << endl;
                        cout << "2. Weight - current weight: " << currentWorkout.Exercises[j].weight << endl;
                        cout << "3. Reps - current reps: " << currentWorkout.Exercises[j].reps << endl;
                        cout << "4. Sets - current sets: " << currentWorkout.Exercises[j].sets << endl;

                        cout << "----------" << endl;

                        while(validOption == false){

                            cout << "Enter number of item you want to adjust: ";
                            cin >> userOptionitem;
                            cout << "----------" << endl;



                            if(userOptionitem == "1"){
                                cout << "Enter name you want to replace with: ";
                                getline(cin >> ws, adjustedName);


                                //currentWorkout.name = adjustedName; this adjusts the name of the workout, we need to adjust the name of the exercise NOT workout
                                //currentWorkout.Exercises.name = adjustedName; not valid syntax as Exercises is a vector, not a single Exercise
                                //this is saying take this entire vector and access its name, but Exercises vector doesn't have a member called name, we have to specify which
                                //Exercise inside the vector we want to change like Exercise[0]

                                // currentWorkout.Exercises[0].name = adjustedName; LIKE THIS

                                currentWorkout.Exercises[j].name = adjustedName;

                                validOption = true;
                                validWorkout = true;
                            }
                            if(userOptionitem == "2"){
                                cout << "Enter weight you want to replace with: ";
                                getline(cin >> ws, adjustedWeight);
                                //currentWorkout.weight = adjustedWeight;

                                currentWorkout.Exercises[j].weight = adjustedWeight;
                                validOption = true;
                                validWorkout = true;
                            }
                            if(userOptionitem == "3"){
                                cout << "Enter reps you want to replace with: ";
                                getline(cin >> ws, adjustedReps);
                                
                                currentWorkout.Exercises[j].reps = adjustedReps;
                                validOption = true;
                                validWorkout = true;
                            }
                            if(userOptionitem == "4"){
                                cout << "Enter sets you want to replace with: ";
                                getline(cin >> ws, adjustedSets);
                                currentWorkout.Exercises[j].sets = adjustedSets;
                                
                                validOption = true;
                                validWorkout = true;
                            }
                            if(validOption == false){
                                cout << "Please enter valid number" << endl;
                            }

                        }
                }

            }
    }

    }




}

int workoutVerification(vector<Workout> &Workouts){ // return a reference so we dont return a copy, so use Workout&
    string removedWorkoutname;
    string removedWorkoutmonth;
    string removedWorkoutday;
    string removedWorkoutyear;
    bool matchingWorkoutname = false;
    bool matchingWorkoutmonth = false;
    bool matchingWorkoutday = false;
    bool matchingWorkoutyear = false;
    bool matchedName = false;

    while(matchingWorkoutname == false){
        cout << "Please enter workout name: ";
        getline(cin >> ws, removedWorkoutname);
        for (int i = 0; i < Workouts.size(); i++){
            if (removedWorkoutname == Workouts[i].name){
                matchedName = true;
                while(matchingWorkoutmonth == false){
                    cout << "Please enter workout month: ";
                    cin >> removedWorkoutmonth;


                        if(removedWorkoutmonth == Workouts[i].date.month){
                            while(matchingWorkoutday == false){
                                cout << "Please enter workout day: ";
                                cin >> removedWorkoutday;
                                if(removedWorkoutday == Workouts[i].date.day){
                                    while(matchingWorkoutyear == false){
                                        cout << "P;ease enter workout year: ";
                                        cin >> removedWorkoutyear;
                                        if(removedWorkoutyear == Workouts[i].date.year){
                                            //return Workouts[i];//need to return current workout we are on aka Workouts[i],
                                            return i;
                                            matchingWorkoutyear = true;
                                        }
                                        else{
                                            cout << "Please enter valid year" << endl;
                                        }
                                    }
                                    matchingWorkoutday = true;
                                }
                                else{
                                    cout << "Please enter valid day" << endl;
                                }

                            }
                            matchingWorkoutmonth = true;
                        }
                        else{
                            cout << "Please enter valid month" << endl;
                        }
                    
                }


                matchingWorkoutname = true;
            }


        }
        if (matchedName == false){
                cout << "Please enter valid name" << endl;
                //need to put this shit out of loop or else if u put in for loop, after every iteration where user inputted name is not equal to name in vector, it will show as 
                //please enter valid name when it should only show if it was never valid in the first place
            }

    }



}


void continueWorkout(vector<Workout> &Workouts){//the parameters is what the function EXPECTS to receive when it is called !!!! 
    //we need vector<Workout> &Workouts because we need the access our entire Workouts vector of Workout objects to see which Workout object the user wants to add exercises to

    //Workouts is the name of our vector
    //we need to now replace everything in here to check and see if it matches with
    //the different objects aka correct workout name and date 
    string exerciseOption;
    bool validExerciseoption = false;


    cout << "Workouts: ";
    for (int i = 0; i < Workouts.size(); i++){//loop through size of vector
        if (i == 0){
            //cout << Workouts[i];
            //remember though the temp Workout Workout1 object is gone but we pushed
            //the copy into the vector so we still have that 
            cout << Workouts[i].name << " - ";
            cout << Workouts[i].date.month << "/" << Workouts[i].date.day << "/" << Workouts[i].date.year;
        }
        else{
            cout << ", " << Workouts[i].name << " - ";
            cout << Workouts[i].date.month << "/" << Workouts[i].date.day << "/" << Workouts[i].date.year;
        }
    }
    //this will print out the elements in our vector
    
    cout << endl;



    int i = workoutVerification(Workouts);

    cout << "----------" << endl;  


    while(validExerciseoption == false){
        cout << "1. Add exercises " << endl;
        cout << "2. Remove exercises " << endl;
        cout << "3. Adjust exercises" << endl;
        cout << "Please enter number: ";
                                                        
        cin >> exerciseOption;
        if(exerciseOption == "1"){
            cout << "----------" << endl;
            addExercises(Workouts[i]);
            validExerciseoption = true;
        }
        if(exerciseOption == "2"){
            if(Workouts[i].Exercises.empty()){
                cout << "Exercise list is empty" << endl;
            }
            else{
                cout << "----------" << endl;
                removeExercises(Workouts[i], Workouts);
                validExerciseoption = true;
            }
        }
        if(exerciseOption == "3"){
            if(Workouts[i].Exercises.empty()){
                cout << "Exercise list is empty" << endl;                                                 
            }
            else{
                cout << "----------" << endl;                                                
                adjustExercises(Workouts[i], Workouts);
                validExerciseoption = true;
            }
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
            cout << Workouts[i].name << " - " << Workouts[i].date.month << "/" << Workouts[i].date.day << "/" << Workouts[i].date.year;
        }
        else{
            cout << ", " << Workouts[i].name << " - " << Workouts[i].date.month << "/" << Workouts[i].date.day << "/" << Workouts[i].date.year;
        }
    }
    cout << endl;
    //this prints out each workout name and date at each position in our vector 
    
    //if(workouts)
    //workoutVerification(Workouts); first call
    
    int index = workoutVerification(Workouts);//must declare index like this, how does this call workoutVerification function the second time?
    //function must execute to produce a value, DO NOT call it twice!!!
    //this gets the index of the specific workout we want in the Workouts vector so it gets the Workouts[i] value 

    Workouts.erase(Workouts.begin() + index);

    cout << "----------" << endl;

}

void viewWorkout(vector<Workout> &Workouts){
    bool emptyExercises = true;

    cout << "Workouts: ";
    for (int i = 0; i < Workouts.size(); i++){
        if (i == 0){
            cout << Workouts[i].name << " - ";
            cout << Workouts[i].date.month << "/" << Workouts[i].date.day << "/" << Workouts[i].date.year;
            //need to separate i and j because we cannot use them for the same or else it will miss certain indexes 
            

        }
        else{
            cout << ", " << Workouts[i].name << " - ";
            cout << Workouts[i].date.month << "/" << Workouts[i].date.day << "/" << Workouts[i].date.year;

            
        }
    }
    cout << endl;

    cout << "----------" << endl;

    int i = workoutVerification(Workouts);
    //for(int i = index; i < Workouts.size(); i++){//we want it so it stays on the particular Workouts[i] with our specific returned i value from the Workout we want to access

    while(emptyExercises == true){//while 
        if(Workouts[i].Exercises.empty()){//if our Workout has no exercises in it, we just cout its empty and break out
            cout << "Exercise list is empty" << endl;
            break;
        }
        else{
            for (int j = 0; j < Workouts[i].Exercises.size(); j++){
                cout << "Exercise: " << Workouts[i].Exercises[j].name << endl;
                cout << "Weight: " << Workouts[i].Exercises[j].weight << endl;
                cout << "Reps: " << Workouts[i].Exercises[j].reps << endl;
                cout << "Sets: " << Workouts[i].Exercises[j].sets << endl;
                emptyExercises = false;
            }
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