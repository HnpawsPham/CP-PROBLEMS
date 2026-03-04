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

    int n, u, v;
    cin>>n>>u>>v;

    set<pii> s;
    while(n--){
        int x, y;
        cin>>x>>y;

        int dx = x - u;
        int dy = y - v;

        int g = __gcd(dx, dy);
        dx /= g;
        dy /= g;

        if(dx < 0 && (dx == 0 && dy < 0)){
            dx *= -1;
            dy *= -1;
        }

        s.insert({dx, dy});
    }
    cout<<s.size();
    return 0;
}