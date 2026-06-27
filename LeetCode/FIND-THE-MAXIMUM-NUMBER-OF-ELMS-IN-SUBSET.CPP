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
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<ll, int> cnt;
    for(int x : a) cnt[x]++;

    int res = max(1, cnt[1] - (cnt[1] % 2 == 0));

    for(int x : a){
        if(x == 1) continue;

        int d = 0;
        ll tmp = x;
        while(cnt[tmp]){
            d++;
            if(cnt[tmp] >= 2 && cnt[tmp * tmp]){
                tmp *= tmp;
                d++;
            }
            else break;
        }
        res = max(res, d);
    }
    cout<<res;
    return 0;
}

// 5
// 5 4 1 2 2

// 4
// 1 3 2 4

// 4
// 2 4 16 256
