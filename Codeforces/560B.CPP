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

int n, m;

bool check(int a, int b, int c, int d){
    return (a + c <= n && max(b, d) <= m) || (b + d <= m && max(a, c) <= n)
        || (a + c <= m && max(b, d) <= n) || (b + d <= n && max(a, c) <= m);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[4];
    cin>>n>>m;
    for(int i = 0; i < 4; i++) cin>>a[i];
    
    if(check(a[0], a[1], a[2], a[3]) || check(a[1], a[0], a[3], a[2])
    || check(a[0], a[1], a[3], a[2]) || check(a[1], a[0], a[2], a[3]))
        cout<<"YES";
    else cout<<"NO";
    return 0;
}