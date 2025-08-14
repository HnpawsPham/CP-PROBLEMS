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

    int n, m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m, '.'));
    bool draw_r = 1;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0)
            for(int j = 0; j < m; j++) a[i][j] = '#';
        
        else {
            if(draw_r) a[i][m - 1] = '#';
            else a[i][0] = '#';
            draw_r = !draw_r;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout<<a[i][j];
        cout<<el;
    }
    return 0;
}