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

int cnt = 0;

pii dfs(TreeNode* u){
    if(u == nullptr) return {0, 0};
    pii l = dfs(u->left);
    pii r = dfs(u->right);

    int sz = l.se + r.se + 1;
    int sum = l.fi + r.fi + u->val;

    if(u->val == sum / sz) cnt++;
    return {sum, sz};
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
    dfs(root);
    cout<<cnt;
    return 0;
}