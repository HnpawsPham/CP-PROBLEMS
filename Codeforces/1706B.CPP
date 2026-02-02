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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cur = 0;
    int h[n + 1] = {0}, prev[n + 1] = {0};
    memset(prev, -1, sizeof prev);

    for(int i = 0; i < n; i++)
        if(prev[a[i]] == -1 || (i - prev[a[i]]) % 2){
            h[a[i]]++;
            prev[a[i]] = i;
        }
    
    for(int i = 1; i <= n; i++)
        cout<<h[i]<<" ";
    cout<<el;
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
        // cout<<sol()<<el;
        sol();
    }
    return 0;
}

// 1
// 6
// 4 2 2 2 4 4