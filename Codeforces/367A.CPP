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

    string s;
    int q;
    cin>>s>>q;

    int n = s.length();
    int cnt[n + 1][3] = {0};
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++){
            cnt[i][j] = cnt[i - 1][j];
            if(s[i - 1] - 'x' == j) cnt[i][j]++;
        }
    while(q--){
        int l, r;
        cin>>l>>r;
        if(r - l + 1 <= 2){
            cout<<"YES"<<el;
            continue;
        }

        int maxx = max(cnt[r][0] - cnt[l - 1][0], max(cnt[r][1] - cnt[l - 1][1], cnt[r][2] - cnt[l - 1][2]));
        int minn = min(cnt[r][0] - cnt[l - 1][0], min(cnt[r][1] - cnt[l - 1][1], cnt[r][2] - cnt[l - 1][2]));
        if(maxx - minn <= 1) cout<<"YES"<<el;
        else cout<<"NO"<<el;
    }
    return 0;
}