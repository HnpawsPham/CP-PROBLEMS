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

int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    if(n == 1 && m == 1) return cout<<0, 0;

    if(m == 1){
        for(int i = 0, j = 2; i < n; i++, j++)
            cout<<j<<el;
    }
    else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                cout<<lcm(i, n + j)<<" ";
            cout<<el;
        }
    }
    return 0;
}