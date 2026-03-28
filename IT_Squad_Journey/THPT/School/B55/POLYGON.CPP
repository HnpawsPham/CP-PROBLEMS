#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pdb pair<db, db>
#define fi first
#define se second
#define taskname "polygon"

struct point{
    db x, y;
    point(int x1, int y1) : x(x1), y(y1) {};
    point() {};
};

int n, m;
     // dinh dg2  dinh 1 dg1  dinh 2 dg1
point coor(point p, point p1, point p2){
    db dx = p2.x - p1.x;
    db dy = p2.y - p1.y;

    db l = dx * dx + dy * dy;
    if(l == 0) return p1;

    db k = ((p.x - p1.x) * dx + (p.y - p1.y) * dy) / l;

    k = min(1.0, max(0.0, k));

    db x3 = p1.x + k * dx;
    db y3 = p1.y + k * dy;
    return point(x3, y3);
}

db d(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<point> a(n);
    for(int i = 0; i < n; i++) cin>>a[i].x>>a[i].y;
    cin>>m;
    vector<point> b(m);
    for(int i = 0; i < m; i++) cin>>b[i].x>>b[i].y;

    db res = 1e18 + 5;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int z = (j + 1) % m;
            point p = coor(a[i], b[j], b[z]);
            db dis = d(a[i], p);
            res = min(res, dis);
        }   

    cout<<fixed<<setprecision(6)<<res / 2.0;
    return 0;
}