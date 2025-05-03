#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n][m];
    bool r[n], c[m];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 0)
                r[i] = c[j] = 1;
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(r[i] || c[j]) a[i][j] = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout<<a[i][j]<<" ";
        cout<<el;
    }
        
    return 0;
}