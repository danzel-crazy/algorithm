#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdio>

int container[1000001];
using namespace std;

int main(){
    int m, n;
    while(scanf("%d%d",&m,&n)!=EOF){
        
        int left = 0, right = 0, mid;
        for(int i = 0 ; i < m; i++){
            cin >> container[i];
            if(container[i] > left) left = container[i];
            right += container[i];
        }
        
        while(left < right){
            mid = (left+right)/2;
            int index = 0, sum = 0;
            for(int i = 0; i < m; i++){
                sum += container[i];
                if(sum > mid){
                    index++;
                    sum = container[i];
                }
                else if(sum == mid){
                    index++;
                    sum = 0;
                }
            }

            if(sum) index++;
            if(index > n){
                left = mid+1;
            }
            else right = mid;
        }

        cout << left << endl;
    }
    return 0;
}