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
#define taskname "BAI4"

int n, m;
const int maxn = 1e5 + 5;
ll a[maxn] = {0};

bool check(ll t){
    int cnt = 0, i = 0;
    while(i < n){
        int j = i;
        while(j < n && a[j] <= a[i] + t) j++; // check cover dc toi dau

        i = j;
        while(i < n && a[i] <= a[j - 1] + t) i++; // add cover

        cnt++;
    }
    return cnt <= m;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = 0, r = 1e15 + 5, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;
    return 0;
}