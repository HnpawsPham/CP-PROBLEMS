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

bool comp(const pii& a, const pii& b){
    if(a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
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
    pii a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i].fi>>a[i].se;

    sort(a, a + n, comp);
    ll res = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i].fi;
        res += a[i].se - sum;
    }
    cout<<res;
    return 0;
}