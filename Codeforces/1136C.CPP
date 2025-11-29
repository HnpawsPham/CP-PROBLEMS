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

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n][m], b[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>b[i][j];

    for(int s = 0; s <= n + m - 2; s++){
        multiset<int> msa, msb;
        
        for(int i = 0; i < n; i++){
            int j = s - i;
            if(j < 0 || j >= m) continue;

            msa.insert(a[i][j]);
            msb.insert(b[i][j]);
        }
        if(msa != msb) return cout<<"NO", 0;
    }
    cout<<"YES";
    return 0;
}