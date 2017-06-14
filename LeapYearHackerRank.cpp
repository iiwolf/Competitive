#include <bits/stdc++.h>

using namespace std;

bool isLeap(int year){
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
		return true;
	}
	return false;
}

int main(){
    int y;
    cin >> y;
	
	if(isLeap(y)){
		cout << "12.09." << y << endl;
	}
	else{
		cout << "13.09." << y << endl;
	}
	
    // your code goes here
    return 0;
}
