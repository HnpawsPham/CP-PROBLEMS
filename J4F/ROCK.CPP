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

int n, k;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n, greater<int>());

    int res[n];
    memset(res, -1, sizeof res);
    int pos = 0;
    for(int i = 0; i + k - 1 < n; i++){
        if(res[i] != -1) continue;

        for(int j = i; j < n; j += k)
            res[j] = a[pos++];
    }
    
    int sum = 0;
    for(int i = 0; i + k < n; i++)  
        sum += res[i] - res[i + k];
    cout<<sum;
    return 0;
}

// 6 3
// 5 2 7 1 10 3