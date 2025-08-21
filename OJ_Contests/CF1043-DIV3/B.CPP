#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b/ 2);
    if(b & 1) return 1LL * half * half * a;
    return 1LL * half * half;
}

void sol(){
    ll n;
    cin>>n;
    deque<ll> res;
    for(int i = 1; i <= 18; i++){
        ll d = 1 + ppow(10, i);
        if(n % d == 0) res.push_front(n / d);
    }
    cout<<res.size()<<el;
    for(ll x : res) cout<<x<<" ";
    if(!res.empty()) cout<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
    }

    return 0;
}