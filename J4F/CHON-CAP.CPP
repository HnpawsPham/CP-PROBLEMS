#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define fi first
#define se second

int n, m, d;
const int maxn = 2015;
int a[maxn];
vector<piii> b, tmp;

bool comp(const piii& a, const piii& b){
    if(a.se.fi == b.se.fi) return a.se.se < b.se.se;
    return a.se.fi > b.se.fi;
}

int sol(int l, int r){
    vector<piii> tmp(b.begin() + l, b.begin() + r + 1);

    sort(tmp.begin(), tmp.end(), comp);
    bool check[n] = {0};
    int cnt = 0;
    
    for(const auto& x : tmp){
        if(check[x.se.fi] || check[x.se.se]) continue;
        check[x.se.fi] = check[x.se.se] = 1;
        cnt++;
    }
    return cnt;
}

int main(){
    // freopen("PAIR.INP", "r", stdin);
    // freopen("PAIR.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            b.push_back({a[i] + a[j], {i, j}});

    sort(b.begin(), b.end());
    int res = 0;
    m = b.size();

    for(int i = 0; i < m; i++){
        if(i > 0 && b[i].fi == b[i - 1].fi) continue;

        int j = i;
        while(j < m && b[j].fi - b[i].fi <= d) j++;
        res = max(res, sol(i, j - 1));
    }
    cout<<res;
    return 0;
}