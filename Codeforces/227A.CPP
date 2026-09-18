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

    int xa, ya, xb, yb, xc, yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;

    ll prod = 1LL * (xa - xb) * (yc - yb) - 1LL * (xc - xb) * (ya - yb);
    if(prod < 0) cout<<"LEFT";
    else if(prod > 0) cout<<"RIGHT";
    else cout<<"TOWARDS";
    return 0;
}