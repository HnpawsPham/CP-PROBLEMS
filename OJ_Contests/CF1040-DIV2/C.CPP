#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define viii vector<tuple<int, int, int>>

int t, n;
const int maxn = 6005;
int sz[maxn], parent[maxn];

void make_set(){
    for(int i = 1; i <= 2 * n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];

    sz[b] = 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while (t--) {
        cin>>n;
        make_set();

        vi res;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin>>a>>b;

            if(union_set(a, b)) res.push_back(i + 1);  
        }
        
        cout<<res.size()<<el;
        for(int x : res) cout<<x<<" ";
        cout<<el;
    }

    return 0;
}