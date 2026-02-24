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

ll res = 0;
void dfs(TreeNode* u, ll sum){
    if(u == nullptr) return;

    sum = (sum << 1) | u->val;

    if(u->left == nullptr && u->right == nullptr){
        res += sum;
        return;
    }

    dfs(u->left, sum);
    dfs(u->right, sum);
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TreeNode *head;
    vector<bool> a;
    dfs(head, a);
    return 0;
}