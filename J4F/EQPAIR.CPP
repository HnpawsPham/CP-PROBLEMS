#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const ll MOD = 1e9 + 7;
const int maxn = 1e6 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[maxn] = {0};
    for(int x : a) cnt[x]++;

    ll res = 0;
    for(int i = 1; i < maxn; i++)
        res = (res + ((cnt[i] * (cnt[i] - 1) % MOD) * ((MOD + 1) / 2) % MOD)) % MOD;
    cout<<res;
    return 0;
}

// 6
// 1 2 2 1 3 1