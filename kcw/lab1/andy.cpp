#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define ll long long

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    ll t;
    vector <ll> a;
    map <ll, int> c;
    cin >> n >> t;

    while(n--){
        ll val;
        cin >> val;
        c[val]++;
        if(c[val] <= 3) a.push_back(val);
    }

    sort(a.begin(), a.end());

    int gg = 0;
    bool have = false;

    ll pre, pre1, pre2;
    vector <ll> :: iterator i;
    for(i = a.begin(); i != a.end(); i = upper_bound(a.begin(), a.end(), *i)){
        auto second = distance(a.begin(), i) + 1; 
        auto third = a.size()-1;
        while(second < third){
            if(have && pre == *i && pre1 == a[second] && pre2 == a[third]){
                second++;
                third--;
            }
            else{
                if(a[second] + a[third] < (t - *i)){
                    second++;
                }
                else if(a[second] + a[third] > (t - *i)){
                    third--;
                }
                else{
                    pre = *i;
                    pre1 = a[second];
                    pre2 = a[third];
                    have = true;
                    gg++;
                    second++;
                    third--;
                }
            }
        }
    }

    if(gg == 0) cout << "FeiDooDoo_Zuo_Wei_Men";
    else cout << gg;

    return 0;
}
