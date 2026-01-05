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

string sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    unordered_map<int, int> mp;
    int cnt[100005] = {0};
    for(int i = 0; i < n; i++){
        cnt[a[i]]++;

        if(!mp.count(a[i]))
            mp[a[i]] = i;
        else if(mp[a[i]] < i - 1 || cnt[a[i]] > 2) 
            return "YES";
    }
    return "NO";
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
        cout<<sol()<<el;
    }
    return 0;
}

// 5
// 3
// 1 2 1
// 5
// 1 2 2 3 2
// 3
// 1 1 2
// 4
// 1 2 2 1
// 10
// 1 1 2 2 3 3 4 4 5 5