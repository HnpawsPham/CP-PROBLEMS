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
#define taskname "LINGVO"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string mp[10];
    for(int i = 0; i < 10; i++) cin>>mp[i];
    int n;
    cin>>n;

    while(n--){
        int x;
        cin>>x;
        if(x == 0){
            cout<<mp[0]<<el;
            continue;
        }

        string res = "";
        while(x > 0){
            res = max(res, mp[x % 10]);
            x /= 10;
        }
        cout<<res<<el;
    }
    return 0;
}

// zero un deux trois quatre cinq six sept huit neuf
// 3 
// 123
// 456
// 908