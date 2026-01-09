#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define data pair<TreeNode*, int>
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

data dfs(TreeNode* u){
    if(u == nullptr) return {nullptr, 0};

    data l = dfs(u->left);
    data r = dfs(u->right);
    
    if(l.se == r.se) return {u, l.se + 1};
    else if(l.se > r.se) return {l.fi, l.se + 1};
    return {r.fi, r.se + 1};
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TreeNode* root;
    // idk how to input lol
    cout<<dfs(root).fi;
    return 0;
}