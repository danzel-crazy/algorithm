#include <iostream>
#include <vector>


using namespace std;

int ans = 0;
vector <int> a;

int check(int start, int end, vector <int> &postorder, int &current, vector <int> &temp){
    if(start > end){
        return -1;
    }

    int value = postorder[current--];
    int index = temp[value];
    //cout << "value : " << index << "\n";
    if(index + 1 <= end){
        int right = check(index + 1, end, postorder, current, temp);
        if(right != -1){
            if(a[value-1] < a[right-1]) ans++;
        }
    }
    //cout << value << " " <<  "right: " << right << " \n";
    if(start <= index - 1){
        int left = check(start, index - 1, postorder, current, temp);
        if(left != -1){
            if(a[value-1] < a[left-1]) ans++;;
        }
    }
    //cout << value << " " << "left : " << left << "\n";

    return value;
} 

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
    cin >> n;
    a.resize(n);
    vector <int> in_order(n), post_order(n);
    vector <int> temp(n+1);

    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        a[i] = s;
    }

    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        temp[s] = i;
    }

    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        post_order[i] = s;
    }

    int index = n-1;
	int i = check(0, n - 1, post_order, index, temp);

    cout << ans << "\n";
    return 0;
}