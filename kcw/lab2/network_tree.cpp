#include <iostream>
#include <vector>

#define mod 1000000007
#define int long long

using namespace std;

class node{
    public:
        node* left = NULL;
        node* right = NULL;
        int val;

        int treversal(){
            if(this->left == NULL && this->right == NULL) return this->val;
            else{
                return (((this->left->treversal()) + (this->right->treversal())) * this->val) % mod;
            }
        }
};

signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector <node *> a;
    for(int i = 0 ; i < n; i++){
        node* n = new node;
        int c;
        cin >> c;
        n->val = c;
        a.push_back(n);
    }
    
    // for(int i = 0 ; i < n; i++) cout << a[i] << " ";
    // cout << "\n";
    for(int i = 1; i <= n-1; i++){
        int o;
        cin >> o;
        if(a[o-1]->left == a[o-1]->right){
            a[o-1]->left = a[i];
        }
        else{
            a[o-1]->right = a[i];
        }
    }

    //for(int i = 0; i < n; i++) cout << out[i].first << " " << out[i].second << "\n";
    cout << a[0]->treversal() << "\n";
    return 0;
}