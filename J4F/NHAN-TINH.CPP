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
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; i * j <= n; j++)
            if(1LL * a[i] * a[j] != a[i * j]) return cout<<"NO", 0;
    cout<<"YES";
    return 0;
}