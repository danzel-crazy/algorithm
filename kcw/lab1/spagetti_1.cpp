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
            if(len == x*(i+1)){
                auto first = lower_bound(start, end, x*i)-a.begin();
                auto second = upper_bound(start, end, len-1)-a.begin();
                aaa += (second-first) * i;

                auto third = upper_bound(start, end, len)-a.begin();
                aaa += (third-second) * (i+1);
                //cout << "3: " << first << " " << second << " " << third << "\n";
                break; 
            }
            else if(len > x*(i+1)){
                auto first = lower_bound(start, end, x*i)-a.begin();
                auto second = upper_bound(start, end, x*(i+1)-1)-a.begin();
                aaa += (second-first) * i;
                //cout << "1: " << first << " " << second << "\n";
            }       
            else if(len < x*(i+1)){
                auto first = lower_bound(start, end, x*i)-a.begin();
                auto second = upper_bound(start, end, len)-a.begin();
                aaa += (second-first) * i;
                //cout << "2: " << first << " " << second << "\n";
                break;
            }
            //cout << aaa << endl;
        }
        cout << aaa << "\n";
    }
    return 0;
}