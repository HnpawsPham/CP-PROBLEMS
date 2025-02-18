#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll x;
const int maxn = 45;
ll a[maxn];
vector<ll> g1, g2;

void sol1(int i, ll sum){
    if(sum > x) return;

    if(i == n/2){
        g1.push_back(sum);
        return;
    }

    sol1(i + 1, sum);
    sol1(i + 1, sum + a[i]);
    return;
}

void sol2(int i, ll sum){
    if(sum > x) return;

    if(i == n){
        g2.push_back(sum);
        return;
    }

    sol2(i + 1, sum);
    sol2(i + 1, sum + a[i]);

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;

    for(int i = 0; i < n; i++) cin>>a[i];
    sol1(0, 0);
    sol2(n / 2, 0);

    ll res = 0;
    sort(g1.begin(), g1.end());

    for(ll sum : g2)
        res += upper_bound(g1.begin(), g1.end(), x - sum) - lower_bound(g1.begin(), g1.end(), x - sum);
    
    cout<<res;

    return 0;
}