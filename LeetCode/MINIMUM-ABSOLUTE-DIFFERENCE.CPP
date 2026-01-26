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

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a.begin(), a.end());
    int minn = 1e6 + 5;
    for(int i = 1; i < n; i++)
        minn = min(minn, a[i] - a[i - 1]);

    vector<vi> res;
    for(int i = 1; i < n; i++)
        if(a[i] - a[i - 1] == minn)
            res.push_back({a[i - 1], a[i]});
    
    for(const vi& v : res)
        cout<<v[0]<<"; "<<v[1]<<" ";
    return 0;
}

// 4
// 4 2 1 3

// 5
// 1 3 6 10 15