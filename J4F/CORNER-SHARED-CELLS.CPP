#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n, x, y;
    cin>>n>>m>>x>>y;

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!(i == x && j == y) && abs(i - x) <= 1 && abs(j - y) <= 1)
                cnt++;
    cout<<cnt;
    return 0;
}