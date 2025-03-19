#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

ll n;
int k, q, sz;
vector<pii> a;

bool comp(pii a, pii b){
    return a.se < b.se;
}

int search(int x){
    int res = 0;
    for(pii p : a){
        if(p.fi <= x && x <= p.se) res++;
        if(p.fi > x) break;
    }
    return res;
}

int bns(int x){
    int res = 0, l = 0, r = sz - 1, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(a[mid].fi <= x && x <= a[mid].se){
            res = mid;
            l = mid + 1;
        }
        else if(a[mid].se < x) l = mid + 1;
        else if(a[mid].fi > x) r = mid - 1;
    }
    return res;
}

void sub1_2(){
    int d[n + 2] = {}, p[n + 2];
    while(k--){
        int x, y;
        cin>>x>>y;
        d[x]++; 
        d[y + 1] -= 1;
    }

    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + d[i];
    
    while(q--){
        int x; cin>>x;
        cout<<p[x]<<el;
    }
    return;
}

void sub3(){
    while(k--){
        int i, j;
        cin>>i>>j;
        a.push_back({i, j});
    }
    sz = a.size();
    sort(a.begin(), a.end(), comp);

    while(q--){
        int x; cin>>x;
        cout<<search(x)<<el;
    }
    return;
}

int main(){
    freopen("TROCHOI.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>q;
    if(n <= 1e6) sub1_2();
    else sub3();
   
    return 0;
}