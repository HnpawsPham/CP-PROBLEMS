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
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int p[n], s[n];
    p[0] = a[0], s[n - 1] = a[n - 1];
    for(int i = 1; i < n; i++)
        p[i] = min(p[i - 1], a[i]);

    for(int i = n - 2; i >= 0; i--)
        s[i] = max(s[i + 1], a[i]);

    for(int i = 1; i < n; i++)
        if(p[i - 1] > s[i]) return "No";
    return "Yes";
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