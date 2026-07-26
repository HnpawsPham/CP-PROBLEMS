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

    int n, m;
    cin>>n>>m;
    string a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i  <m; i++) cin>>b[i];
    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0, common = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            common++;
            i++;
            j++;
        }
        else if(a[i] < b[j]) i++;
        else j++;
    }
  
    if(n - common / 2 > m - (common + 1) / 2)
        cout<<"YES";
    else cout<<"NO";
    return 0;
}