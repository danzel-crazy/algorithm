#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

#define int long long

signed main(){
    int num, limit, time;
    int ans = 0;
    cin >> num >> limit >> time;
    vector <int> a;

    while(num--){
        int val;
        cin >> val;
        a.push_back(val);
    }

    sort(a.begin(), a.end(), greater <int>());
    
    int first = 0, end = a.size() - 1;

    while(first <= end){
        if(a[first] + a[end] <= limit){
            //cout << "first " << first << "second " << end << endl;
            ans += time * 2;
            first += 1;
            end -= 1;
        }
        else{
            first += 1;
            //cout << "first " << first << endl;
            ans += time * 2;
        }
    }   

    cout << ans << endl;
    return 0;
}