#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> hh(4);

struct student{
    string name;
    int color[4];
    //student(string name, vector <int> s) : name(name), color(s){}
};
int state;

int check(char c) {
    switch (c) {
        case 'G':
            return 0;
            break;
        case 'H':
            return 1;
            break;
        case 'R':
            return 2;
            break;
        case 'S':
            return 3;
            break;
    }
}

bool compare0(student &a, student &b){
    int ch[4];
    ch[0] = check(hh[0][0]), ch[1] = check(hh[0][1]),ch[2] = check(hh[0][2]),ch[3] = check(hh[0][3]);
    if(a.color[ch[0]] != b.color[ch[0]]){
        return a.color[ch[0]] > b.color[ch[0]];
    }
    else if(a.color[ch[1]] != b.color[ch[1]]){
        return a.color[ch[1]] > b.color[ch[1]];

    }
    else if(a.color[ch[2]] != b.color[ch[2]]){
        return a.color[ch[2]] > b.color[ch[2]];
    }
    else if(a.color[ch[3]] != b.color[ch[3]]){
        return a.color[ch[3]] > b.color[ch[3]];
    }
    else{
        for(int i = 0;; i++){
            if(a.name[i] != b.name[i]){
                return (int)a.name[i] < (int)b.name[i];
                break;
        }
        }
    }
}

bool compare1(student &a, student &b){
    int ch[4];
    ch[0] = check(hh[1][0]), ch[1] = check(hh[1][1]),ch[2] = check(hh[1][2]),ch[3] = check(hh[1][3]);
    if(a.color[ch[0]] != b.color[ch[0]]){
        return a.color[ch[0]] > b.color[ch[0]];
    }
    else if(a.color[ch[1]] != b.color[ch[1]]){
        return a.color[ch[1]] > b.color[ch[1]];

    }
    else if(a.color[ch[2]] != b.color[ch[2]]){
        return a.color[ch[2]] > b.color[ch[2]];
    }
    else if(a.color[ch[3]] != b.color[ch[3]]){
        return a.color[ch[3]] > b.color[ch[3]];
    }
    else{
        for(int i = 0;; i++){
            if(a.name[i] != b.name[i]){
                return (int)a.name[i] < (int)b.name[i];
                break;
            }
        }
    }
}

bool compare2(student &a, student &b){
    int ch[4];
    ch[0] = check(hh[2][0]), ch[1] = check(hh[2][1]),ch[2] = check(hh[2][2]),ch[3] = check(hh[2][3]);
    if(a.color[ch[0]] != b.color[ch[0]]){
        return a.color[ch[0]] > b.color[ch[0]];
    }
    else if(a.color[ch[1]] != b.color[ch[1]]){
        return a.color[ch[1]] > b.color[ch[1]];

    }
    else if(a.color[ch[2]] != b.color[ch[2]]){
        return a.color[ch[2]] > b.color[ch[2]];
    }
    else if(a.color[ch[3]] != b.color[ch[3]]){
        return a.color[ch[3]] > b.color[ch[3]];
    }
    else{
        for(int i = 0;; i++){
            if(a.name[i] != b.name[i]){
                return (int)a.name[i] < (int)b.name[i];
                break;
        }
    }
    }
}

bool compare3(student &a, student &b){
    int ch[4];
    ch[0] = check(hh[3][0]), ch[1] = check(hh[3][1]),ch[2] = check(hh[3][2]),ch[3] = check(hh[3][3]);
    if(a.color[ch[0]] != b.color[ch[0]]){
        return a.color[ch[0]] > b.color[ch[0]];
    }
    else if(a.color[ch[1]] != b.color[ch[1]]){
        return a.color[ch[1]] > b.color[ch[1]];
    }
    else if(a.color[ch[2]] != b.color[ch[2]]){
        return a.color[ch[2]]> b.color[ch[2]];
    }
    else if(a.color[ch[3]] != b.color[ch[3]]){
        return a.color[ch[3]] > b.color[ch[3]];
    }
    else{
        for(int i = 0;; i++){
            if(a.name[i] != b.name[i]){
                return (int)a.name[i] < (int)b.name[i];
                break;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    vector <string> hou_nam = {"GRYFFINDOR", "HUFFLEPUFF", "RAVENCLAW", "SLYTHERIN"};
    int n;

    
    cin >> n;
    cin >> hh[0] >> hh[1] >> hh[2] >> hh[3];
    vector <vector <student>> house;
    house.resize(4);
    while(n--){
        student s;
        cin >> s.name;
        int h = 0;
        int cur = -1;
        for(int i = 0 ; i < 4; i++){
            cin >> s.color[i];
            if(cur == -1){
                cur = s.color[i];
                h = 0;
            }
            else if(s.color[i] > cur) {
                cur = s.color[i];
                h = i;
            }
        }
        house[h].push_back(s);
    }

    // for(int i = 0; i < 4; i++){
    //     if(!house[i].size()){
    //         cout << hou_nam[i] << ": NO NEW STUDENTS" << "\n";
    //     }
    //     else{
    //         state = i;
    //         sort(house[i].begin(), house[i].end(), compare);
    //         cout << hou_nam[i] << ":" <<"\n";
    //         for(auto s : house[i]){
    //             cout << s.name << "\n";
    //         }
    //     }
    // }

    if(!house[0].size()){ 
        cout << "GRYFFINDOR: NO NEW STUDENTS" << '\n';
    }
    else{
        sort(house[0].begin(), house[0].end(), compare0);
        cout << "GRYFFINDOR:" << '\n';
        for(auto s : house[0]){
            cout << s.name << '\n';
        }
    }
    if(!house[1].size()){
        cout << "HUFFLEPUFF: NO NEW STUDENTS" << '\n';
    }
    else{
        sort(house[1].begin(), house[1].end(), compare1);
        cout << "HUFFLEPUFF:" << '\n';
        for(auto s : house[1]){
            cout << s.name << '\n';
        }
    }
    if(!house[2].size()){
        cout << "RAVENCLAW: NO NEW STUDENTS" << '\n';
    }
    else{
        sort(house[2].begin(), house[2].end(), compare2);
        cout << "RAVENCLAW:" << '\n';
        for(auto s : house[2]){
            cout << s.name << '\n';
        }
    }
    if(!house[3].size()){
        cout << "SLYTHERIN: NO NEW STUDENTS" << '\n';
    }
    else{
        sort(house[3].begin(), house[3].end(), compare3);
        cout << "SLYTHERIN:" << '\n';
        for(auto s : house[3]){
            cout << s.name << '\n';
        }
    }
    return 0;
}