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
    int topR[n][2], botL[n][2];
    for(int i = 0; i < n; i++) 
        cin>>topR[i][0]>>topR[i][1];
    for(int i = 0; i < n; i++) 
        cin>>botL[i][0]>>botL[i][1];

    ll res = 0;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++){
            int w = max(topR[i][0], topR[j][0]);
            int h = min(topR[i][1], topR[j][1]);
                    
            if(w < 0 || h < 0) continue;
            if(h < w) swap(w, h);
            res = max(res, 1LL * w * w);
        }
    cout<<res;
    return 0;
}