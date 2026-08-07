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

const int oo = 1e5 + 5;
int cnt[oo];

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
    vector<vi> a(n);
    for(int i = 0; i < n; i++){
        int m, x;
        cin>>m;
        for(int j = 0; j < m; j++){
            cin>>x;
            a[i].push_back(x);
        }
    }

    vector<pii> v;
    for(int i = 0; i < n; i++)
        for(const int& x : a[i])
            v.push_back({x, i});

    sort(v.begin(), v.end());
    memset(cnt, 0, sizeof cnt);

    int uniq = 0, l = 0;
    int minn = oo, minl = -1, minr = -1;
    int m = v.size();

    for(int i = 0; i < m; i++){
        cnt[v[i].se]++;
        if(cnt[v[i].se] == 1) uniq++;

        while(l <= i && uniq == n){
            if(minn > v[i].fi - v[l].fi){
                minn = v[i].fi - v[l].fi;
                minl = v[l].fi;
                minr = v[i].fi;
            }
            cnt[v[l].se]--;
            if(cnt[v[l++].se] == 0) uniq--;
        }
    }
    cout<<minl<<" "<<minr;
    return 0;
}

// 3
// 5
// 4 10 15 24 26 
// 4
// 0 9 12 20
// 4
// 5 18 22 30