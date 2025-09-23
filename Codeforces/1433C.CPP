#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        int maxx = -1;
        for(int i = 0; i < n; i++) {
            cin>>a[i];
            maxx = max(maxx, a[i]);
        }

        bool ok = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != maxx) continue;
            if((i > 0 && a[i - 1] < a[i])
             || (i + 1 < n && a[i + 1] < a[i])) {
                cout<<i + 1<<el;
                ok = 1;
                break;
            }
        }
        if(!ok) cout<<-1<<el;
    }

    return 0;
}