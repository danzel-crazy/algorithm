#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int count = 0;
    int n;
    cin >> n;
    while(n--){
        count = 0;
        map <float, vector<pair<float,float>>> lines;
        set <float> straight;
        vector <pair<float,float>> dot;
        int num;
        float a, b;
        cin >> num;
        for(int i = 0; i < num; i++){
            cin >> a >> b;
            dot.push_back(make_pair(a,b));
        }
        
        for(int i = 0; i < num; i++){
            for(int j = i+1; j < num; j++){
                if((dot[j].first - dot[i].first) == 0) {
                    if(!straight.count(dot[j].first)){
                        straight.insert(dot[j].first);
                        // cout << "0" << dot[j].first << "\n";
                        count++;
                    }
                    continue;
                }

                float slope =  (dot[j].second - dot[i].second) / (dot[j].first - dot[i].first);
                if(lines.find(slope) == lines.end()){
                    pair<int,int> a = make_pair(dot[i].first, dot[i].second);
                    lines[slope].push_back(a);
                    // cout << slope << a.first << " " << a.second << "\n";
                    count++;
                }
                else{
                    bool good = 1;
                    for(auto z : lines[slope]){
                        float temp =  (float)(z.second - dot[j].second)/ (z.first - dot[j].first);
                        if(temp == slope) {
                            good = 0;
                            break;
                        }
                    }
                    
                    if(good) {
                        lines[slope].push_back(make_pair(dot[i].first, dot[i].second));
                        // cout << slope << dot[i].first << " " << dot[i].second << "\n";
                        count++;
                    }
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}