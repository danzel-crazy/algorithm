#include <iostream>
#include <map>
#include <iomanip>
#include <vector>

#define t long long

using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    t range;
    long double val;
    bool check = false;

    cin >> n;

    vector <pair<t, long double>> a;

    while(n--){
        cin >> range >> val;
        a.push_back(make_pair(range-1,val));
    }

    cin >> n;
    t income;
    while(n--){
        long double answer = 0.0;
        check = false;
        cin >> income;

        pair<t,long double> last(0,0);
        for(auto i = a.begin(); i != a.end(); i++){
            if(income >= i->first){
                answer += (i->first - last.first) * last.second;
            }
            else{
                answer += (income - last.first) * last.second;
                break;
            }
            last.first = i->first;
            last.second = i->second;
        }
        if(income >= a[a.size()-1].first){
            answer += (income-a[a.size()-1].first) * a[a.size()-1].second;
        }

        cout << setprecision(6) << fixed << answer << "\n";
    }
    return 0;
}