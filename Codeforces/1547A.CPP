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

int d(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int sol(){
    int xa, ya, xb, yb, xf, yf;
    cin>>xa>>ya>>xb>>yb>>xf>>yf;

    int res = d(xa, ya, xb, yb);
    if(xa == xf && xf == xb && yf > min(ya, yb) && yf < max(ya, yb)) 
        res += 2;

    if(ya == yf && yf == yb && xf > min(xa, xb) && xf < max(xa, xb))
        res += 2;
    return res;
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