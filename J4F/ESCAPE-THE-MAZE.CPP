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

int a[4], dir[4] = {'L', 'R', 'U', 'D'};
const ll oo = 2e18;

ll combine(ll n, ll k) {
    if(k < 0 || k > n) return 0;
    if(k == 0 || k == n) return 1;
    if(k > n - k) k = n - k;

    ll res = 1;
    for(int i = 1; i <= k; i++) {
        if(res > oo / (n - i + 1)) return oo;
        res = res * (n - i + 1);
        res /= i;
    }
    return res;
}

ll cnt() {
    ll sz = a[0] + a[1] + a[2] + a[3];
    if(sz == 0) return 1;
    
    ll res = 1, m = sz;
    for(int i = 0; i < 4; i++) {
        if(a[i] == 0) continue;
        ll c = combine(m, a[i]);
        if(res > oo / c) return oo;
        res *= c;
        m -= a[i];
    }
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "k", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>k){
        n = a[0] + a[1] + a[2] + a[3];
        if(cnt() < k){
            cout<<-1<<el;
            continue;
        }
        string res = "";

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 4; j++){
                if(!a[j]) continue;
                a[j]--;
                ll perm = cnt();
                if(k <= perm){
                    res.push_back(dir[j]);
                    break;
                }
                else{
                    k -= perm;
                    a[j]++;
                }
            }
        cout<<res<<el;
    }
    return 0;
}