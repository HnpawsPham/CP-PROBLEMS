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

    if(n < 1000) return cout<<0, 0;
    int cnt = 0;
    for(int i = 1000; i <= n; i++){
        int sz = 0, x = i;
        while(x > 0){
            sz++;
            x /= 10;
        }
        cnt += (sz - 1) / 3;
    }
    cout<<cnt;
    return 0;
}