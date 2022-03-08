#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    long long a = 1000000007;
    vector <int> temp;

    int n;
    cin >> n;
    int max = n;
    while(n--){
        int a;
        cin >> a;
        temp.push_back(a);
    }

    
    sort(temp.begin(), temp.end());
    
    long long sum = 1;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] > max){
            temp[i] = max;
            int ans =  temp[i] - i;
            sum = (sum * ans) % a;
        } 
        else{
            long long ans =  temp[i] - i;
            sum = (sum * ans) % a;
        }
    }

    cout << sum << endl;
    return 0;
}