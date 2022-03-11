#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
    int ans;
    int n;
    cin >> n;
    while(n--){
        vector <int> pos;
        ans = 0;
        int t;
        cin >> t;
        while(t--){
            string s;
            cin >> s;
            if(s == "LEFT"){
                ans -= 1;
                pos.push_back(-1);
            }
            else if(s == "RIGHT"){
                ans += 1;
                pos.push_back(1);
            }
            else if(s == "SAME"){
                string as;
                int i;
                cin >> as >> i;
                ans += pos[i-1];
                //cout << "ans: " << ans << endl;
                pos.push_back(pos[i-1]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}