#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line, filename;
    map <string,int> coronamap;

    ifstream in;
    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);

    string partOf;
    while (in)
    {
        string country = "";
		int cases = 0;
		in>>country>>cases;
		coronamap[country] = cases;
    }
	map<string,int>::iterator itr;
	int maximum = -1;
	for(itr = coronamap.begin(); itr!=coronamap.end(); ++itr){
		if(itr->second>maximum){
			maximum = itr->second;
			partOf = itr->first;
		}
	}
	cout << "Most confirmed cases are in " << partOf << endl;
    
    // your implementation here to print the country with max cases
    // E.g. Most confirmed cases are in USA

    return 0;
}
