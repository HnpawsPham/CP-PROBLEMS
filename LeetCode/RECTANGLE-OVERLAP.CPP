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

    int a[4], b[4];
    for(int i = 0; i < 4; i++) cin>>a[i];
    for(int i = 0; i < 4; i++) cin>>b[i];

    // 0: x2, 1: y2, 2: x1, 3: y1
    bool res = (a[0] < b[2] && a[2] > b[0] && a[1] < b[3] && a[3] > b[1]);
    cout<<res;
    return 0;
}