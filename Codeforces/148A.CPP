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

    int a, b, c, d, n;
    cin>>a>>b>>c>>d>>n;

    bool check[n + 1] = {0};
    for(int i = a; i <= n; i+=a)
        check[i] = 1;

    for(int i = b; i <= n; i+=b)
        check[i] = 1;

    for(int i = c; i <= n; i+=c)
        check[i] = 1;

    for(int i = d; i <= n; i+=d)
        check[i] = 1;
    cout<<count(check + 1, check + n + 1, 1);
    return 0;
}