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

int n, m, k, p, q;

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

    cin>>m;
    int b[m];
    for(int i = 0; i < m; i++) cin>>b[i];

    cin>>k;
    int c[k];
    for(int i = 0; i < k; i++) cin>>c[i];

    cin>>p>>q;
    int r1 = *max_element(a, a + n);
    int p1 = *max_element(b, b + m);
    int p2 = *min_element(c, c + k);

    db res = 0;
    res = r1 * (db)sqrt((db)(q * p1) / (db)(p * p2 + q * p1));
    cout<<fixed<<setprecision(6)<<res;
    return 0;
}