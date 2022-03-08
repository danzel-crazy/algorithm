#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    map <int, int> temp;

    int n, m;
    cin >> n >> m;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        temp[val] = i;
    }

    while(m--){
        int num;
        cin >> num;
        if(temp.find(num) != temp.end()){
            cout << temp[num] << endl;
        }
        else cout << "-1" << endl;
    }

    return 0;
}