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

    int n, MOD;
    cin>>n>>MOD;
    int a[5] = {n, n + 1, n + 2, n + 3, n + 4};
    int m = 120;

    for(int i = 0; i < 5; i++){
        ll gcd = __gcd(a[i], m);
        a[i] /= gcd;
        m /= gcd;
    }
    ll res = 1;
    for(int i = 0; i < 5; i++)
        res = (res * a[i] % MOD) % MOD;
    cout<<res;
    return 0;
}