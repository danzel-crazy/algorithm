#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector <int> a;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        a.push_back(v);
    }
    sort(a.begin(), a.end());
    // for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    // cout << endl;
    int q;
    cin >> q;
    int x, len;
    while(q--){
        cin >> x >> len;
        int aaa = 0;
        auto start = lower_bound(a.begin(), a.end(), x);
        int max = (x*k) > len ? len : x*k;
        auto end = upper_bound(a.begin(), a.end(), max);
        for(int i = 1; i <= k && x*i <= len; i++){
            auto first = lower_bound(start, end, x*i);
            auto second = upper_bound(start, end, x*(i+1)-1);
            aaa += (second-first) *i;
            //cout << aaa << endl;
        }
        cout << aaa << "\n";
    }
    return 0;
}