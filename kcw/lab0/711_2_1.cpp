#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int order;
    cin >> order;
    map <int ,priority_queue <int, vector <int>, greater<int>>> a;

    int option;
    
    while(order--){
        cin >> option;
        int type, index;
        if(option == 1){
            cin >> type >> index;
            a[type].push(index);
        }
        else{
            cin >> type;
            if(a[type].size() != 0){
                cout << a[type].top() << "\n";
                a[type].pop();
            }
            else{
                cout << -1 << "\n";
            }
            
        }
    }
    return 0;
}