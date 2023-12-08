#include <iostream>
#include "caesar.h"

using namespace std;


int main()
{	
	int shift;
		
	cout << "Zahl fuer Shifting eingeben: ";
	cin >> shift;

	
	CaesarExtended c("montag", shift);
	string sentence = "Kindergeburtstag";
	string encryptedSentence = c.encrypt(sentence);
	cout << "Verschuesselt: " << encryptedSentence << endl;
	cout << "Entschuesselt: " << c.decrypt(encryptedSentence) << endl;
	
	return 0;
}
