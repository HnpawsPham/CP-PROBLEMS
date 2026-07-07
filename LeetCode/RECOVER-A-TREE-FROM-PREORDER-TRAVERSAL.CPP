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
vi h[1005];

node makeNode(int val){
    node res = new TreeNode(val);
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    int n = s.length();
    int u = 0, d = 0;
    stack<node> st;

    for(int i = 0; i < n; i++){
        if(s[i] == '-') d++;
        else{
            u = u * 10 + (s[i] - '0');
            if(i + 1 != n && s[i + 1] != '-') continue;

            while(st.size() > d) st.pop();

            node cur = makeNode(u);

            if(!st.empty()){
                if(st.top()->left == nullptr)
                    st.top()->left = cur;
                else st.top()->right = cur;
            }
            st.push(cur);
        
            u = 0;
            d = 0;
        }
    }
    
    while(st.size() > 1) st.pop();
    // return st.top();
    return 0;
}