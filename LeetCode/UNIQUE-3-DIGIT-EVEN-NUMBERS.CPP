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

    int cnt[10], res = 0;
    memset(cnt, 0, sizeof cnt);
    for(const int& x : a) cnt[x]++;

    for(int i = 0; i < 10; i++){
        if(!cnt[i]) continue;
        cnt[i]--;

        for(int j = 0; j < 10; j++){
            if(!cnt[j]) continue;
            cnt[j]--;

            for(int k = 0; k < 10; k+=2)
                if(cnt[k] > 0) res++;
            cnt[j]++;
        }
        cnt[i]++;
    }
    cout<<res;
    return 0;
}