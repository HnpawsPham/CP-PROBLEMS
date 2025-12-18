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

int sol(){
    int n;
    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = n, cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == '#'){
                cnt++;
                break;
            }
    res = min(res, cnt);
    cnt = 0;

    for(int j = 0; j < n; j++)
        for(int i = 0; i < n; i++)
            if(a[i][j] == '#'){
                cnt++;
                break;
            }
    res = min(res, cnt);
    return res;
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