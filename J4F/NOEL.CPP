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

int n, m;
const int maxn = 1e5 + 5;
ll a[maxn], b[maxn];

bool check(ll t){
    for(int i = 0, j = 0; i < n; i++){
        if(a[i] >= t) continue;
        while(j < m && a[i] + b[j] < t)
            j++;
        if(j < m && a[i] + b[j] >= t)
            j++;
        else return 0;
    }
    return 1;
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
    for(int i= 0; i < n; i++) cin>>a[i];
    cin>>m;
    for(int i = 0; i < m; i++) cin>>b[i];

    ll l = 0, r = 1e17 + 5, mid, res;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    } 
    cout<<res;
    return 0;
}