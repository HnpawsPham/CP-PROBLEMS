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

    int a, b, c, n;
    cin>>a>>b>>c>>n;
    if(a + b - c < n && a + b - c >= 0 && c <= a && c <= b) 
        cout<<n - a - b + c;
    else cout<<-1;
    return 0;
}