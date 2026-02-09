#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

struct TreeNode {
    int val;
    TreeNode *left;     
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define node TreeNode*

void dfs(node u, vi& a){
    if(u == nullptr) return;

    dfs(u->left, a);
    a.push_back(u->val);
    dfs(u->right, a);
    return;
}

node build(int l, int r, const vi& a){
    if(l > r) return nullptr;

    int mid = (l + r) / 2;
    node u = new TreeNode(a[mid]);
    u->left = build(l, mid - 1, a);
    u->right = build(mid + 1, r, a);
    return u;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node root;
    vi a;
    dfs(root, a);
    cout<<build(0, a.size() - 1, a);
    return 0;
}