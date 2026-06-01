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
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n == 1) return cout<<a[0], 0;
    if(n == 2) return cout<<a[0] + a[1], 0;
    sort(a.begin(), a.end());  
    
    int sum = 0, i = n - 1;
    for(; i > 0; i-=3)
        sum += a[i] + a[i - 1];

    while(i >= 0) sum += a[i--];
    cout<<sum;
    return 0;
}

// 6
// 6 5 7 9 2 2