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

int n, s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll res = 0;
    for(int i = 0; i < (1 << n); i++){
        ll sum = 0;
        for(int j = 0; j < n; j++)
            if(1 & (i >> j)) sum += a[j];
        if(sum <= s) res = max(res, sum);
    }
    cout<<res;
    return 0;
}