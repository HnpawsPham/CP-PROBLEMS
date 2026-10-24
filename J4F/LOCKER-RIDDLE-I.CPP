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

int tc = 1;
bool a[105];

void sol(){
    int n;
    cin>>n;
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; i++) cin>>a[i];

    vi res;
    for(int i = 1; i <= n; i++)
        if(a[i]){
            res.push_back(i);
            for(int j = i; j <= n; j+=i)
                a[j] = !a[j];
        }

    cout<<res.size();
    if(res.empty()) return;
    cout<<el;
    reverse(res.begin(), res.end());
    for(const int& x : res) cout<<x<<" ";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}

// 8
// 3
// 0 0 0
// 3
// 0 0 1
// 3
// 0 1 0
// 3
// 0 1 1
// 3
// 1 0 0
// 3
// 1 0 1
// 3
// 1 1 0
// 3
// 1 1 1