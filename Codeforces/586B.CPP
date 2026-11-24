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
    int a[2][n + 1], b[n];
    memset(a, 0, sizeof a);
    for(int i = 1; i < n; i++){
        int x;
        cin>>x;
        a[0][i] = a[0][i - 1] + x;
    }
    for(int i = 0; i < n - 1; i++)
        cin>>a[1][i];
    
    for(int i = n - 2; i >= 0; i--)
        a[1][i] += a[1][i + 1];
    
    for(int i = 0; i < n; i++) cin>>b[i];

    int min1 = 5005, min2 = 5005;
    for(int i = 0; i < n; i++){
        int cur = a[0][i] + b[i] + a[1][i];
        if(cur < min1){
            min2 = min1;
            min1 = cur; 
        }
        else if(cur < min2) 
            min2 = cur;
    }
    cout<<min1 + min2;
    return 0;
}