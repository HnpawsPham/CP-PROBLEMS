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
using umi = std::unordered_map<int, int>;

int n;

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half * a;
    return half * half;
}

umi calc(ll x){
    umi mp;

    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            int cnt = 0;
            while(x % i == 0){
                x /= i;
                cnt++;
            }
            mp[i] = cnt;
        }
    }
    if(x > 1) mp[x] = 1;
    return mp;
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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n == 0) return cout<<"impossible", 0;
    for(int x : a)
        if(x == 0) return cout<<"impossible", 0;

    umi mul, lcm;
    for(int x : a){
        umi mp = calc(x);
        for(auto [x, cnt] : mp){
            mul[x] += cnt;
            lcm[x] = max(lcm[x], cnt);
        }
    }

    ll res = 1;
    for(auto [x, cnt] : mul)
        res *= ppow(x, cnt - lcm[x]);

    cout<<res;
    return 0;
}