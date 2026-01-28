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

int n;
const int maxn = 1e6 + 5;
int a[maxn];
int spf[maxn];

void sieve(){
    for(int i = 1; i < maxn; i++)
        spf[i] = i;

    for(int i = 2; i * i < maxn; i++)
        if(spf[i] == i)
            for(int j = i * i; j < maxn; j+=i){
                if(spf[j] == j) 
                    spf[j] = i;
            }
    return;
}

ll lcm(int a, int b){
    return 1LL * a * b / __gcd(a, b);
}

ll sub1(){
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            ll x = lcm(a[i], a[j]) / __gcd(a[i], a[j]);
            ll tmp = (ll)sqrt(x);
            if(tmp * tmp == x) cnt++;
        }
    return cnt;
}

ll sub2(){
    return 1LL * n * 1LL * (n - 1) / 2LL;
}

ll sol(){
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x = a[i], cur = 1;
        while(x > 1){
            int p = spf[x];
            int cnt = 0;

            while(x % p == 0){
                x /= p;
                cnt++;
            }
            if(cnt % 2) cur *= p;
        }
        mp[cur]++;
    }

    ll res = 0;
    for(const auto& x : mp)
        res += 1LL * x.se * 1LL * (x.se - 1) / 2LL;
    return res;
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
    for(int i = 0; i < n; i++) cin>>a[i];    

    if(n <= 4000)
        return cout<<sub1(), 0;

    sieve();
    bool ok = 1;
    
    for(int x : a){
        int tmp = (int)sqrt(x);
        if(tmp * tmp != x) 
            return cout<<sol(), 0;
    }

    cout<<sub2();
    return 0;   
}

// 5
// 2 8 3 12 50