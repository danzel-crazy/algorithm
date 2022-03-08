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
        for(int i = 0; a[i] <= n; i++){
            int temp = 0;
            for(int j = i; temp < n; j++){
                temp += a[j];
                if(temp == n){
                    tt++;
                }
            }
        }
        printf("%d\n", tt);
    }
    return 0;
}