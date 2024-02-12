//joseph gebretsadik
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool login(const string& username, const string& password);
void getUserInput(string& fullName, int& age, double& height, string& loseorGain, double& currentWeight, double& goalWeight, int& months);
void calculateMetrics(double currentWeight, double height, int age, double goalWeight, double& currentBMI, double& BMR, double& Maintenance, double& weightLoss, double& weightGain, int months, string loseorGain);
double calculateCalorieRecommendation(double Maintenance, double weightLossOrGain, int months);
void printClientProfile(const string& fullName, int age, double height, double currentWeight, double goalWeight, double currentBMI, int months, double Maintenance, double proteinGoal, const string& advice);
void printLiftSchedule();

int main() {
    string enteredUsername, enteredPassword;

    cout << "Enter username: ";
    cin >> enteredUsername;

    cout << "Enter password: ";
    cin >> enteredPassword;

    cin.ignore();

    if (login(enteredUsername, enteredPassword)) {
        cout << "Login successful. Welcome to Geb Athletics!" << endl;

        string fullName;
        int age, months;
        double goalWeight, currentWeight, height, currentBMI, Maintenance, BMR, weightLoss, weightGain, calorieRecommendation, proteinGoal;
        string loseorGain, advice;

        getUserInput(fullName, age, height, loseorGain, currentWeight, goalWeight, months);
        calculateMetrics(currentWeight, height, age, goalWeight, currentBMI, BMR, Maintenance, weightLoss, weightGain, months, loseorGain);
        calorieRecommendation = calculateCalorieRecommendation(Maintenance, (loseorGain == "lose") ? weightLoss : weightGain, months);
        proteinGoal = currentWeight * 0.8;
        advice = (loseorGain == "lose") ? "You should eat more protein, clean food, lift heavy (go to failure), do cardio and watch your carb, processed food and sugar intake." : "You should eat more protein, clean food, lift heavy (go to failure), and mix in some cardio to maintain cardiovascular health.";

        printClientProfile(fullName, age, height, currentWeight, goalWeight, currentBMI, months, Maintenance, proteinGoal, advice);
        printLiftSchedule();
    } else {
        cout << "Login failed. Invalid credentials." << endl;
    }
    return 0;
}

bool login(const string& username, const string& password) {
    const string validUsername = "joseph";
    const string validPassword = "1234";

    return (username == validUsername && password == validPassword);
}

void getUserInput(string& fullName, int& age, double& height, string& loseorGain, double& currentWeight, double& goalWeight, int& months) {
    cout << endl << "Enter full name: ";
    getline(cin, fullName);

    cout << endl << "Enter age: ";
    cin >> age;

    cout << endl << "Enter height in inches: ";
    cin >> height;

    cout << endl << "Do you want to gain or lose: ";
    cin >> loseorGain;

    cout << endl << "Enter current weight (in pounds): ";
    cin >> currentWeight;

    cout << endl << "Enter goal weight (in pounds): ";
    cin >> goalWeight;

    cout << "Enter amount of months to reach goal weight: ";
    cin >> months;
}

void calculateMetrics(double currentWeight, double height, int age, double goalWeight, double& currentBMI, double& BMR, double& Maintenance, double& weightLoss, double& weightGain, int months, string loseorGain) {
    currentBMI = (currentWeight / pow(height, 2)) * 703;
    BMR = 66 + (6.23 * currentWeight) + (12.7 * height) - (6.8 * age);
    Maintenance = BMR * 1.375;
    weightLoss = (currentWeight - goalWeight);
    weightGain = (goalWeight - currentWeight);
}

double calculateCalorieRecommendation(double Maintenance, double weightLossOrGain, int months) {
    return Maintenance + (weightLossOrGain * 3500.0 / months);
}

void printClientProfile(const string& fullName, int age, double height, double currentWeight, double goalWeight, double currentBMI, int months, double Maintenance, double proteinGoal, const string& advice) {
    cout << "\nClient Profile: " << endl;
    cout << "Name: " << fullName << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << " inches" << endl;
    cout << "Current Weight: " << currentWeight << " pounds" << endl;
    cout << "Goal Weight: " << goalWeight << " pounds" << endl;
    cout << "Current BMI: " << currentBMI << endl;
    cout << "Time it will take to reach goal: " << months << " Months" << endl;
    cout << "Maintenance Calories: " << Maintenance << endl;
    cout << "Eat about " << proteinGoal << " grams of protein per day" << endl;
    cout << advice << endl;
}

void printLiftSchedule() {
    cout << "\nLift Schedule: " << endl;
    cout << "Cardio (treadmill): Speed 3.5, Incline Max" << endl;
    cout << "\nDay 1 (chest & triceps): " << endl;
    cout << "Chest: Dumbbell Bench 4x10" << endl;
    cout << "Chest: Incline Dumbbell Bench 4x10" << endl;
    cout << "Chest: Standing Incline Cable Fly 4x10" << endl;
    cout << "Chest: Cable Flys 4x10" << endl;
    cout << "Tricep: Rope Pull Down 4x10" << endl;
    cout << "Tricep: Overhead Cable Tricep Extension 4x10" << endl;
    cout << "Tricep: Dips 4x10" << endl;
    cout << "\nDay 2 (back & biceps): " << endl;
    cout << "Back: Lat Pulldown 4x10" << endl;
    cout << "Back: Seated Row 4x10" << endl;
    cout << "Back: Bent Over Rows 4x10" << endl;
    cout << "Back: Pullups 4x10" << endl;
    cout << "Biceps: Hammerhead Curls 4x10" << endl;
    cout << "Biceps: Preacher Curls 4x10" << endl;
    cout << "Biceps: Cable Curls 4x10" << endl;
    cout << "Biceps: Reverse Curls 4x10" << endl;
    cout << "\nDay 3 (legs & shoulders): " << endl;
    cout << "Legs: Squats 4x10" << endl;
    cout << "Legs: Calf Raises 4x10" << endl;
    cout << "Legs: Leg Press 4x10" << endl;
    cout << "Legs: Leg Extensions 4x10" << endl;
    cout << "Shoulders: Overhead Press 4x10" << endl;
    cout << "Shoulders: Lateral Raises 4x10" << endl;
    cout << "Shoulders: Front Raises 4x10" << endl;
    cout << "Shoulders: Delt Fly Machine 4x10" << endl;
    cout << "\nDay 4 (chest & triceps): " << endl;
    cout << "Chest: Dumbbell Bench 4x10" << endl;
    cout << "Chest: Incline Dumbbell Bench 4x10" << endl;
    cout << "Chest: Standing Incline Cable Fly 4x10" << endl;
    cout << "Chest: Cable Flys 4x10" << endl;
    cout << "Tricep: Rope Pull Down 4x10" << endl;
    cout << "Tricep: Overhead Cable Tricep Extension 4x10" << endl;
    cout << "Tricep: Dips 4x10" << endl;
    cout << "\nDay 5 (back & biceps): " << endl;
    cout << "Back: Lat Pulldown 4x10" << endl;
    cout << "Back: Seated Row 4x10" << endl;
    cout << "Back: Bent Over Rows 4x10" << endl;
    cout << "Back: Pullups 4x10" << endl;
    cout << "Biceps: Hammerhead Curls 4x10" << endl;
    cout << "Biceps: Preacher Curls 4x10" << endl;
    cout << "Biceps: Cable Curls 4x10" << endl;
    cout << "Biceps: Reverse Curls 4x10" << endl;
    cout << "\nDay 6 (legs & shoulders): " << endl;
    cout << "Legs: Squats 4x10" << endl;
    cout << "Legs: Calf Raises 4x10" << endl;
    cout << "Legs: Leg Press 4x10" << endl;
    cout << "Legs: Leg Extensions 4x10" << endl;
    cout << "Shoulders: Overhead Press 4x10" << endl;
    cout << "Shoulders: Lateral Raises 4x10" << endl;
    cout << "Shoulders: Front Raises 4x10" << endl;
    cout << "Shoulders: Delt Fly Machine 4x10" << endl;
}
