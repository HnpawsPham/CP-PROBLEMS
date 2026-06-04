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

struct car{
    int id, w, t;
    car() {};
    
    bool operator<(const car& other) const{
        return w * other.t > other.w * t;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    car a[n];
    for(int i = 0; i < n; i++) cin>>a[i].w;
    for(int i = 0; i < n; i++){
        cin>>a[i].t;
        a[i].id = i + 1;
    }
    sort(a, a + n);

    int t = 0;
    ll cost = 0;
    for(int i = 0; i < n; i++){
        t += a[i].t;
        cost += 1LL * a[i].w * t;
    }

    cout<<cost<<el;
    for(int i = 0; i < n; i++)
        cout<<a[i].id<<" ";
    return 0;
}