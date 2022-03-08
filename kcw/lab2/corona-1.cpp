#include <iostream>
#include <vector>
#include <bitset>

#define m 1000000007
#define int long long

using namespace std;
signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, q;
    int n;
    cin >> a >> b >> q;

    vector<int> num(100);
    num[0] = a;
    for(int i = 1; i < 64; i++){
        num[i] = (num[i-1] * num[i-1]) % m;    
    }

    for(int i = 0; i < q; i++){
        int ans = 1;
        cin >> n;
        bitset<64> bin(n - 1);
        for(int j = 0; j < bin.size(); j++){
            if(bin[j])
                ans = (ans * num[j]) % m;
        }
        ans = (ans + ((ans - 1) * (b/(a-1))) % m ) % m;
        if(ans < 0)
            ans = ans + m;
        cout << ans << '\n';
    }
}