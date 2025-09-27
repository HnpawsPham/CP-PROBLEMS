#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
vector<string> a;
int dy[4] = {1, -1, 0, 0},
    dx[4] = {0, 0, 1, -1};

bool check(int i, int j){
    if(i < 0 || j < 0 || i == n || j == m) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    a.resize(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    queue<pii> q;
    vector<vi> cnt(n, vi(m, 0));
    for(int i = 0 ; i < n ;i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == '.'){
                for(int x = 0; x < 4; x++){
                    int i1 = i + dy[x];
                    int j1 = j + dx[x];
                    if(check(i1, j1) && a[i1][j1] == '#')
                        cnt[i][j]++;
                }
                if(cnt[i][j] == 1)
                    q.push({i, j});
            }
        }

    while(!q.empty()){
        int sz = q.size();
        vector<pii> v;
        
        for(int k = 0; k < sz; k++){
            auto [i, j] = q.front();
            q.pop();
            if(a[i][j] == '.' && cnt[i][j] == 1){
                a[i][j] = '#';
                v.push_back({i, j});
            }
        }
        if(v.empty()) break;

        for(auto [i, j] : v){
            for(int x = 0; x < 4; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];
                if(check(i1, j1) && a[i1][j1] == '.'){
                    if(++cnt[i1][j1] == 1) 
                        q.push({i1, j1});
                }
            }
        }   
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == '#') res++;
    cout<<res;
    return 0;
}