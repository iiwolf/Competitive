#include <bits/stdc++.h>

using namespace std;

int twinArrays(vector <int> ar1, vector <int> ar2){
    int min = ar1[0] + ar2[1];
    
    for (int i = 0; i < ar1.size(); i++){
        for(int j = 0; j < i; j++){
            if(ar1[i] + ar2[j] < min){
                min = ar1[i] + ar2[j];
            }        
        }
        for(int j = i + 1; j < ar2.size(); j++){
            if(ar1[i] + ar2[j] < min){
                min = ar1[i] + ar2[j];
            }      
        }
    }
    
    return min;
}

int twinArrays(vector <int> ar1, vector <int> ar2){
    int min = ar1[0] + ar2[1];
    vector<int> save1, save2;
    save1 = ar1;
    save2 = art2;
    
    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());
    
    for (int i = 0; i < save1.size(); i++){
        if(ar[0] == save1[i]){
            index1 = i;
            
            for(int j = 0; j < )
        }
        
    }
    
    return min;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar1(n);
    for(int ar1_i = 0; ar1_i < n; ar1_i++){
       cin >> ar1[ar1_i];
    }
    vector<int> ar2(n);
    for(int ar2_i = 0; ar2_i < n; ar2_i++){
       cin >> ar2[ar2_i];
    }
    int result = twinArrays(ar1, ar2);
    cout << result << endl;
    return 0;
}
