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
#define taskname "CAU4"

ll n, a, b;
    
ll sub2(){
    ll maxx = 0;
    for(int i = 1; i <= a && i < n; i++){ 
        if(n - i > b) continue;
        maxx = max(maxx, min(a / i, b / (n - i)));
    }
    return maxx;
}

ll sub3(){
    ll l = 0, r = min(a, b), mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(a / mid + b / mid >= n)
            l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b;
   
    if(n <= 1e6)
        cout<<sub2();
    else cout<<sub3();
    return 0;
}