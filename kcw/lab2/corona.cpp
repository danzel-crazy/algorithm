#include <iostream>
#include <vector>

#define m 1000000007
#define int long long

using namespace std;

int powxy(int x, int y) {
    if (y == 0) return 1;
    if (y%2 == 1) return (x*powxy(x, y-1))% m;
    int t = powxy(x, y/2);
    return (t*t) % m;
}

signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, n;
    cin >> a >> b >> n;
    
    
    while(n--){
        int i;
        cin >> i;   
        int an = powxy(a,i-1);
        int ans = (an + ((an-1) * (b/(a-1)))% m) % m;
        if(ans < 0) ans = ans + (1e9+7);
        cout << ans << "\n";
    }
    return 0;
}