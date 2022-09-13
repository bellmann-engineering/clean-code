#include <vector>
#include <string>
using namespace std;

class Address 
{

    private:
        string streetName;
        string zipCode;

    public:
        Address()  
        {

        }

        string getStreetName() 
        {
            return this->streetName;
        }
        
        void setStreetName(string streetName) 
        {
            this->streetName = streetName;
        }

        string getZipCode() 
        {
            return this->zipCode;
        }
        
        void setZipCode(string zipCode) 
        {
            this->zipCode = zipCode;
        }

};

class Person 
{

    private:
        string fullName;

    public:
        Person() 
        {

        }
        
        void setFullName(string fullName) 
        {
            this->fullName = fullName;
        }

        string getFullName()
        {
            return this->fullName;
        }
};


class House 
{
    private:
        Address* address;
        Person* person;
    public:
        House() 
        {

        }

        House(Address* address, Person* person)
        {
            this->address = address;
            this->person = person;
        }

        ~House() 
        {
            if(this->address)
            {
                delete address;
                address = nullptr;
            }
            if(this->person)
            {
                delete person;
                person = nullptr;
            }
        }

        Address* getAddress()
        {
            return this->address;
        }

        Person* getPerson()
        {
            return this->person;
        }

}; 