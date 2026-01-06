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

int depth = 0;
const int maxn = 1e4 + 5;
int sum[maxn] = {0};

void dfs(TreeNode* u, int h){
    if(u == nullptr) return;
    depth = max(depth, h);
    
    sum[h] += u->val;

    dfs(u->left, h + 1);
    dfs(u->right, h + 1);
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
    
    dfs(root, 1);

    int maxx = sum[1], res = 1;
    for(int i = 2; i <= depth; i++)
        if(sum[i] > maxx){
            maxx = sum[i];
            res = i;
        }
    cout<<res;
    return 0;
}