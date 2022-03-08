#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    long a = pow(10, 9) + 7;
    stack <long> count;
    string c;

    while((cin >> c)){

        if(!c.compare("+")){
            long first, second, ans;
            
            first = count.top();
            count.pop();
            second = count.top();
            count.pop();

            ans = (first + second ) % a;
            count.push(ans);

        }
        else if(!c.compare("*")){
            long first, second, ans;
            
            first = count.top();
            count.pop();
            second = count.top();
            count.pop();

            ans = (first * second) % a;
            count.push(ans);
        }
        else{
            long temp = stol(c);
            count.push(temp);

        }
    }

    cout << count.top();
    return 0;
}