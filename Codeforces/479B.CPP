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

int n, k;
const int maxn = 1e4 + 5;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];


    priority_queue<pii> maxx;
    priority_queue<pii, vector<pii>, greater<pii>> minn;

    for(int i = 1; i <= n; i++){
        minn.push({a[i], i});
        maxx.push({a[i], i});
    }

    int s = 0;
    vector<pii> res;
        while(k && !maxx.empty() && !minn.empty()){
            pii large = maxx.top(), small = minn.top();
            if(large.fi - small.fi <= 1 || large.fi <= 0) break;

            res.push_back({large.se, small.se});
            maxx.pop();
            minn.pop();

            maxx.push({large.fi - 1, large.se});
            minn.push({small.fi + 1, small.se});
            k--;
        }
    if(!maxx.empty() && !minn.empty())
        s = maxx.top().fi - minn.top().fi;

    cout<<s<<" "<<res.size()<<el;
    for(auto [u, v] : res) 
        cout<<u<<" "<<v<<el;
    return 0;
}