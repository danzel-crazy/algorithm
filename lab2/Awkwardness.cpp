#include <iostream>
#include <vector>
#define int long long
using namespace std;

int ans = 0;
vector <int> a;
vector <int> in_order, post_order;
vector <int*> temp;

void check(int *in_start, int *in_end, int *po_start, int *post_end){
    if(in_start == in_end){
        return;
    }

    int *root = temp[*post_end];
    int right = in_end - root;
    int left = root - in_start;

    if(right != 0){
        int *right_root = post_end - 1;
        if(a[*root-1] < a[*right_root-1]){
            ans++;
        }
        check(root + 1, in_end, po_start + left, post_end - 1);
    }
    if(left != 0){
        int *left_root = po_start + left - 1;
        if(a[*root-1] < a[*left_root-1]){
            ans++;
        }
        check(in_start, root - 1, po_start, po_start + left - 1);
    }
}

signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
    cin >> n;

    a.resize(n);
    in_order.resize(n);
    post_order.resize(n);
    temp.resize(n+1);

    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        a[i] = s;
    }

    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        in_order[i] = s;
        temp[s] = &in_order[i];
    }

    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        post_order[i] = s;
    }

    check(&in_order[0], &in_order[n-1], &post_order[0], &post_order[n-1]);

    cout << ans << "\n";
    return 0;
}