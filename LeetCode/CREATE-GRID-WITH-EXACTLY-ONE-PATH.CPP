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

    vector<vector<char>> res(n, vector<char>(m, '#'));
    for(int i = 0; i < m; i++)
        res[0][i] = '.';
    for(int i = 0; i < n; i++)
        res[i][m - 1] = '.';
        
    for(const vector<char>& v : res){
        for(const char& x : v)
            cout<<x<<" ";
        cout<<el;
    }
    return 0;
}