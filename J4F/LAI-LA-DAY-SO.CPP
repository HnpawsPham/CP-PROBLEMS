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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    ll res = 0;
    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == k) r = i;
        else if(a[i] > k){
            l = i;
            r = i;
        }
        res += r - l;
    }
    cout<<res;
    return 0;
}