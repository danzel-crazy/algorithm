#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef vector<int>::iterator it;
int traverse(vector<int>&, it, it, it, it, vector<it>&);
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int num, temp;
    cin >> num;
    vector<int> stat(num), inOr(num), postOr(num);
    vector<it> ptr(num+1); 

    for(int i = 0; i < num; i++)
        cin >> stat[i];
    for(int i = 0; i < num; i++){
        cin >> inOr[i];
        ptr[inOr[i]] = inOr.begin()+i;
    }
    for(int i = 0; i < num; i++){
        cin >> temp;
        postOr[i] = *ptr[temp];
    }
    cout << traverse(stat, inOr.begin(), inOr.end(), postOr.begin(), postOr.end(), ptr) << '\n';
}

int traverse(vector<int>& stat, it ib, it ie, it pb, it pe, vector<it>& ptr){
    if(ie - ib == 1)
        return 0;
    
    int root = *(pe-1);
    // int* rt = vector[1]
    it rootIn = ptr[root];  
    it leftRoot, rightRoot;
    if(rootIn - ib == 0){
        rightRoot = pe-2;
        return (stat[*rightRoot-1] > stat[root-1]) + traverse(stat, rootIn+1, ie, pb, rightRoot+1, ptr);
    }else if(ie - rootIn - 1 == 0){
        leftRoot = pe-2;
        return (stat[*leftRoot-1] > stat[root-1]) + traverse(stat, ib, rootIn, pb, leftRoot+1, ptr);
    }else{
        leftRoot = pb + (rootIn - ib) - 1;
        rightRoot = pe-2;
        return (stat[*rightRoot-1] > stat[root-1]) + (stat[*leftRoot-1] > stat[root-1]) + traverse(stat, ib, rootIn, pb, leftRoot+1, ptr) + traverse(stat, rootIn+1, ie, leftRoot+1, rightRoot+1, ptr);
    }  
}