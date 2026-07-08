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

const int MOD = 1e9 + 7;

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int m;
    cin>>s>>m;
    vector<vi> q(m, vi(2));
    for(int i = 0; i < m; i++) cin>>q[i][0]>>q[i][1];

    int n = s.length();

    vi p(n + 1, 0), cnt(n + 1, 0), num(n + 1, 0);
    for(int i = 1; i <= n; i++){
        p[i] = p[i - 1];
        cnt[i] = cnt[i - 1];
        num[i] = num[i - 1];

        if(s[i - 1] - '0' > 0){
            p[i] += (s[i - 1] - '0');
            cnt[i]++;
            num[i] = num[i] * 10 + (s[i - 1] - '0');
        }
    }

    vi res;
    for(const vi& v : q){
        long long x = (1LL * num[v[1] + 1] - 1LL * num[v[0]] % MOD * 1LL * ppow(10, cnt[v[1] + 1] - cnt[v[0]]) % MOD + MOD) % MOD;
        res.push_back(1LL * (p[v[1] + 1] - p[v[0]]) * x % MOD);
    }
    
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 10203004
// 3
// 0 7
// 1 3
// 4 6