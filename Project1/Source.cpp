//Bartlett Powell
//Gelo Programming Project
//Menu driven Program for coffee menu


#include<iostream>
#include <iomanip>// Allows me to restrict money output to 2 decimal points

using namespace std;
//Constants for determining information about coffee shop
const float smallcoffee = 1.5;
const float largecoffee = 1.9;
const float cprice = 3;
const float bprice = .6;
// Function to sell coffee
void sell_coffee(float& money, int& scoffee, int& lcoffee) {
    int choose, amt;
    // Allows you to choose which size
    cout << "Enter 1 for 9oz\t2 for 12 oz" << endl; 
    cin >> choose;
    while (choose != 1 && choose != 2) { //Validates input
        cout << "Choose 1 or 2..." << endl;
        cin >> choose;
    }
    cout << "How many cups of coffee would you like to purchase?" << endl;
    cin >> amt;
    // Calculates price for small coffee
    if (choose == 1) {
        scoffee += amt;
        money += amt * smallcoffee;
    }
    // Calculates price for large coffee
    else if (choose ==2) {
        lcoffee += amt;
        money += amt * largecoffee;
    }
}

// Function to sell cake
void sell_cake(float& money, int& slice) {
    int amt;
    cout << "How many slices of cake would you like to buy?" << endl;
    cin >> amt;
    slice += amt;
    // Math for money from cake
    money += amt * cprice; //Multiplies price by amount of cake sold
}

// Function to sell coffee beans
void sell_coffee_beans(float& money, int& beans) {
    int amt;
    cout << "How many oz would you like to purchase ($0.6 per oz)" << endl;
    cin >> amt;
    beans += amt;
    // Math for calculating money from beans
    money += amt * bprice; //Multiplies price by amount of beans sold
}

// Function for items sold
void sold(int scoffee, int lcoffee, int slice, int beans) {
    cout << "Number of sold Items" << endl;
    cout << "Small Coffee (9 oz)\t" << scoffee << endl; // Prints small coffee amount
    cout << "Large Coffee (12 oz)\t" << lcoffee << endl; // Prints large coffee amount
    cout << "Cheese Cake Slices\t" << slice << endl; // Prints cake amount
    cout << "Coffee Beans\t" << beans<< endl; // Prints beans amount
}
//Function for cups of coffee sold
void coffeesold(int scoffee, int lcoffee) {
    int csold;
    csold = scoffee + lcoffee; //Adds amount of small cups and large cups together
    cout << "We have sold " << csold << " cups of coffee." << endl;
}

// Function for money earned
void total_money(float money) {
    cout << "We have earned $" << fixed << setprecision(2) << money << endl;
}

int main() {
    float money = 0;
    int scoffee = 0;
    int lcoffee = 0;
    int slice = 0;
    int beans = 0;
    int choose;
    while (1) {
        cout << endl;
        cout << "COFFEE SHOP MENU\n";//Outputs Coffee shop Menu
        cout << "1. Coffee\n";
        cout << "2. Cake\n";
        cout << "3. Coffee Beans\n";
        cout << "4. Amount Sold\n";
        cout << "5. Coffee Sold\n";
        cout << "6. Money Earned\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choose;
        switch (choose) { //Switch statement that allows for menu choices
        case 1:
            sell_coffee(money, scoffee, lcoffee);
            break;
        case 2:
            sell_cake(money, slice);
            break;
        case 3:
            sell_coffee_beans(money, beans);
            break;
        case 4:
            sold(scoffee, lcoffee, slice, beans);
            break;
        case 5:
            coffeesold(scoffee, lcoffee);
            break;
        case 6:
            total_money(money);
            break;
        case 7:
            cout << "Exit..." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
    return 0;
}