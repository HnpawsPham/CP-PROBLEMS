#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

struct point{
    ll x, y;
};

int n;
const int maxn = 2e5 + 5;
point a[maxn];

ll p2(point p){
    return 1LL * p.x * p.x + 1LL * p.y * p.y;
}

bool comp(const point& a, const point& b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool comp2(const point& a, const point& b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

ll sol(){
    ll minn = LLONG_MAX;
    for(int i = 1; i < n; i++)
        minn = min(minn, p2(a[i]) + p2(a[i - 1]) 
        - 2LL * a[i].x * a[i - 1].x - 2LL * a[i].y * a[i - 1].y);

    int l = 0, r = n - 1;
    while(l < r){
        minn = min(minn, p2(a[l]) + p2(a[r]) 
        - 2LL * a[l].x * a[r].x - 2LL * a[l].y * a[r].y);
        l++;
        r--;
    }
    return minn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin>>a[i].x>>a[i].y;

    ll res = LLONG_MAX;
    // if(n <= 3050){
    //     for(int i = 0; i < n; i++)
    //         for(int j = i + 1; j < n; j++){
    //             ll dx = a[i].x - a[j].x;
    //             ll dy = a[i].y - a[j].y;
    //             res = min(res, dx * dx + dy * dy);
    //         }
    // }
    // else{
        sort(a, a + n, comp);
        res = min(res, sol());
        sort(a, a + n, comp2);
        res = min(res, sol());
    // }

    cout << res;
    return 0;
}

// 6
// -100 0
// 0 0
// 1 100
// 2 0
// 100 100
// 200 200

