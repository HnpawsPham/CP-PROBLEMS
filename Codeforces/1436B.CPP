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

void sol(){
    int n;
    cin>>n;

    bool a[n][n];
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++)
        a[i][i] = a[i][n - i - 1] = 1;

    if(n % 2) a[0][n / 2] = a[n / 2][n / 2 + 1] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<a[i][j]<<" ";
        cout<<el;
    }
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
    }
    return 0;
}