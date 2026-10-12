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

    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[31];
    memset(cnt, 0, sizeof cnt);
    for(const int& x: a){
        for(int i = 0; i < 31; i++)
            cnt[i] += ((x >> i) & 1);
    }

    vi b(n, 0);
    for(int j = 0; j < 31; j++)
        for(int i = 0; i < cnt[j]; i++)
            b[i] |= (1 << j);

    sort(b.begin(), b.end(), greater<int>());
    const int MOD = 1e9 + 7;
    int sum = 0;
    for(int i = 0; i < k; i++)
        sum = (sum + 1LL * b[i] * b[i] % MOD) % MOD;
    cout<<sum;
    return 0;
}

// 4 2
// 2 6 5 8