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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    ll ori = 0;
    for(int i = 0; i < n; i++)
        ori += 1LL * b[i] * a[i];

    if(n < k) return ori;

    ll take = 0, notake = 0;
    int sz = k / 2;
    
    for(int i = 0; i < sz; i++)
        notake += 1LL * b[i] * a[i];

    for(int i = sz; i < k; i++)
        take += 1LL * a[i] * (1 - b[i]);

    ll del = take - notake;

    for(int i = 1; i <= n - k; i++){
        notake -= 1LL * b[i - 1] * a[i - 1];
        notake += 1LL * b[i + sz - 1] * a[i + sz - 1];

        take -= (1LL - b[i + sz - 1]) * 1LL * a[i + sz - 1];
        take += (1LL - b[i + k - 1]) * 1LL * a[i + k - 1];

        ll tmp = take - notake;
        del = max(del, tmp);
    }
    cout<<ori + max(0LL, del);
    return 0;
}