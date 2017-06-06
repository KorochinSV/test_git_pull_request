#include <iostream>
#include <string>
#include <sys/types.h>
#include <regex>
#include <map>

using namespace std;

int main(int a, char ** v)
{	
	string inb;
	cin >> inb;	
//	inb = "2*x^100+100*x^2+3*x-2*x+8";
    	map<int, int> m; 
    	
	regex r("(-?\\d*)\\*?x\\^?(\\d*)");
//	regex r("([\+-]?)([[:d:]]*)\\*?(x?)\\^?([[:d:]]*)");
    	sregex_iterator pos(inb.cbegin(), inb.cend(),r);
	sregex_iterator end;
	int power = 1;
	int koef = 1;
	for(; pos != end; pos++)
    	{
		if (pos->str(1) != "") 
			if (pos->str(1) == "-") koef = -1;
			else koef = stoi(pos->str(1));
		else koef = 1;
	        if (pos->str(2) != "") power = stoi(pos->str(2));
	        else power = 1;
        	m[power] += koef;
	}	
	bool b = true;
	for(auto rim = m.crbegin(); rim != m.crend(); rim++)
	{
		if (!b) {
			if (rim->second > 0) cout << "+";
		}
		else b = false;
		cout << rim->first * rim->second;
		if (rim->first > 1) 
		{
			cout << "*x";
			if (rim->first > 2) cout << "^" <<  rim->first - 1;
		}
	}
	cout << '\n';
	return 0;
}
