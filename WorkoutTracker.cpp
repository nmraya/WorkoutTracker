#include <iostream>
#include <string>
#include <vector>
using namespace std;




int main(){

    string menuInput;
    bool validNumber = false;

    cout << "Welcome to Raya Fitness Tracker" << endl;
    cout << "1. Add Workout" << endl;
    cout << "2. Continue Existing Workout" << endl;
    cout << "3. Remove Workout" << endl;
    cout << "4. View Previous Workout" << endl;

    while (validNumber == false){
        cout << "Please Enter Number: ";
        cin >> menuInput;

        if (menuInput == "1"){
            cout << "Adding Workout" << endl;
            validNumber = true;
        }
        else if (menuInput == "2"){
            cout << "Continuing Existing Workout" << endl;
            validNumber = true;
        }
        else if (menuInput == "3"){
            cout << "Removing Workout" << endl;
            validNumber = true;
        }
        else if (menuInput == "4"){
            cout << "Viewing Previous Workout" << endl;
            validNumber = true;
        }
        else{
            cout << "Please Enter Again" << endl;
            validNumber == false;
        }
    }






    return 0;
}