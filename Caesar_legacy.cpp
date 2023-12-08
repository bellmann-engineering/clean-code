#include <iostream>
#include "caesar.h"

using namespace std;

int main()
{
	int shift = 0;
	
	cin.exceptions(ios_base::failbit);
	
	cout << "Zahl eingeben:" ;		
	
	try
	{	
		cin >> shift;
	}
	/*catch(ios_base::failure&)
	{
		cout << "IOS Exception" << endl;
		return 0;
	}*/	
	catch(exception& e)
	{
		cout << "Laufzeitfehler: "  << e.what() << endl;
		return 0;
	}
	catch(...)
	{
		cout << "alle Laufzeitfehler" << endl;
		return 0;
	}
	
	/*if(cin.fail())
	{
		cout << "das war keine zahl" << endl;
		cin.clear();
		cin.ignore();
		
		return 0;
	}*/
	

	
	CaesarExtended c("montag", shift);
	string sentence = "Kindergeburtstag";
	string encryptedSentence = c.encrypt(sentence);
	cout << "Verschuesselt: " << encryptedSentence << endl;
	cout << "Entschuesselt: " << c.decrypt(encryptedSentence) << endl;
}
