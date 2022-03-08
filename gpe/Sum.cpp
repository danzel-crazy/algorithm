#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std; 

vector <int> a;

int main(){
    a.push_back(2);
    a.push_back(3);
    for(int i = 4; i < 10000; i++){
        bool prime = true;
        for(int j = 0; j < a.size(); j++){
            if(i % a[j] == 0){
                prime = false;
                break;
            }
        }
        if(prime) a.push_back(i);
    }
    // for(auto i : a) cout << i << " ";
    // cout << endl;
    int n;
    while(cin >> n){
        if(n == 0) break;
        int tt = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] > n) break;
            int temp = 0;
            for(int j = i; j < a.size(); j++){
                if(temp > n) break;
                else if(temp == n){
                    tt++;
                    break;
                }
                else temp += a[j];
            }
        }
        printf("%d\n", tt);
    }
    return 0;
}