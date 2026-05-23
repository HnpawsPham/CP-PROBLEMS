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

    int cnt = 0;
    for(int i = 1; i < n; i++)
        if(a[i] < a[i - 1]) cnt++;
    cnt += a[n - 1] > a[0];
    cout<<(cnt <= 1);
    return 0;
}

// 5
// 3 4 5 1 2

// 4
// 2 1 3 4