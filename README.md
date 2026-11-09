# Workout Tracker

A menu-driven command-line fitness tracker written in C++. Log workouts by
name and date, manage their exercises, and look back at past workouts.

## Features
- Add a workout with a name and date
- Continue an existing workout: add, remove, or adjust its exercises
- Remove a workout
- View a previous workout by looking it up with its name and date
- Workouts are saved to a file and load again on the next run
- Input validation for menu choices, duplicate workout names, and workout lookup

## Example
    Welcome to Raya Fitness Tracker
    1. Add Workout
    2. Continue Existing Workout
    3. Remove Workout
    4. View Previous Workout
    5. Exit
    Please Enter Number: 4
    ----------
    Viewing Previous Workout
    Workouts: push - 3/26/2006
    Please enter workout name: push
    Please enter workout month: 3
    Please enter workout day: 26
    Please enter workout year: 2006
    ----------
    Exercise: bench press
    Weight: 185
    Reps: 5
    Sets: 3

## How to run
    g++ -o WorkoutTracker main.cpp FileIO.cpp WorkoutFunctions.cpp
    ./WorkoutTracker      (on Windows PowerShell: .\WorkoutTracker.exe)

Workouts are saved to `workouts.txt`, which is created automatically on
first run. Choose "5. Exit" to save your workouts; changes are written to
the file on exit, so closing the terminal early loses that session's changes.

## Project structure
- `main.cpp`: menu and program flow
- `WorkoutFunctions.cpp/.h`: add, continue, remove, and view operations
- `FileIO.cpp/.h`: saving and loading workouts
- `Workout.h`, `Exercise.h`, `Date.h`: data classes

## What I practiced
- Splitting a single-file program into separate classes and header files
- File I/O so data persists between sessions
- Validating user input in a command-line program