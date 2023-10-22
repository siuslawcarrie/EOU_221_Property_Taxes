/*
Carrie Bailey
CS221 Fall 2023
October 23, 2023
Week 2, Program #1: Property Taxes
This program asks the user for the assessed value of their property then calculates the tax based on $1.05 per $100 of property tax value which is 92% of
 assessed value.
 */
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <limits>

using namespace std;

/*
 Property tax:
 --USER INPUT
 1.Ask for user's name
 2. Ask for user's physical address
    street number
    street name
    address line 2
    city
    state
    zip
3. Ask user if they have a mailing address.
 IF statement
 If yes, same prompts as in #2.
 3. Ask for assessed value.
 --END USER INPUT

 --VARIABLES
 TYPE string
homeowner name: owner_name
street number: street_number
street name: street_name
 city: city
 state: state
 zip: zip
 address line 2: line_2
 mailing:
 m_street_number
 m_street_name
 m_line_2
 m_city
 m_state
 m_zip
 Press to start: any_key

 TYPE integer
 property tax value = property_tax_value
 property tax amount: tax_amount
 assessed value: assessed_value
 calculated property tax value, math rounding: assessed_value_calc
converted property tax amount, math rounded: property_tax_amount_calc
 width_output: width of the itemized list

 TYPE double
 tax rate: tax_rate $1.05 per $100

 PROGRAM
 Welcome
 Press any key to start
 Ask user for their name.
 Ask for physical address, separated by each field.
 Ask if they have a mailing address.
 IF statement.
 Ask for assessed value
 Calculate property tax
 --DISPLAY
 for address (justify)

*/

int main() {
//Variables

//OWNER INFORMATION
    string owner_name; //owner's name
    string street_name, city, state; //physical address info
    string m_street_name, m_city, m_state; //mailing address info
    int street_number, m_street_number; //physical street number, mailing street number
    int zip, m_zip; //zip codes
    char yes_mailing_address; //yes if mailing address

//HOUSE INFORMATION
    double assessed_value;
    double property_tax_value;

//TAX CALCULATIONS
    double tax_amount, tax_rate;
    tax_rate = 1.05;
    //end variables

//ask for owner information
    cout << "Easily calculate your property tax amount!" << endl;
    cout << "Press enter to start.";
    cin.ignore();
    cout << "What is your name? " << endl; //ask for username
    getline(cin, owner_name);
    cout << "Next I'll be asking for your address." << endl;
    sleep(1);
    cout << "For the physical address of house, please enter the street number only: " << endl;
    cin >> street_number;
    cin.ignore();
    cout << "Enter house street name: " << endl;
    getline(cin, street_name);
    cout << "Enter house city: " << endl;
    getline(cin, city);
    cout << "Enter house state: " << endl;
    getline(cin, state);
    cout << "Enter house zip code: " << endl;
    cin >> zip;
    cout << "Do you have a mailing address? Y for yes, N for no. " << endl;
    cin >> yes_mailing_address;
    if ((yes_mailing_address == 'Y') or (yes_mailing_address == 'y')) {
        cout << "For your mailing address, please enter the street number only: "
             << endl;
        cin >> m_street_number;
        cin.ignore();
        cout << "Enter street name or if PO Box, enter here, including PO Box number: " << endl;
        getline(cin, m_street_name);
        cout << "Enter city: " << endl;
        getline(cin, m_city);
        cout << "Enter state: " << endl;
        getline(cin, m_state);
        cout << "Enter zip code: " << endl;
        cin >> m_zip;
    }

//ask for property tax information
    cout << "Enter the assessed value of your house: " << endl;
    cin >> assessed_value;

//display
        cout << "Processing. Please wait." << endl << endl;
        sleep(3);
        cout << "Property tax information for:" << endl << endl;
        cout << street_number << " " << street_name << " " << endl;
        cout << city << ", " << state << " " << zip << endl << endl;

        cout << "Owner information: " << endl;
        cout << owner_name << endl;
        cout << "Mailing address:" << endl;
        if ((yes_mailing_address == 'Y') || (yes_mailing_address == 'y')) {

        cout << m_street_number << " "  << m_street_name << " " << endl;
        cout << m_city << ", " << m_state << " " << m_zip << endl << endl;
        } else {
        cout << street_number << " " << street_name << " " << endl;
        cout << city << ", " << state << " " << zip << endl << endl;
        }
//calculation of property tax
        property_tax_value = assessed_value * .92;
        tax_amount = property_tax_value / 100 * tax_rate;
//display of property taxes, itemized
        cout << left << setw(30) << setfill('.') << "Assessed Value" << "$" << setw(11) << setfill(' ') << right
             << fixed << setprecision(2) << assessed_value << endl;
        cout << left << setw(30) << setfill('.') << "Taxable Amount" << "$" << setw(11) << setfill(' ') << right
             << fixed << setprecision(2) << property_tax_value << endl;
        cout << left << setw(30) << setfill('.') << "Tax Rate for each $100.00" << "$" << setw(11) << setfill(' ')
             << right << fixed << setprecision(2) << tax_rate << endl;
        cout << left << setw(30) << setfill('.') << "Property Tax" << "$" << setw(11) << setfill(' ') << right << fixed
             << setprecision(2) << tax_amount << endl;


        return 0;
    }
