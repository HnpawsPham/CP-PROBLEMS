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

int mp[2][1050000] = {0};

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
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    
    mp[0][0] = 1;
    int sum = 0; 
    ll res = 0;

    for(int i = 1; i <= n; i++){
        sum ^= a[i];
        res += mp[i % 2][sum];
        mp[i % 2][sum]++;
    }
    cout<<res;
    return 0;
}