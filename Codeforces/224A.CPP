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

    int s1, s2, s3;
    cin>>s1>>s2>>s3;
    ll s = (ll)(sqrt(1LL * s1 * 1LL * s2 * 1LL * s3));
    ll a = s / s2;
    ll b = s / s3;
    ll c = s / s1;
    cout<<4LL * 1LL * (a + b + c);
    return 0;
}