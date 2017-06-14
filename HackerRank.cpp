#include <bits/stdc++.h>

using namespace std;


bool checkNext(string s, int digitSize, int i, int increaseFactor){
    cout << "STARTING INFO: " << s << " - " << digitSize << " - " << i << endl;
    int location = i*digitSize;
    cout << "Giving a location of " << location << endl;
    
    //went through the whole string without not being beautiful
    if(location >= s.size() - 1){
        return true;
    }
    
    string number = s.substr(i*digitSize - increaseFactor,digitSize);
    cout << "Looking at " << number;
    int n = stoi(number);
    int nx = n + 1;
    string nextNumber = to_string(nx);
    int newDigitSize = nextNumber.size();
    
    if(newDigitSize > digitSize){
                increaseFactor += 1;
    }
    
    i++;
    location = newDigitSize*i - increaseFactor; //takes care if same or increasing by 1
    
    string actualNext = s.substr(location,newDigitSize);
    digitSize = newDigitSize;
    cout << ". Next number should be " << nextNumber << "\n";
    cout << "Next number actually is " << actualNext << endl;
    if(actualNext == nextNumber){
        cout << "Yes!\n";
        i++;
        if(checkNext(s, digitSize, i, increaseFactor)){
            return true;
        }
    }
    
    cout << "No...\n";
    return false;
    
 }

int main(){
    int q;
    cin >> q;
    
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        cout << "--Considering new number: " << s << "\n\n";
        bool continueLoop = true;
        int size = s.size();
        
        if(size == 1){
            cout << "NO\n";
            continue;
        }
        
        for(int digitSize = 1; digitSize <= size/2 + 1; digitSize++){
            
            //take in number, convert it to int, find next, convert back to string
            string number = s.substr(0,digitSize);
            int n = stoi(number);
            int nx = n + 1;
            string nextNumber = to_string(nx);
            int newDigitSize = nextNumber.size(); //update incase 99-->100, etc.        
            
            
            int increaseFactor = 0;
            if(newDigitSize > digitSize){
                increaseFactor += 1;
            }
            //actual next number in string
            string actualNext = s.substr(digitSize,newDigitSize);
        
            cout << "Looking at " << number << ". Next should be " << nextNumber << "\n";
            cout << "Actual next string number is " << actualNext << endl;
            
            if(nextNumber == actualNext){
                cout << "Found possible match with a digit size of " << digitSize << endl;
                if(digitSize + newDigitSize == size){
                    cout << "YES" << number << endl;
                    continueLoop = false;
                }
                
                else if(checkNext(s, newDigitSize, 1, increaseFactor)){
                    cout << "YES " << number << endl;
                    continueLoop = false;;
                }
            }
            
            if(!continueLoop){break;}
            else{
                cout << "No match found yet. New digitSize " << (digitSize + 1)<< endl;
            }
        }
        

        // your code goes here
    }
    return 0;
}
