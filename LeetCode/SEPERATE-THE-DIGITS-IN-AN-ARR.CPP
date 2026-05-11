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
    int a[n];
    for(int i = 0;i < n; i++) cin>>a[i];

    vector<int> res, tmp;
    for(int x : a){
        while(x > 0){
            tmp.push_back(x % 10);
            x /= 10;
        }
        
        while(!tmp.empty()){
            res.push_back(tmp.back());
            tmp.pop_back();
        }
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 4
// 13 25 83 77