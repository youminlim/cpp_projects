// Celcius to farenheit vice versa converter

#include <iostream>
#include <string>
#include <tuple>
using namespace std;

namespace myconv {

// User input prompter
    auto inputer () {

        // Declare variables
        int vChoice;
        double vTemp;

        // Prompt user for temperature type input
        cout << "Temperature Type : " << endl;
        cout << "1. Fahrenheit" << endl << "2. Celcius" << endl;
        cout << "Please indicate the temperature option number : ";
        cin >> vChoice;
        
        while (vChoice < 1 || vChoice > 2) {
            throw logic_error("Number must be either 1 or 2.");
            /* cout << "Please indicate the temperature option number : ";
            cin >> vChoice; */
        }

        // Prompt user for temperature value input
        cout << "Temperature, T = ";
        cin >> vTemp;

        return make_tuple(vChoice, vTemp);
    }

// Fahrenheit to Celcius converter
    double f2c (double vFahrenheit) {
        // Check if input is valid
        if (vFahrenheit < -459.67) {
            throw logic_error("Number must be more than absolute zero.");
            /* cout << "Temperature, T = ";
            cin >> vFahrenheit; */
        }
        // Compute and return conversion
        return (vFahrenheit - 32) * 5/9;
        }

// Celcius to Fahrenheit converter
    double c2f (double vCelcius) {
        // Check if input is valid
        if (vCelcius < -273.15) {
            throw logic_error("Number must be more than absolute zero.");
            /* cout << "Temperature, T = ";
            cin >> vCelcius; */
        }
        // Compute and return conversion
        return (vCelcius * 9/5) + 32;
        }
}

int main() 
{
    // Declare variables
    int vChoice;
    double vTemp, vConv;

    // Perform functions
    try {
        tie(vChoice, vTemp) = myconv::inputer();
        if (vChoice == 1) {
            vConv = myconv::f2c(vTemp);
            cout << vTemp << "°F = " << vConv << "°C" << endl;
        } else {
            vConv = myconv::c2f(vTemp);
            cout << vTemp << "°C = " << vConv << "°F" << endl;
        }
    }
    catch (const logic_error& e) {
        cout << "An error occured: " << e.what() << endl;
    }
    catch (const bad_alloc& e) {
        cout << "Inputted data takes too much memory!" << endl;
    }
}

