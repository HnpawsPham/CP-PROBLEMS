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
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    int i = 0, j = 0, cnt = 0;
    int u = 0, d = n - 1, l = 0, r = m - 1;

    while(cnt < n * m){
        while(j <= r && cnt < n * m){
            cnt++;
            cout<<a[i][j++]<<" ";
        }
        j--;
        i++;
        u++;

        while(i <= d && cnt < n * m){
            cnt++;
            cout<<a[i++][j]<<" ";
        }
        i--;
        r--;
        j--;

        while(j >= l && cnt < n * m){
            cnt++;
            cout<<a[i][j--]<<" ";
        }
        j++;
        d--;
        i--;

        while(i >= u && cnt < n * m){
            cnt++;
            cout<<a[i--][j]<<" ";
        }
        i++;
        l++;
        j++;
    }
    return 0;
}