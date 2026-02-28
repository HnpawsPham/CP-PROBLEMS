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
#define taskname "BALANCE"

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
    int a[n + 10];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll p[n + 1] = {0}, s[n + 2] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    for(int i = n; i > 0; i--)
        s[i] = s[i + 1] + a[i];

    ll dmin = 5e12 + 5;
    for(int i = 1; i <= n; i++)
        dmin = min(dmin, abs(p[i] - s[i + 1]));
    cout<<dmin;
    return 0;
}