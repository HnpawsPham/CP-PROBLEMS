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
const int maxn = 1005;
int maxcol[maxn];

vector<vi> rotate90(const vector<vi> a){
    vector<vi> res(m, vi(n));
 
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++) 
            res[j][i] = a[i][m - j - 1];
    return res;
}

void print(const vector<vi>& a){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout<<a[i][j]<<" ";
        cout<<el;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> a(n, vi(m)), check(n, vi(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int cnt = 0;
    for(int x = 0; x < 4; x++){
        memset(maxcol, 0, sizeof maxcol);

        for(int j = 0; j < m; j++)
            for(int i = 0; i < n; i++)
                if(a[i][j] > maxcol[j]){
                    if(!check[i][j]){
                        cnt++;
                        check[i][j] = 1;
                    }
                    maxcol[j] = a[i][j];        
                }
                
        a = rotate90(a);
        check = rotate90(check);
        swap(n, m);
    }
    cout<<cnt;
    return 0;
}

// 4 4
// 2 3 5 3
// 2 1 2 2
// 3 4 3 4
// 2 1 3 3