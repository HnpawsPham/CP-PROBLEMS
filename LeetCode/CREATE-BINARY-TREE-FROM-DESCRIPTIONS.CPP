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
const int maxn = 1e5 + 5;
int a[maxn][2];
bool check[maxn];

node createNode(int x){
    node res = new TreeNode(x);
    return res;
}

void dfs(int u, node cur){
    if(a[u][0] != -1){
        cur->left = createNode(a[u][0]);
        dfs(a[u][0], cur->left);
    }
    else cur->left = nullptr;

    if(a[u][1] != -1){
        cur->right = createNode(a[u][1]);
        dfs(a[u][1], cur->right);
    }    
    else cur->right = nullptr;
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

    int n;
    cin>>n;
    int q[n][3];
    for(int i = 0; i < n; i++)
        cin>>q[i][0]>>q[i][1]>>q[i][2];

    memset(a, -1, sizeof a);
    memset(check, 0, sizeof check);

    for(const vi& v : q){
        check[v[1]] = 1;
        if(v[2]) a[v[0]][0] = v[1];
        else a[v[0]][1] = v[1];
    }
    
    int root = q[0][0];
    for(const vi& v : q)
        if(!check[v[0]]){
            root = v[0];
            break;
        }

    node head = createNode(root);
    dfs(root, head);

    return 0;
}