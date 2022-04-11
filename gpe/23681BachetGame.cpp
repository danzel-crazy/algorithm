#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
int a[11];
bool dp[1000001];

int main()
{
    int n,m;
    while(cin >> n)
    {
        cin >> m;
        for(int i=0; i<m; i++)scanf("%d",&a[i]);
        dp[0]=0;
        for(int i=1; i<=n; i++)
        {
            dp[i]=0;
            for(int j=0; j<m; j++)
            {
                if(i>=a[j]&&dp[i-a[j]]==0)
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        if(dp[n])puts("Stan wins");
        else
            puts("Ollie wins");
    }
    return 0;
}