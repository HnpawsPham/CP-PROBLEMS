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

int n, k;
const int maxn = 1e5 + 5;
const ll oo = 2e14 + 5;
int a[maxn];

bool check(ll t){
    ll sum = 0;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(a[i] > t) return 0;
        if(sum + a[i] > t){
            sum = 0;
            cnt++;
        }
        sum += a[i];
    }
    return cnt <= k;
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
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = 0, r = oo, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)) 
            r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;
    return 0;
}