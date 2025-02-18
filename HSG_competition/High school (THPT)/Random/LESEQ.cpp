#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1], p[n + 1];
    int cnt0 = 0;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        cnt0 += (a[i] == 0);
    }

    sort(a + 1, a + n + 1);
    memset(p, 0, sizeof(p));

    a[0] = a[1];
    int d = cnt0;

    for(int i = 1; i<=n; i++){
        if(a[i] == 0) continue;
        
        int x = a[i] - a[i - 1] - 1;
        p[i] = p[i - 1] * (x <= d) + 1;
        d -= x;
        if(d <= 0) d = cnt0;
    }
    for(int i = 1; i <= n; i++) cout<<p[i]<<" ";
    
    return 0;
}
// 7
// 1 0 3 8 5 9 0