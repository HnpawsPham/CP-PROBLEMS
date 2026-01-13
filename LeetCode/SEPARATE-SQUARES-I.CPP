#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

bool check(db t, const vector<vi>& a){
    db sum1 = 0, sum2 = 0;
    for(const vi& v : a){
        db w = v[2];
        int y = v[1];

        if(y >= t) sum2 += w * w;
        else if(y + w <= t) sum1 += w * w;
        else{
            sum1 += (t - y) * w;
            sum2 += (w - t + y) * w;
        }
    }
    return sum1 >= sum2;
}

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
    vector<vi> a(n, vi(3));
    for(int i = 0; i < n; i++) 
        cin>>a[i][0]>>a[i][1]>>a[i][2];

    db l = 0.0, r = 1e12, mid;
    for(int i = 0; i <= 60; i++){
        db mid = (l + r) / 2.0;
        if(check(mid, a)) r = mid;
        else l = mid;
    }
    cout<<fixed<<setprecision(5)<<l;
    return 0;
}

// 2
// 0 0 1
// 2 2 1

// 2
// 0 0 2
// 1 1 1