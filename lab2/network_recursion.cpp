#include <iostream>
#include <vector>

#define mod 1000000007
#define int long long

using namespace std;

int treversal(vector <int> &a, vector <pair <int,int>> &out, int current){
    if(out[current].first == -1 && out[current].second == -1) return a[current];
    else{
        return ((treversal(a, out, out[current].first) + treversal(a, out, out[current].second)) * a[current]) % mod;
    }
}

signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector <int> a;
    vector <pair <int,int>> out;
    for(int i = 0 ; i < n; i++){
        int c;
        cin >> c;
        a.push_back(c);
        out.push_back(make_pair(-1,-1));
    }
    
    // for(int i = 0 ; i < n; i++) cout << a[i] << " ";
    // cout << "\n";
    for(int i = 1; i <= n-1; i++){
        int o;
        cin >> o;
        if(out[o-1].first == -1){
            out[o-1].first = i;
        }
        else{
            out[o-1].second = i;
        }
    }

    //for(int i = 0; i < n; i++) cout << out[i].first << " " << out[i].second << "\n";

    int ans = treversal(a, out, 0);    
    cout << ans << "\n";
    return 0;
}
