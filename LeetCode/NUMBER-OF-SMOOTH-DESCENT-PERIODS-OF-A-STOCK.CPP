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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll res = 1;
    int len = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1] - 1) len++;
        else{
            res += 1LL * len * 1LL * (len + 1) / 2LL;
            len = 1;
        }
    }
    cout<<res + 1LL * len * 1LL * (len + 1) / 2LL - 1LL;
    return 0;
}

// 4
// 3 2 1 4

// 4
// 8 6 7 7

// 1 
// 1