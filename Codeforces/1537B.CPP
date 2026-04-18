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

int d(int i, int j, int x, int y){
    return abs(i - x) + abs(j - y);
}

void sol(){
    int n, m, x, y;
    cin>>n>>m>>x>>y;

    if(d(x, y, 1, 1) + d(1, 1, n, m) + d(n, m, x, y) 
    > d(x, y, 1, m) + d(1, m, n, 1) + d(n, 1, x, y))
        cout<<"1 1 "<<n<<" "<<m;
    else cout<<1<<" "<<m<<" "<<n<<" "<<1;
    return;
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
        sol();
        cout<<el;
    }
    return 0;
}