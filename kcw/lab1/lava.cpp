#include <iostream>
#include <vector>
#include <map>

#define int long long

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;
    map <int, int> a;
    for(int i = 0; i < n; i++){
        int c, p;
        cin >> c >> p;
        a[c] = p;
    }
    
    return 0;
}