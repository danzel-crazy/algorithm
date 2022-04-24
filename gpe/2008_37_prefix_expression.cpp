#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string temp;
    while(getline(cin, temp) && temp[0] != '.'){
        // cout << temp.size() << endl;
        stack <int> prefix;
        int ans;
        int n = 0;
        int time = 1;
        for(int i = temp.size()-1; i >= 0; i--){
            if(temp[i] == '+'){
                int first = prefix.top();
                prefix.pop();
                if(prefix.size() == 0) break;
                int second = prefix.top();
                prefix.pop();

                ans = first + second;
                // cout << ans << endl;
                prefix.push(ans);
            }
            else if(temp[i] == '/'){
                int first = prefix.top();
                prefix.pop();
                if(prefix.size() == 0) break;
                int second = prefix.top();
                prefix.pop();

                ans = first / second;
                //cout << ans << endl;
                prefix.push(ans);
            }
            else if(temp[i] == '*'){
                int first = prefix.top();
                prefix.pop();
                if(prefix.size() == 0) break;
                int second = prefix.top();
                prefix.pop();

                ans = first * second;
                // cout << ans << endl;
                prefix.push(ans);
            }
            else if(temp[i] == '%'){
                int first = prefix.top();
                prefix.pop();
                if(prefix.size() == 0) break;
                int second = prefix.top();
                prefix.pop();

                ans = first % second;
                // cout << ans << endl;
                prefix.push(ans);
            }
            else if(temp[i] == '-'){
                int first = prefix.top();
                prefix.pop();
                if(prefix.size() == 0) break;
                int second = prefix.top();
                prefix.pop();

                ans = first - second;
                // cout << ans << endl;
                prefix.push(ans);
            }
            else if(temp[i] == ' '){
                if(n != 0){
                    // cout << n << endl;
                    prefix.push(n);
                    n = 0;
                    time = 1;
                }
            }
            else if((temp[i]-'0') >= 0 && (temp[i]-'0') <= 9){
                n = (temp[i]-'0') * time + n;
                time*=10;
            }
        }

        if(prefix.size() == 1){
            cout << ans << "\n";
        }
        else{
            cout << "illegal\n";
        }
    }
}