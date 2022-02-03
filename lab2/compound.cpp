#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main(){
    char n;
    string com;
    map <string, int> sin;
    map <string, int> dou;
    queue <string> temp;

        if((n - 'A') >= 0 && (n - 'A') <= 26){
            com.push_back(n);
        }
        else if((n - 'a') >= 0 && (n - 'a') <= 26){
            com.push_back(n);
            temp.push(com);
            com.erase();
        }
        else if((n - '0') >= 0 && (n - '0') <= 9){
            if(temp.size() == 1){
                sin[temp.front()] = n - '0';
            }
            else{
                dou[com] = n - '0';
            }
            com.erase();
        }
        else if((n - '{') == 0){


        } 
}
