#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct section
{
    int left;
    int right;
};

bool compare(section a, section b)
{
    if(a.left != b.left)
        return a.left < b.left;
    else return a.right > b.right;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int num, fee;
    int ans = 0;
    cin >> num >> fee;

    section goal;
    cin >> goal.left >> goal.right;
    vector <section> line;
    vector <section> final;

    for(int i = 0; i < num; i++)
    {
        section temp;
        cin >> temp.left >> temp.right;
        if(temp.left < goal.right && temp.right > goal.left){
            line.push_back(temp);
        }
    }

    sort(line.begin(), line.end(), compare);
    
    for(int i = 1; i < line.size(); i++)
    {
        if(line[i].left > goal.left && line[i-1].left > goal.left){
            cout << 0;
            return 0;
        }

        if(line[i].left > goal.left){
            goal.left = line[i-1].right;
            // cout << goal.left << endl;
            ans += 1;
        }
    }

    if(goal.left < goal.right){
        if(line[line.size()-1].left <= goal.left && line[line.size()-1].right >= goal.right){
            ans++;
            goal.left = line[line.size()-1].right;
        }
    }

    if(goal.left < goal.right) cout << 0;
    else cout << fee * ans;
    return 0;
}