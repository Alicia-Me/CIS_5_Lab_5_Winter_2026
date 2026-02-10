#include <iostream>
#include <string> 
#include <cstdlib> // rand, srand 
#include <ctime> // 

using namespace std;

//Create a structure struct BusinessCard with the following members
struct BusinessCard {
    string companyname;
    string adress;
    string phoneNum;
    string hours;
    string poc;
    float priceQouta; //<---- qoutes are usually rando 
};

int main() {

    srand(time(0));   // different random prices every run

    //Create 5 different companies from the BusinessCard struct 
    BusinessCard place1 = { "KrustyCrabs", "831 Bottom Feeder Lane", "555-501-1999", "5AM - 11PM", "Mr.Krabs", 0 };
    BusinessCard place2 = { "ChumBucket", "842 Bottom Feeder Lane", "1-800-328-2486", "7AM - 8AM", "Plankton", 0 };
    BusinessCard place3 = { "KrustyBurger", "789 SpringField", "407-224-3663", "5AM - 11PM", "Bart", 0 };
    BusinessCard place4 = { "PlanetPizza", "300 Cutting Boulevard", "714-781-4636", "8AM - 10PM", "Woody", 0 };
    BusinessCard place5 = { "BuenoNacho", "800 Middleton", "815-469-8353", "7AM - 9PM", "Kim", 0 }; 

    //---------------------------------------------------------
    // An array to loop through 
    BusinessCard companies[5] = { place1, place2, place3, place4, place5 };

  
    // assign random prices to each company 
    // rand() % 100 + 1 ---> random number between 1 and 100
    for (int i = 0; i < 5; i++) {
        companies[i].priceQouta = rand() % 100 + 1;
    }
    //----------------------------------------------------------
    
    //lowest price
    int lowPrice = 0;

    for (int i = 1; i < 5; i++) {
        if (companies[i].priceQouta < companies[lowPrice].priceQouta) {
            lowPrice = i;
        }
    }
    //-------------------------------------------------
    //highest price
    int highPrice = 0;
    for (int i = 1; i < 5; i++) {
        if (companies[i].priceQouta > companies[highPrice].priceQouta) {
            highPrice = i;
        }
    }

    //-----------------------------------------------------------
    //prints out all the companies prices
    cout << "Companies Prices:\n";
    for (int i = 0; i < 5; i++) {
        cout << companies[i].companyname << ": $" << companies[i].priceQouta << endl;
    }

    //prints out the comparisons-- cheap, costly 

    cout << "\n" << "Cheap Price Match: " << companies[lowPrice].companyname << " with a price of $" << companies[lowPrice].priceQouta << endl;
    cout << "Address: " << companies[lowPrice].adress << endl; cout << "Phone: " << companies[lowPrice].phoneNum << endl;

    cout << "\n" << "Costly Price Match: " << companies[highPrice].companyname << " with a price of $" << companies[highPrice].priceQouta << endl;
    cout << "Address: " << companies[highPrice].adress << endl; cout << "Phone: " << companies[highPrice].phoneNum << endl;
    return 0;
}