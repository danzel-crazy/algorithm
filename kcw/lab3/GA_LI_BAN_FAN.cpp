#include <iostream>
#include <vector>

using namespace std;

long long remain(long long , vector <long long> &);
bool checkPay(vector<long long>& , long long );
vector<long long> value = {1000, 500, 100, 50, 10, 5, 1};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    long long t;
    long long sum;
    cin >> t;
    while(t--){
        bool check = false;
        long long num;
        cin >> num;
        vector<long long> money(7);
        vector <long long> coin(7,0);
        vector<long long> left(num, 0);
        for(int i = 0; i < num; i++){
            cin >> sum;
            for(int j = 0; j < 7; j++){
                cin >> money[j];
                coin[j] += money[j];
            }

            left[i] = remain(sum, money);
        }

        for(int j = 0; j < left.size(); j++){
            if(!checkPay(coin, left[j])){
                check = true;
                break;
            }
        }
        if(check) cout << "No\n";
        else cout << "Yes\n";
    }
    
    return 0;
}

long long remain(long long sum, vector <long long>& coin){
    long long total = 0;
    for(int i = 0; i < 7; i++){
        total += (value[i] * coin[i]);
    }
    return total - sum;
}

bool checkPay(vector<long long>& coin, long long left){
    // cout << left << "\n";
    for(int i = 0; i < 7; i++){
        long long temp = left / value[i];
        if(temp > coin[i]){
            left -= value[i]*coin[i];
            coin[i] = 0;
        }
        else{
            left -= value[i]*temp;          
            coin[i] -= temp;
        }

        if(left == 0) return true;
    }

    return false;
}