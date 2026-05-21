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

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    bool check[n] = {0};

    int maxx[m] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            maxx[j] = max(maxx[j], int(a[i][j] - '0'));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m && !check[i]; j++)
            if(int(a[i][j] - '0') == maxx[j])
                check[i] = 1;
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += check[i];
    cout<<cnt;
    return 0;
}