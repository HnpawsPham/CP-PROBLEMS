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

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return half * half * a;
    return half * half;
}

void sol(){
    int x, y;
    cin>>x>>y;
    if(y % x){
        cout<<"0 0";
        return;
    }

    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++){
            int cur = ppow(i, j);
            if(cur > 100) break;
            if(cur == y / x){
                cout<<j<<" "<<i;
                return;
            }
        }
    cout<<"0 0";
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