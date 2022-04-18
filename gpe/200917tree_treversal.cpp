#include <stdio.h>
#include <stdlib.h>
#include <iostream>

char in[30];
char pre[30];
int preindex = 0;
using namespace std;

int search(char in[], int start, int end, char val){
    int ans = 0;
    for(int i = start; i <= end; i++){
        if(in[i] == val)
            return i;
    }
    return ans;
}

void postorder(char in[], char pre[], int left, int right){
    if(left > right){
        return;
    }

    int root = search(in, left, right, pre[preindex]); 
    preindex++;

    postorder(in, pre, left, root-1);

    postorder(in, pre, root+1, right);

    cout << in[root] << " ";
}

int main(){
    int n;
    cin >> n;
    while(n--){
        preindex = 0;
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> pre[i];
        }
        for(int i = 0; i < m; i++){
            cin >> in[i];
        }

        postorder(in, pre, 0, m-1);
        cout << "\n";
    }


    return 0;
}