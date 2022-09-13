#include<iostream>

#include "Good.h"

using namespace std;
 
 
int main(int argc, const char * argv[]) {
    
    Person* john = new Person();
    john->setFullName("John Dosch");

    Address* address = new Address();
    address->setStreetName("Rosa-Luxemburg-Allee.");
    address->setZipCode("12345");

    House* home = new House(address, john);
    // Good: according to LoD this is better, this increases the adaptiveness and testability
    cout << home->getAddressStreetName() << endl;

    if(home != nullptr)
        delete home;

    return 0;
 
}