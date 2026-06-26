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

int n, m, k, x;
string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k>>x>>s;
    string a[m];
    for(int i = 0; i < m; i++){
        cin>>a[i];
        sort(a[i].begin(), a[i].end());
    }

    int powk[m + 1] = {1};
    for(int i = 1; i <= m; i++){
        if(1LL * powk[i - 1] * 1LL * k <= 1LL * x)
            powk[i] = powk[i - 1] * k;
        else powk[i] = x;
    }
    
    int pos = 1;
    for(int i = 0; i < n; i++){
        if(s[i] != '#') continue;

        s[i] = a[pos - 1][(x - 1) / powk[m - pos]];
        x = (x - 1) % powk[m - pos] + 1;
        pos++;
    }
    cout<<s;
    return 0;
}