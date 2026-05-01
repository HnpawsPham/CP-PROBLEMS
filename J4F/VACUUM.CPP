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

int n, k, step = 0;
const int maxn = 105;
bool a[maxn][maxn];
vector<pii> path;

bool ok(){
    return step < n * n - 1;
}

int i = 0, j = 0;
void incj(int d, int lim){
    while(step < n * n){
        j += d;
        step++;
        if(!a[i][j]) path.push_back({i + 1, j + 1});
        if(j == lim) return;
    }
    return;
}

void inci(int d, int lim){
    while(step < n * n){
        i += d;
        step++;
        if(!a[i][j]) path.push_back({i + 1, j + 1});
        if(i == lim) return;
    }
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];    

    if(!a[i][j]) path.push_back({1, 1});
    int u = 0, l = 0, r = n - 1, d = n - 1;

    while(ok()){
        if(ok()){
            incj(1, r);
            u++;
        }
        if(ok()){
            inci(1, d);
            r--;
        }
        if(ok()){
            incj(-1, l);
            d--;
        }
        if(ok()){
            inci(-1, u);
            l++;
        }
    }

    int sz = path.size();
    for(int i = sz - 2; i > 0; i--)
        path.push_back(path[i]);
    sz += sz - 2;

    cout<<path[k % sz].fi<<" "<<path[k % sz].se;
    return 0;
}