#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, q;
const int maxn = 1005;
vector<vector<int>> a(maxn, vector<int>(maxn, 0));

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;

    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n; j++){
            char x; cin>>x;
            a[i][j] = (x == '*');
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
        }

    while(q--){
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;

        cout<<(a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1])<<el;
    }

    return 0;
}