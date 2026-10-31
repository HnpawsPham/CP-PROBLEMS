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
const int oo = 1e9 + 5;
int minx, maxx, miny, maxy;

void maxi(int x, int y){
    maxx = max(maxx, x);
    maxy = max(maxy, y);
}

void mini(int x, int y){
    minx = min(minx, x);    
    miny = min(miny, y);
}

ll sol(){
    int n, m, q;
    cin>>n>>m>>q;
    minx = oo; maxx = -oo; miny = oo; maxy = -oo;

    while(n--){
        int x, y;
        cin>>x>>y;
        maxi(x, y);
        mini(x, y);
    }
    while(m--){
        int x1, y1, x2, y2; // bot-l, top-r
        cin>>x1>>y1>>x2>>y2;
        maxi(x2, y2);
        mini(x1, y1);
    }
    while(q--){
        int x, y, r;
        cin>>x>>y>>r;
        maxi(x + r, y + r);
        mini(x - r, y - r);
    }
    return 1LL * max(maxx - minx, maxy - miny) * max(maxx - minx, maxy - miny);
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
        cout<<sol()<<el;
    }
    return 0;
}