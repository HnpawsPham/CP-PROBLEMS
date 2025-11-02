#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, q;
int a[10][27];

int sol(string s){
    int st = s.find('(');
    if(st == string::npos)
        return a[s[1] - '1'][s[0] - 'A'];

    bool ok = 0;
    int lvl = 0, sz = s.length();
    string pl, pr;

    for(int i = st + 1; i < sz - 1; i++){
        if(s[i] == '(') lvl++;
        if(s[i] == ')') lvl--;
        if(s[i] == ',' && lvl == 0) {
            ok = 1;
            continue;
        }

        if(!ok) pl.push_back(s[i]);
        else pr.push_back(s[i]);
    }

    int l = sol(pl);
    int r = sol(pr);

    if(s.substr(0, 3) == "SUM") return l + r;
    return max(l, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin>>a[i][j];

    cin>>q;
    while(q--){
        string s;
        cin>>s;
        cout<<sol(s)<<el;
    }

    return 0;
}

// 4 3
// 2 1 9
// 1 5 3
// 4 3 6
// 3 2 2
// 3
// SUM(A1,B2)
// MAX(A1,B2)
// SUM(C4,C1)

// 4 3
// 2 1 9
// 1 5 3
// 4 3 6
// 3 2 2
// 2
// SUM(MAX(A1,B2),SUM(C3,C4))
// SUM(C4,MAX(C2,C3))