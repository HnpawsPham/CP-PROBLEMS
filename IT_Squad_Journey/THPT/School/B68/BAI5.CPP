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
#define taskname "BAI5"

struct point{
    int x, y;
    point(){};
    point(int x1, int y1): x(x1), y(y1) {};

    bool operator<(const point& other) const {
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};

int n;
const int oo = 1e9 + 5;
vector<point> a;

ll crossProd(const point& a, const point& b, const point& c){
    return 1LL * (b.x - a.x) * 1LL * (c.y - a.y) - 1LL * (b.y - a.y) * 1LL * (c.x - a.x);
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
    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        a.push_back(point(x, y));
    }
    sort(a.begin(), a.end());

    vector<point> hull;
    for(int i =0; i < n; i++){
        int sz = hull.size();
        while(sz >= 2 && crossProd(hull[sz - 2], hull.back(), a[i]) <= 0){
            hull.pop_back();
            sz--;
        }
        hull.push_back(a[i]); 
    }

    int m = hull.size();
    for(int i = n - 2; i >= 0; i--){
        int sz = hull.size();
        while(sz > m && crossProd(hull[sz - 2], hull.back(), a[i]) <= 0){
            hull.pop_back();
            sz--;
        }
        hull.push_back(a[i]);
    }

    hull.pop_back();
    m = hull.size();
    
    ll res = 0;
    for(int i = 0; i < m; i++){
        int j = (i + 1) % m;
        res += hull[i].x * hull[j].y - hull[j].x * hull[i].y;
    }
    
    cout<<m<<el;
    cout<<fixed<<setprecision(1)<<(db)(abs(res) / 2.0)<<el;

    int pos = 0;
    for(int i = 1; i < m; i++)
        if(hull[i].y < hull[pos].y || (hull[i].y == hull[pos].y && hull[i].x < hull[pos].x))
            pos = i;

    for(int i = 0; i < m; i++)
        cout<<hull[(i + pos) % m].x<<" "<<hull[(i + pos) % m].y<<el;
    return 0;
}