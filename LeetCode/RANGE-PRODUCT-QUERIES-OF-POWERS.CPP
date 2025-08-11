#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, q;
const int MOD = 1e9 + 7;

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);

    if(b & 1) return 1LL * half * half % MOD * a % MOD;
    return 1LL * half * half % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    vector<vi> que;
    for(int i = 0; i < q; i++){
        int l, r;
        cin>>l>>r;
        que.push_back({l, r});
    }

    vi a;
    int i = 0;
    while(n > 0){
        int d = (1 << i) * (n % 2);
        if(d > 0) a.push_back(d);
        n /= 2;
        i++;
    }
    
    int m = a.size();
    vi p(m + 1, 1);
    for(int i = 0; i < m; i++)
        p[i + 1] = 1LL * p[i] * a[i] % MOD;

    vi res;
    for(const vi& v : que)
        res.push_back(1LL * p[v[1] + 1] * ppow(p[v[0]], MOD - 2) % MOD);
        
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 15 3
// 0 1
// 2 2
// 0 3