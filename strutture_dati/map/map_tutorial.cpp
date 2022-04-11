/*

Test della struttura dati MAP
Luigi Daddario (mat.685195)

*/

#include <iostream>
#include <map>
#include <string.h>
#include <iterator>



using namespace std; 

int main(int argc, char** argv) {
	
	std::map<int, std::string> dict; //students using id
	dict[1] = "Luigi";
	dict[2] = "Max";
	dict[2] = "MAx2";
	
	cout << dict[2];
	
dict.insert(pair<int,string>(3,"Marco"));

map<int, string>::iterator it = dict.find(2);
cout << "key found" << it->second << endl; 

for(auto it = dict.begin(); it!=dict.end(); it++ )
{
	cout << it->first << " => " << it->second << endl;
}
	
	map<char, int> dict2;
	dict2['a'] = 12;
	dict2['b'] = 18;
	
	
	for(auto it=dict2.begin();it!=dict2.end();++it)
	{
		cout << it->first << "=>" << it->second << endl;
	}
	
	
	
	return 0;
}
