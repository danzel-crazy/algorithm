#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int num, order;
    cin >> num >> order;
    unordered_map <int, vector <int>> b;
    int option;

    while(order--){
        cin >> option;
        int type, index;
        if(option == 1){
            cin >> type >> index;
            b[type].push_back(index);
        }
        else{
            cin >> type >> index;
            if(b[type].size() < index + 1){
                cout << "-1" << "\n";
            }
            else{
                cout << b[type][index] << "\n";
            }
        }
    }
    return 0;
}