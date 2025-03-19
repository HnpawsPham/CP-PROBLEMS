#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second
#define INF (int)1e6 + 5;

int n;
map<int, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(n--){
        int x; cin>>x;
        mp[x]++;
    }
    int maxnum = -INF;
    int maxfreq = 0;
    int minnum = INF;
    int minfreq = INF;
    for(pii x : mp){
        if(x.se >= maxfreq){
            maxnum = x.fi;
            maxfreq = x.se;
        }
        if(x.se < minfreq){
            minnum = x.fi;
            minfreq = x.se;
        }
    }
    cout<<maxnum<<" "<<maxfreq<<el;
    cout<<minnum<<" "<<minfreq;

    return 0;
}