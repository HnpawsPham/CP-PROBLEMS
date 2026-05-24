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

int tc = 1;

string sol(){
    int n, m;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    cin>>m;
    int b[m];
    for(int i = 0; i < m; i++) cin>>b[i];

    int maxa = *max_element(a, a + n);
    int maxb = *max_element(b, b + m);

    if(maxa > maxb) return "Alice\nAlice";
    else if(maxb > maxa) return "Bob\nBob";
    return "Alice\nBob";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}