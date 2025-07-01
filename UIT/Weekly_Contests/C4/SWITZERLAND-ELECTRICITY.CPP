#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    bool a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int i = 0, cnt = 0;
    bool ok = 0;

    while(i < n){
        int l = max(0, i - k + 1);
        int r = min(n - 1, i + k - 1);

        for(int j = r; j >= l; j--)
            if(a[j]){
                ok = 1;
                i = j + k;
                break;
            }
        
        if(!ok) return cout<<-1, 0;
        ok = 0;
        cnt++;
    }
    cout<<cnt;
    return 0;
}