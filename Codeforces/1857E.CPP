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

int tc = 1;

void sol(){
    int n;
    cin>>n;
    pii a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i].fi;
        a[i].se = i;
    }
    sort(a, a + n);
    
    ll p[n + 1];
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1].fi;

    ll res[n];
    for(int i = 0; i < n; i++){
        res[a[i].se] = 1LL * i * 1LL * a[i].fi - p[i] + n; 
        res[a[i].se] += p[n] - p[i + 1] - 1LL * (n - i - 1) * 1LL * a[i].fi;
    }
    
    for(const ll& x : res)
        cout<<x<<" ";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}