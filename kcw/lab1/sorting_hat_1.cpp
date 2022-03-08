#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std; 

int compare[4][4];

class Student{
    public:
        string name;
        int rank[4];
        int max = 0;

        void findLargest();
};

void Student::findLargest(){
    for(int i = 1; i < 4; i++){
        if(this->rank[i] > this->rank[this->max])
            this->max = i;
    }
}

class COMP{
    public:
        bool operator()(Student& st1, Student& st2){
            for(int i = 0; i < 4; i++){
                if(st1.rank[compare[st1.max][i]] != st2.rank[compare[st2.max][i]])
                    return st1.rank[compare[st1.max][i]] > st2.rank[compare[st2.max][i]];
            }
            return st1.name < st2.name;
        }
}comp;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<Student> subHouse;
    int num;
    string seq;
    Student st;

    cin >> num;
    vector<vector<Student>> House(num, subHouse);

    for(int i = 0; i < 4; i++){
        cin >> seq;
        for(int j = 0; j < 4; j++){
            switch(seq[j]){
                case 'G':
                    compare[i][j] = 0;
                    break;
                case 'H':
                    compare[i][j] = 1;
                    break;
                case 'R':
                    compare[i][j] = 2;
                    break;
                case 'S':
                    compare[i][j] = 3;
                    break;
            }
        }
    }

    for(int i = 0; i < num; i++){
        cin >> st.name;
        st.max = 0;
        cin >> st.rank[0] >> st.rank[1] >> st.rank[2] >> st.rank[3];
        st.findLargest();
        House[st.max].push_back(st);
    }

    for(int i = 0; i < 4; i++){
        sort(House[i].begin(), House[i].end(), comp);
    }

    // --------------------------------------------------//
    cout << "GRYFFINDOR: ";
    if(House[0].empty())
        cout << "NO NEW STUDENTS" << '\n';
    else{
        cout << '\n';
        for(int i = 0; i < House[0].size(); i++){
            cout << House[0][i].name << '\n';
        }
    }
    // --------------------------------------------------//
    cout << "HUFFLEPUFF: ";
    if(House[1].empty())
        cout << "NO NEW STUDENTS" << '\n';
    else{
        cout << '\n';
        for(int i = 0; i < House[1].size(); i++){
            cout << House[1][i].name << '\n';
        }
    }
    // --------------------------------------------------//
    cout << "RAVENCLAW: ";
    if(House[2].empty())
        cout << "NO NEW STUDENTS" << '\n';
    else{
        cout << '\n';
        for(int i = 0; i < House[2].size(); i++){
            cout << House[2][i].name << '\n';
        }
    }
    // --------------------------------------------------//
    cout << "SLYTHERIN: ";
    if(House[3].empty())
        cout << "NO NEW STUDENTS" << '\n';
    else{
        cout << '\n';
        for(int i = 0; i < House[3].size(); i++){
            cout << House[3][i].name << '\n';
        }
    }
}