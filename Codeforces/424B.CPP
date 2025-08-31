#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define x first.first
#define y first.second
#define w second
#define piii pair<pii, int>

int n, s;
const int maxn = 1e3 + 5;
piii a[maxn];

db dis(const piii& a){
    return sqrt(a.x * a.x + a.y * a.y);
}

bool comp(const piii& a, const piii& b){
    return dis(a) < dis(b);
}

bool check(db lim){
    int sum = s;

    for(int i = 0; i < n; i++)
        if(dis(a[i]) <= lim) 
            sum += a[i].w;

    return sum >= 1e6;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    for(int i = 0; i < n; i++) cin>>a[i].x>>a[i].y>>a[i].w;
    if(s >= 1e6) return cout<<0, 0;

    sort(a, a + n, comp);

    // db l = 0, r = 2e7 + 5, mid, res = -1;
    // while(r - l > 2e-6){
    //     mid = (l + r) / 2;
    //     if(check(mid)){
    //         res = mid;
    //         r = mid;
    //     }
    //     else l = mid;
    // }
    db res = 0;
    int sum = s;
    for(int i = 0; i < n; i++){
        sum += a[i].w;
        res = dis(a[i]);
        if(sum >= 1e6) return cout<<fixed<<setprecision(7)<<res, 0;
    }
    cout<<-1;
    return 0;
}

// 20 93350
// 13 -28 486
// 26 -26 48487
// 5 -23 143368
// -23 -25 10371
// -2 -7 75193
// 0 -8 3
// -6 -11 5015
// -19 -18 315278
// 28 -15 45801
// 21 8 4590
// -4 -28 12926
// -16 17 9405
// -28 -23 222092
// 1 -10 1857
// 14 -28 35170
// -4 -22 22036
// -2 -10 1260
// -1 12 375745
// -19 -24 38845
// 10 -25 9256