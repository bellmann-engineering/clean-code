#include<iostream>

#include "Bad.h"

using namespace std;
 
 
int main(int argc, const char * argv[]) {
    
    Person* john = new Person();
    john->setFullName("John Dosch");

    Address* address = new Address();
    address->setStreetName("Rosa-Luxemburg-Allee.");
    address->setZipCode("12345");

    House* home = new House(address, john);
    //Bad: this is a chain...
    //House should not have knowledge about Address
    cout << home->getAddress()->getStreetName() << endl;

    if(home != nullptr)
        delete home;

    return 0;
 
}