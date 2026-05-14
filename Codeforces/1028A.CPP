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

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] != 'B') continue;

            int i1 = i, j1 = j;
            while(i1 < n - 1 && a[i1 + 1][j1] == 'B') i1++; 
            while(j1 < m - 1 && a[i1][j1 + 1] == 'B') j1++;
            
            return cout<<i + (i1 - i + 1)/ 2 + 1<<" "<<j + (j1 - j + 1) / 2 + 1, 0;
        }
    cout<<(n + 1) / 2 <<" "<<(m + 1) / 2;
    return 0;
}