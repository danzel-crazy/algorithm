#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int ans = 0;
vector <int> a;

struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

Node* construct(int start, int end,
				vector<int> const &postorder, int &pIndex,
				unordered_map<int, int> &map)
{
	
	if (start > end) {
		return nullptr;
	}

	
	Node* root = new Node(postorder[pIndex--]);

	int index = map[root->key];

	root->right = construct(index + 1, end, postorder, pIndex, map);

	root->left = construct(start, index - 1, postorder, pIndex, map);

    if(root->left != nullptr){
        if(a[root->key-1] < a[root->left->key-1]) ans++;
    }
    if(root->right != nullptr){
        if(a[root->key-1] < a[root->right->key-1]) ans++;
    }

	return root;
}

Node* construct(vector<int> const &inorder, vector<int> const &postorder)
{
	int n = inorder.size();

	unordered_map<int, int> map;
	for (int i = 0; i < inorder.size(); i++) {
		map[inorder[i]] = i;
	}

	int pIndex = n - 1;
	return construct(0, n - 1, postorder, pIndex, map);
}

int main()
{
	int n;
    cin >> n;
    vector <int> in_order, post_order;
    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        a.push_back(s);
    }

    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        in_order.push_back(s);
    }

    for(int i = 0 ; i < n; i++){
        int s;
        cin >> s;
        post_order.push_back(s);
    }

	Node* root = construct(in_order, post_order);

    cout << ans << "\n";
	return 0;
}