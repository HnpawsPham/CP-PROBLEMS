#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
vector<vector<string>> res;
vector<string> a;
bool horizon[10] = {0},
     vertical[10] = {0};

bool check(int i, int j){
    if(horizon[j]) return 0;
    if(vertical[i]) return 0;

    for(int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--)
        if(a[x][y] == 'Q') return 0;

    for(int x = i - 1, y = j + 1; x >= 0 && y < n; x--, y++)
        if(a[x][y] == 'Q') return 0;
    return 1;
}

void sol(int i){
    if(i == n) {
        res.push_back(a);
        return;
    }

    for(int j = 0; j < n; j++)
        if(check(i, j)){
            horizon[j] = vertical[i] = 1;
            a[i][j] = 'Q';
            sol(i + 1);
            a[i][j] = '.';
            horizon[j] = vertical[i] = 0;
        }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    a.assign(n, string(n, '.'));

    sol(0);

    for(auto v : res){
        for(auto x : v) cout<<x<<el;
        cout<<el;
    }
    return 0;
}