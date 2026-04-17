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

int inv(int x){
    int res = 0;
    while(x > 0){
        res = res * 10 + (x % 10);
        x /= 10;
    }
    return res;
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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, int> mp;
    int minn = n + 5;
    for(int i = 0; i < n; i++){
        int x = inv(a[i]);
   
        if(mp.find(a[i]) != mp.end()) 
            minn = min(minn, abs(i - mp[a[i]]));

        mp[x] = i;
    }
    cout<<(minn == n + 5 ? -1 : minn);
    return 0;
}

// 5
// 12 21 45 33 54

// 2
// 120 21