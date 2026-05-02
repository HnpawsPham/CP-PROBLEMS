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

int tc = 1;

void sol(){
    int n;
    cin>>n;
    ll a[n];
    for(int i = 0 ; i < n; i++) cin>>a[i];

    int cnt[31] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= 30; j++)
            if((a[i] >> j) & 1) cnt[j]++;

    for(int i = 1; i <= n; i++){
        bool ok = 1;
        for(int j = 0; j <= 30 && ok; j++)
            if(cnt[j] && cnt[j] % i) ok = 0;
        if(ok) cout<<i<<" ";
    }
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}