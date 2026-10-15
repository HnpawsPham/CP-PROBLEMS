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
const int maxn = 2e5 + 5;
int cnt[maxn];

void sol(){
    int n, k;
    string s;
    cin>>n>>k>>s;

    memset(cnt, 0, sizeof cnt);

    int tmp = k;
    for(int i = 0; i < n && k; i++){
        if((tmp % 2) == (s[i] - '0')){
            cnt[i] = 1;
            k--;
        }
    }
    cnt[n - 1] += k;

    k = tmp;
    for(int i = 0; i < n; i++){
        int p = (k - cnt[i]) % 2;
        if(p) cout<<(s[i] == '1' ? '0' : '1');
        else cout<<s[i];
    }
    
    cout<<el;
    for(int i = 0; i < n; i++)
        cout<<cnt[i]<<" ";
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
        sol();
        cout<<el;
    }
    return 0;
}