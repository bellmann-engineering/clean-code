#include <string>
using namespace std;

class CaesarExtended 
{
	private:
		string a; 
		string k;
			
	public:
		CaesarExtended(string w, int s)
		{
			for(char c='a'; c<='z';c++)
				a += c;		
			
			for(char c='A'; c<='Z';c++)
				a += c;	
			
			string alpha = a;
			int alphaLen = a.size();
				
			int n = w.size();

			for (int i = 0; i < n; i++) 
			{
				char ch = w[i];
				int z = alpha.find(ch);
				alpha = alpha.substr(0,z) + alpha.substr(z+1,alphaLen-i);
			}
			
			int na = alpha.size();
			k = alpha.substr(na-s,na) + w + alpha.substr(0,alphaLen-n-s);			
		}
		 

		string encrypt(string i)
		{
			char c;
			int z;

			string o="";

			for (int j = 0; j < i.size(); j++) 
			{
				c = i[j];
				z = a.find(c);
				char x = k[z];
				o = o + x;
			}

			return o;
		}

		string decrypt(string i)
		{
			char c;
			int z;
			
			string o = "";

			for(int j = 0; j < i.size(); j++) 
			{
				c = i[j];
				z = k.find(c);
				o = o + a[z];
			}

			return o;
		}
};
