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

    int n, a, b;
    cin>>n>>a>>b;
    if(a + b < n)
        return cout<<0, 0;

    int res = 0;
    for(int i = 1; i <= a; i++){
        if(n - i == 0 || n - i > b) continue;
        res = max(res, min(a / i, b / (n - i)));
    }
    cout<<res;
    return 0;
}