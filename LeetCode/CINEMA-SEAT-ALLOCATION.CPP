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

bool check[11];
int delta(){
    bool l = !check[2] && !check[3] && !check[4] && !check[5];
    bool r = !check[6] && !check[7] && !check[8] && !check[9];
    bool mid = !check[4] && !check[5] && !check[6] && !check[7];

    if(l && r) return 0;
    if(mid || l || r) return -1;
    return -2;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> a(m, vi(2));
    for(int i = 0; i < m; i++)
        cin>>a[i][0]>>a[i][1];

    ll cnt = 2LL * n;
    unordered_map<int, vi> mp;
    for(const vi& x : a)
        mp[x[0]].push_back(x[1]);

    for(const auto& p : mp){
        memset(check, 0, sizeof check);
        for(const int& x : p.se)
            check[x] = 1;
        cnt += delta();
    }
    cout<<cnt;
    return 0;
}

// 3 6
// 1 2
// 1 3
// 1 8
// 2 6
// 3 1
// 3 10