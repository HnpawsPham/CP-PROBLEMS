#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = 105;
int a[maxn][maxn];
vector<int> g1, g2;
bool ok = true;

void solve(vector<int> g){
    for(int i : g)
        for(int j : g)
            if(a[i][j]){
                cout<<i<<" "<<j<<el;
                ok = false;
                return;
            } 
    return;
}

int main(){
    freopen(".\\txt\\QUAN-HE.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++) cin>>a[i][j];
        
    for(int i = 0;i<n;i++)
        for(int j = 0;j<=i;j++)
            if(a[i][j]){
                g1.push_back(i);
                g2.push_back(j);
            }

    solve(g1); solve(g2);
    cout<<(ok ? "YES" : "NO")<<el;
    return 0;
}