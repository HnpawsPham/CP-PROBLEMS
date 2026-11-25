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

int n, base = 2;
const int MOD = 1e9 + 7;
vll ppow = {1}, h = {0};

bool check(int len, const vi& a){
    int cnt = 0;
    unordered_map<ll, int> mp;

    for(int i = 0; i + len <= n; i++){
        ll cur = ((h[i + len] - h[i] * ppow[len]) % MOD + MOD) % MOD;
        mp[cur]++;

        if(mp[cur] == 1) cnt++;
        else if(mp[cur] == 2) cnt--;
    }
    return cnt > 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n; i++){
        ppow.push_back(ppow.back() * 1LL * base % MOD);
        h.push_back(h.back() * 1LL * base % MOD + 1LL * a[i] % MOD);
    }

    int l = 1, r = n, mid, res = n;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid, a)){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    cout<<res;
    return 0;
}