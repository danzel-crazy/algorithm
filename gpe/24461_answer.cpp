#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10000+5;
int p[maxn];
vector <int> v;
 
int main() {
    for (int i = 2; i < maxn; i++){
        if (p[i] == 0){
            for (int j = i+i; j < maxn; j+=i){
                p[j] = 1;
            }
            v.push_back(i);
        }
    }
    int n;
    while (cin >> n){
        if (n == 0) break;
        int cnt = 0;
        for (int i = 0; v[i] <= n; i++){
            int sum = 0;
            for (int j = i; sum < n; j++){
                sum += v[j];
                if (sum == n) {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}