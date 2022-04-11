#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
    int dollar[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
    long long int dp[30005];
    int a, b;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < 11; i++){
        for(int j = dollar[i]; j <= 30000; j += 5){
            dp[j] += dp[j-dollar[i]];
        }   
    }
    
    while(scanf("%d.%d", &a, &b) != EOF && !(a == 0 && b == 0)){
        printf("%3d.%02d%17lld\n", a, b, dp[a*100+b]);
    }
    return 0;
}