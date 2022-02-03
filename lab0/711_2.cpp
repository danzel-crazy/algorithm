#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define t long long

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    t order;
    cin >> order;
    unordered_map <t, vector <t>> b;
    t option;

    while(order--){
        cin >> option;
        t type, index;
        if(option == 1){
            cin >> type >> index;
            b[type].push_back(index);
            //sort(b[type].begin(), b[type].end(), greater<int>());
            //cout << type << " " << b[type] << endl;
        }
        else{
            cin >> type;
            if(b.find(type) == b.end()){
                cout << "-1" << "\n";
            }
            else{
                if(b[type].size() == 0){
                    cout << "-1" << "\n";
                }
                else{
                    //sort(b[type].begin(), b[type].end(), greater<int>());
                    auto place = b[type].begin();
                    t answer = b[type][0];
                    for(auto i = b[type].begin(); i != b[type].end(); i++){
                        //cout << *i << " ";
                        if(answer > *i) {
                            answer = *i;
                            place = i;
                        }
                    }
                    // auto i = b[type].end()-1;
                    // cout << *i <<"\n";
                    cout << answer << "\n";
                    b[type].erase(place);
                }
            }
        }
    }
    return 0;
}