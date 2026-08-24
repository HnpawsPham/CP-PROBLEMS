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

    int n;
    cin>>n;
    bool a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll res = 0;
    int cnt0 = 0;
    for(int i = 0; i < n; i++)
        if(!a[i]){
            res += i - cnt0;
            cnt0++;
        }
    cout<<res;
    return 0;
}