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
const int MOD = 1e9 + 7;
long total = 0, res = 0;

void calc(TreeNode* u){
    if(u == nullptr) return;
    total += u->val;

    calc(u->left);
    calc(u->right);
    return;
}

int dfs(TreeNode* u){
    if(u == nullptr) return 0;
    int sum = u->val;

    sum += dfs(u->left);
    sum += dfs(u->right);
    res = max(res, (total - sum) * sum);
    return sum;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // idk how to input lol

    calc(root);
    dfs(root);
    cout<<res % MOD;
    return 0;
}