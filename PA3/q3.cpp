#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

int insertLinear(int x, vector<int> & linear);
int insertQuad(int x, vector<int> & quad);
int insertDuble(int x, int dubHash, vector<int> & duble);

int main()
{
  int linCollides=0;
  int quadCollides= 0;
  int dubCollides = 0;
  int quadInc;
  int tableSize;
  bool fail = false;
  int x, count=0;
  int doubleHash;

  srand(time(NULL));
  cout<<"enter the size of the table ";
  cin>>tableSize;
  vector<int> linear(tableSize,-1);//initalize each table to -1 for empty
  vector<int> quad(tableSize,-1);  //initalize each table to -1 for empty
  vector<int> duble(tableSize,-1);  //initalize each table to -1 for empty
  do{
   doubleHash = rand()%tableSize;
  }while (doubleHash < tableSize/10 && doubleHash%tableSize==0);

  while(count < tableSize && !fail)
  {
    x= rand()%tableSize;// value to insert
	quadInc=insertQuad(x,quad);
	if (quadInc < 0)
		fail = true;
	else
	{
	 quadCollides += quadInc;
	 linCollides+=insertLinear(x,linear);
	 dubCollides+=insertDuble(x,doubleHash, duble);
	}
	count++;
  }
  cout<<"Num linear collides "<<linCollides<<endl;
  cout<<"Num quadratic collides "<<quadCollides<<endl;
  cout<<"Num double hash collides "<<dubCollides<<endl;
  return 0;
}

int insertLinear(int x, vector<int> & linear)
{
	int collisions = 0;
	int count = x;
	while(linear[count] != -1){
		collisions++;
		count++;
		if(count >= linear.size()){
			count = 0;
		}
	}
	linear[count]=x;
	
    return collisions;
}

int insertQuad(int x, vector<int> & quad)
{
	int collisions = 0;
	int count = x;
	int store = x;
	int i = 0;
	while(quad[count] != -1){
		collisions++;
		count = (store + i +(i*i));
		i++;
		if(count >= quad.size()){
			count = count + (i*i) - quad.size();
		}
	}
	quad[count] = x;
  
  return collisions;
}

int insertDuble(int x, int dubHash, vector<int> & duble)
{
	return 0;
	int i = 0;
	int count = 0;
	bool f = false;
	while(f == false){
		count = (x+i*dubHash) % duble.size();
		if(count>=duble.size()){
			return -1;
		}
		if(duble[count] == -1){
			f = true;
			break;
		}
		cout << i << endl;
		i++;
	}
	if(f){
		duble[count] = x;
	}
  // Remove below line after your implementaion
    return i;
}
