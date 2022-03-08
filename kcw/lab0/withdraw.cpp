#include <iostream>
#include <vector>
#include <queue>

#define t long long

using namespace std;

struct  student
{
    t id;
    t value;
    student(t id_, t val_){
        id = id_;
        value = val_;
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    queue <student> b;
    t n;
    cin >> n;

    int end = n;
    t num, like;
    while(n--){
        cin >> num >> like;
        b.push(student(num,like));
    }

    while(!b.empty()){
        if(b.front().value > 0){
            cout << b.front().id << "\n";
            student temp(b.front().id, b.front().value-1);
            b.pop();
            b.push(temp);
        }
        else{
            b.pop();
        }
    }
    return 0;
}