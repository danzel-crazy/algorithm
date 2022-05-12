#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef vector<int>::iterator iter;
void divide(iter, iter, long long int);
long long int move(iter, iter);

long long int minimum = 1ll<<62;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    vector<int> seq(num);
    for(int i = 0; i < num; i++){
        cin >> seq[i];
    }
    divide(seq.begin(), seq.end(), 0);
    cout << minimum << '\n';
}   

void divide(iter begin, iter end, long long int total){
    long long int count = 0;
    vector<int> temp;

    if(end - begin <= 2){
        if(total < minimum) minimum = total;
        return;
    }
    
    temp.insert(temp.begin(), begin + (end-begin-1)/2 + 1, end);
    nth_element(temp.begin(), temp.begin() + temp.size()/2, temp.end());  //quick select
    divide(begin, begin + (end-begin-1)/2 + 1, total + move(temp.begin(), temp.end() ) );
    temp.clear();

    temp.insert(temp.begin(), begin, begin + (end-begin-1)/2 + 1);
    nth_element(temp.begin(), temp.begin() + temp.size()/2, temp.end());
    divide(begin + (end-begin-1)/2 + 1, end, total + move(temp.begin(), temp.end()));
}

long long int move(iter begin, iter end){
    long long int count = 0;
    for(iter it = begin; it != end; it++){
        count += abs(*it - *(begin+(end-begin)/2));
    }
    return count;
}