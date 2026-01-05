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
    int a[n][n];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) cin>>a[i][j];

    ll sum = 0;
    int minn = 1e5 + 5, neg = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum += abs(a[i][j]);
            if(a[i][j] < 0) neg++;
            minn = min(minn, abs(a[i][j]));
        }
        if(neg % 2) sum -= 2 * minn;
    }
    return 0;
}

// 3
// 1 2 3
// -1 -2 -3
// 1 2 3

// 2
// -1 1
// 1 -1