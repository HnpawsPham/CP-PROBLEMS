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

int n;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int res[n];
    int j = 0;
    for(int i = 1; i < n; i+=2)
        res[i] = a[j++];
    
    for(int i = 0; i < n; i+= 2)
        res[i] = a[j++];

    int cnt = 0;
    for(int i = 1; i < n - 1; i++)
        if(res[i] < res[i - 1] && res[i] < res[i + 1])
            cnt++;
    
    cout<<cnt<<el;
    for(int x : res) cout<<x<<" ";
    return 0;
}