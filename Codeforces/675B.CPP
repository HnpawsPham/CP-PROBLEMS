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

int n, a, b, c, d;

bool check(int x){
    return (1 <= x && x <= n);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b>>c>>d;

    ll cnt = 0;
    for(int x = 1; x <= n; x++){
        if(check(x + a - d) && check(x - c + a + b - d) && check(x + b - c))
            cnt++;
    }
    cout<<cnt * n;
    return 0;
}