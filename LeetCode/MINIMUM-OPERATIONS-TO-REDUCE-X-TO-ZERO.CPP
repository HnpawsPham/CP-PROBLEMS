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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, int> mp;
    int sum = 0, len = -1;
    int total = accumulate(a, a + n, 0);

    if(k == total) return n;

    mp[0] = -1;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(mp.count(sum - total + k))
            len = max(len, i - mp[sum - total + k]);

        if(!mp.count(sum)) 
            mp[sum] = i;
    }
    cout<<(len != -1 ? n - len : -1);
    return 0;
}

// 5 5
// 1 1 4 2 3