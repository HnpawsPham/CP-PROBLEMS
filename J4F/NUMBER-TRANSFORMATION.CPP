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
    int n, m;
    cin>>n>>m;

    if(n > m){
        cout<<-1;
        return;
    }

    bool ok = 1;
    vi res;
    while(n < m && ok){
        int k = __gcd(n, m / n);
        if(k == 1) ok = 0;

        n *= k;
        res.push_back(k);
    }
    if(ok){
        cout<<res.size()<<" ";
        for(int x : res) cout<<x<<" ";
    }
    else cout<<-1;
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

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}