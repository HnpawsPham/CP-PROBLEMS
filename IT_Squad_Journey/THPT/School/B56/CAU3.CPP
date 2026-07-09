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
#define taskname "CAU3"

int tc = 1;
int n, m;
const int maxn = 105;
int a[maxn][maxn], b[maxn][maxn];
int ta[maxn][maxn], tb[maxn][maxn];

#define mask(i, j) (1 & (j >> i))

int id(int i, int j){
    return i * m + j;
}

void reset(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            ta[i][j] = a[i][j];
            tb[i][j] = b[i][j];
        }
    return;
}

bool check(int i, int j){
    if(j > 0 && (ta[i][j] <= ta[i][j - 1] || tb[i][j] <= tb[i][j - 1])) 
        return 0;
    if(i > 0 && (ta[i][j] <= ta[i - 1][j] || tb[i][j] <= tb[i - 1][j])) 
        return 0;
    return 1;
}

string sub1(){
    for(int it = 0; it < (1 << (n * m)); it++){
        reset();
        bool ok = 1;

        for(int i = 0; i < n && ok; i++)
            for(int j = 0; j < m && ok; j++){
                if(mask(id(i, j), it)) 
                    swap(ta[i][j], tb[i][j]);
                ok = check(i, j);
            }

        if(ok) return "Yes";
    }
    return "No";
}

string gamble(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] > b[i][j]) 
                swap(a[i][j], b[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(i > 0 && (a[i][j] <= a[i - 1][j] || b[i][j] <= b[i - 1][j]))
                return "No"; 
            if(j > 0 && (a[i][j] <= a[i][j - 1] || b[i][j] <= b[i][j - 1]))
                return "No";
        }
    return "Yes";
}

string sol(){
    cin>>n>>m;
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>b[i][j];

    if(n * m <= 16) return sub1();
    return gamble();
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}