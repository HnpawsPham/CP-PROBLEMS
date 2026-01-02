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

ll l, r;
vector<ll> a;

void sol(ll x){
    if(x != 0)
        a.push_back(x);
    if(x > 10000000000) return;

    sol(x * 10 + 4);
    sol(x * 10 + 7);
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

    cin>>l>>r;
    sol(0);
    sort(a.begin(), a.end());

    ll sum = 0;
    int pos = l;
    for(const ll& x : a){
        if(x < l) continue;

        sum += (min(x, r) - pos + 1) * x;
        pos = x + 1;
        if(x > r) break;
    }
    cout<<sum;
    return 0;
}