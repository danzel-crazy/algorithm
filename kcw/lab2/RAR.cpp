#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector <int> rotate_(vector <int> s, int k){
    rotate(s.begin(), s.begin()+k, s.end());
    return s;
}

vector <int> reverse_(vector <int> s){
    reverse(s.begin(), s.end());
    return s;
}

vector <int> add(vector <int> s, int k){
    for(int i = 0; i < s.size(); i++){
        s[i] += k;
    }
    return s;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector <int> ans;
    ans.push_back(1);

    vector <int> a, b, c;
    for(int i = 1; i <= n; i++){
        a = reverse_(ans);
        b = add(ans, pow(2,i-1));
        a.insert(a.end(), b.begin(), b.end());
        // for(auto i : a) cout << i << " ";
        // cout << "\n";
        ans = rotate_(a, pow(2,i-1));
        // for(auto i : ans) cout << i << " ";
        // cout << "\n";
    }

    for(auto i : ans) cout << i << " ";
    cout << "\n";
    return 0;
}