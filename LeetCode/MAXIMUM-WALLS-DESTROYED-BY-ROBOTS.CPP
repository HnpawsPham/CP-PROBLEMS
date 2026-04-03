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

struct robot{
    int pos, dis;
    robot() {};
    robot(int pos1, int dis1) : pos(pos1), dis(dis1) {}

    bool operator<(const robot& other) const {
        if(pos != other.pos) return pos < other.pos;
        return dis < other.dis;
    }
};

int n, m;

int cntWall(int l, int r, const vi& wall){
    if(l > r) return 0;
    return upper_bound(wall.begin(), wall.end(), r) - lower_bound(wall.begin(), wall.end(), l);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int robots[n], d[n];
    vi wall(m);
    for(int i = 0; i < n; i++) cin>>robots[i];
    for(int i = 0; i < n; i++) cin>>d[i];
    for(int i = 0; i < m; i++) cin>>wall[i];

    vector<robot> a;
    for(int i = 0; i < n; i++)
        a.push_back({robots[i], d[i]});

    sort(a.begin(), a.end());
    sort(wall.begin(), wall.end());
    
    vi l(n, 0), r(n, 0);
    for(int i = 0; i < n; i++){
        int llim = (i > 0 ? a[i - 1].pos + 1 : -2e9 - 5);
        l[i] = cntWall(max(llim, a[i].pos - a[i].dis), a[i].pos, wall);

        int rlim = (i < n - 1 ? a[i + 1].pos - 1 : 2e9 + 5);
        r[i] = cntWall(a[i].pos, min(a[i].pos + a[i].dis, rlim), wall);
    }

    vector<vi> dp(n, vi(2, 0));
    dp[0][0] = l[0];
    dp[0][1] = r[0];

    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i - 1][0] + l[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + r[i];

        int gap = cntWall(a[i - 1].pos, a[i].pos, wall);
        int combine = min(gap, r[i - 1] + l[i]);
        int maxx = (i == 1 ? 0 : max(dp[i - 2][1], dp[i - 2][0]));

        dp[i][0] = max(dp[i][0], maxx + combine);
    }
    cout<<max(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}