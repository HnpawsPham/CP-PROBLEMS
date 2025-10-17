#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin>>n>>k;
    ll even = n / 2, odd = n - even;
    ll lim_odd = n - 1 + (n % 2), lim_even = n - (n % 2);

    if(k <= odd) cout<<lim_odd - (odd - k) * 2;
    else cout<<lim_even - (n - k) * 2;
    return 0;
}
