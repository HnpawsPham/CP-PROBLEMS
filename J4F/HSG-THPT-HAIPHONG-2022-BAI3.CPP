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
ll k;
const int maxn = 25;
pii a[maxn];

bool check(ll t){
    if(t < a[0].fi) return 0;
    ll sum = 0;
    for(int i = 0; i < n; i++)
        if(t >= a[i].fi)
            sum += (t - a[i].fi) / a[i].se + 1;
        else break;

    return sum >= k;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i =0 ; i < n; i++)
        cin>>a[i].fi>>a[i].se;
    sort(a, a + n);

    ll l = 0, r = 5e17 + 5, mid, res;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid)){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    cout<<res;
    return 0;
}