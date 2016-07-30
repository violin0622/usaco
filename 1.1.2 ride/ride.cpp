/*
ID:violin01
LANG:C++
TASK:ride
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");

	char names[7] = {'\0'};
	char groups[7] = {'\0'};

	int i = 0;
	while(i<8 && (names[i] = fin.get()) != '\n'){
		i++;
	}
	i=0;
	while(i<8 && (groups[i] = fin.get()) != '\n'){
		i++;
	}
	int one = 1,two = 1;
	for(i=0;names[i] != '\n';i++){
		one *= (names[i]-'A'+1);
	}
	for(i=0; groups[i] != '\n'; i++){
		two *= (groups[i]-'A'+1);
	}
	
	if(two%47 == one%47){
		fout << "GO" << endl;
	}else{
		fout << "STAY" << endl;
	}

	return 0;
}
