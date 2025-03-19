#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 105;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i<n;i++) cin>>a[i];
    cin>>m;

    int res = 0;

    while(m--){
        int k;
        cin>>k;
        bool ok = 1;

        while(k--){
            int x;
            cin>>x;
            for(int i = 0; i<n;i++) if(x == a[i]) ok = 0;
        }
        if(ok) res++;
    }

    cout<<res;

    return 0;
}