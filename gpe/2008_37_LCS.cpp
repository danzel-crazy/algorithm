#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
vector <int> lcs;
int c;

void print_LIS(vector <int> a, int dp[], int i, int max){
    if (dp[i] == 1) {
        c += 1;
        // /scout << a[i] << " ";
        lcs.push_back(a[i]);
        return;
    }

    for (int j = (i+1); j < a.size(); ++j)
        if (a[j] > a[i])
            if (dp[j] == (dp[i] + 1)){
                    // cout << a[j] << " ";
                    print_LIS(a, dp, j, max);
                    lcs.push_back(a[i]);
                    // cout << a[i] << " ";
            }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        lcs.clear();
        c = 0;
        int max = -1;
        vector <int> a;
        int dp[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        int len;
        cin >> len;
        for(int i = 0; i < len; i++){
            int val;
            cin >> val;
            a.push_back(val);
        }    

        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
                if(a[i] > a[j] && dp[i] < (dp[j]+1)){
                    dp[i] = (dp[j]+1);
                }
            }
        }
        // for(int i = 0; i < len; i++){
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";

        for(int i = 0; i < len; i++){
            if(dp[i] > max) max = dp[i];
        }
        for (int i=0; i< len; i++)
            if (dp[i] == 1)
                print_LIS(a, dp, i, max);
        
        cout << c << "\n";
        for(int i = 0; i < lcs.size(); i++){
            if(((i+1) % max) == 0){
                cout << lcs[i];
                cout << "\n";
            }
            else cout << lcs[i] << " ";
        }
    }

    return 0;
}