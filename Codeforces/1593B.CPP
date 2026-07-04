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
const int fi[4] = {0, 2, 5, 7};
const char* se = "0505";

int sol(){
    string s;
    cin>>s;
    int n = s.length();

    int minn = 20;
    int last[10];
    memset(last, -1, sizeof last);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(s[i] == se[j] && last[fi[j]] != -1)
                minn = min(minn, n - last[fi[j]] - 2);
                // cout<<i - last[fi[j]] - 1 + n - i - 1<<el;
        }
        // cout<<minn<<el;
        last[s[i] - '0'] = i;
    }
    return minn;
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