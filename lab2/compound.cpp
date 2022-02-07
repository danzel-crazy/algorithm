#include <iostream>
#include <map>
#include <stack>

#define int long long

using namespace std;

char* check(string& com, char* current, int time, map<string, int>& sin, map<string, int>& dou){
    int base = 1, count = 0;
    string temp;
    while(true){
        //cout << current << "\n";
        if(*current == '('){
            return current;
        }
        else if(*current == ')'){
            if(count == 0){
                current = check(com, current-1, time, sin, dou);
            }
            else{
                current = check(com, current-1, time*count, sin, dou);
            }
            count = 0;
            base = 1;
        }
        else if((*current - 'A') >= 0 && (*current - 'A') <= 25){
            temp.insert(temp.begin(), *current);
            if(temp.size() == 1){
                if(count == 0){
                    sin[temp] += time;
                    //cout << temp << "sin0:" << sin[temp] << "\n";
                }
                else{
                    //cout << "count:" << count << "\n";
                    sin[temp] += time*count;
                    //cout << temp << "sin:" << sin[temp] << "\n";
                }
            }
            else if(temp.size() == 2){
                if(count == 0){
                    dou[temp] += time;
                    //cout << temp << "dou0:" << dou[temp] << "\n";
                }
                else{
                    dou[temp] += time*count;
                    //cout << temp << "dou:" << dou[temp] << "\n";
                }
            }
            count = 0;
            base = 1;
            temp = "";
        }
        else if((*current - 'a') >= 0 && (*current - 'a') <= 25){
            temp.insert(temp.begin(), *current);
        }
        else if((*current - '0') >= 0 && (*current - '0') <= 9){
            count += (*current - '0') * base;
            //cout << count << "\n";
            base *= 10;
        }

        if(current == &com[0]){
            return current;
        }
        else current--;
    }
}

signed main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    
    string com, temp = "";
    
    map <string, int> sin;
    map <string, int> dou;
    
    cin >> com;
    char* current = &com[com.size()-1];

    current = check(com, current, 1, sin, dou);

    cout << sin.size() << "\n";
    for(auto i : sin){
        cout << i.first << ":" << i.second << "\n";
    }
    cout << dou.size() << "\n";
    for(auto i : dou){
        cout << i.first << ":" << i.second << "\n";
    }
    return 0;
}