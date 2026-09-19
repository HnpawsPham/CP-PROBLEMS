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

    int r, cx, cy, sx1, sy1, sx2, sy2;
    cin>>r>>cx>>cy>>sx1>>sy1>>sx2>>sy2;

    int mindx = 0, mindy = 0;
    if(cx < sx1) mindx = sx1 - cx;
    else if(cx > sx2) mindx = cx - sx2;
    if(cy < sy1) mindy = sy1 - cy;
    else if(cy > sy2) mindy = cy - sy2;

    cout<<(mindx * mindx + mindy * mindy <= r * r);
    return 0;
}

// 1 0 0 1 -1 3 1