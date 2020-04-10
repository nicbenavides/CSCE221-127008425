#include <fstream>
#include <cctype>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line, filename, word;
    int pos;

    ifstream in;
    set<string> idents;
    set<string> reserved;
    string reserveArray[]= {"for", "if","else", "fstream", "set","string",
        "include", "main", "using", "namespace","std", "iostream", "string", 
        "ifstream","char","auto","size","open","while","return","int","endl"};
    
    for (int i = 0; i <22; i++)
        reserved.insert(reserved.end(),reserveArray[i]);

    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);
	
	word = "";
    while (in)
    {
		for(int i = 0; i < line.length(); i++){
			if(line[i] == '"'){
				i = line.substr(i+1).find('"')+1+i;
			}
			else if(line[i] == '/' && line[i+1] == '/' && i != line.length()-1){
				continue;
			}
			else if(line[i] == ' ' || line[i] == ';' || line[i] == ',' || line[i] == ':' || line[i] == '<' || line[i] == '>' || line[i] == '(' || line[i] == ')' || line[i] == '{' || line[i] == '}' || line[i] == '=' || line[i]== '#' || line[i] == '.' || line[i] == '-' || line[i] == '0'){
				if(reserved.find(word) == reserved.end() && idents.find(word) == idents.end()){
					idents.insert(idents.end(),word);
				}
				word = "";
			}
			else{
				word = word + line[i];
			}
			
		}
		getline(in,line);
    }

    for (auto x:idents)
        cout<<x<<endl;
    return 0;
}
