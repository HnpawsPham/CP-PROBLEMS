#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 1e5 + 5;
set<int> a[maxn];
int in[maxn] = {0};

void euler(int x){
    stack<int> st;
    vi ec;
    st.push(x);
    
    while(!st.empty()){
        int u = st.top();
        if(a[u].size() > 0){
            int v = *a[u].begin();
            a[u].erase(v);
            a[v].erase(u);
            st.push(v);
        }
        else{
            st.pop();
            ec.push_back(u);
        }
    }
    reverse(ec.begin(), ec.end());
    for(int x : ec) cout<<x<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].insert(v);
        a[v].insert(u);
        in[u]++;
        in[v]++;
    }
    euler(1);

    return 0;
}

// 5 6
// 1 2
// 2 3
// 3 1
// 2 4
// 4 5
// 2 5

// 6 6
// 1 2
// 2 3
// 2 5
// 2 5
// 5 6
// 3 4