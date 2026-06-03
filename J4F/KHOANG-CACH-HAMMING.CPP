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

    int n, m, k;
    cin>>n>>m>>k;
    string s, t;
    cin>>s;

    int res = n;
    while(k--){
        cin>>t;
        for(int st = 0; st < n; st++){
            int cnt = 0;
            for(int i = 0, j = st; i < m; i++, j++){
                if(j == n) j = 0;
                cnt += s[j] != t[i];
            }
            res = min(res, cnt);
        }
    }
    cout<<res;
    return 0;
}