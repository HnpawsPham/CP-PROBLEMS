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

        viii v(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[i] = {a, b, i + 1};  
        }

        viii use;
        for (auto [a, b, i] : v) 
            if (union_set(a, b)) 
                use.emplace_back(a, b, i);
            
        vector<pii> inv;
        for (auto [a, b, _] : use) 
            inv.emplace_back(a, b);
        
        sort(inv.begin(), inv.end());

        int f = 0, l = -1, r = -1;
        for (auto [a, b] : inv) {
            if (a > r) {
                f += b - a;
                l = a, r = b;
            } else {
                if (b > r) {
                    f += b - r;
                    r = b;
                }
            }
        }

        cout<<use.size()<<el;
        for (const auto& [a, b, i] : use) 
            cout << i << ' ';
        cout<<el;
    }

    return 0;
}