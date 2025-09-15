#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int t, n;
const int maxn = 1002;
int a[maxn];

bool check(int l, int r, int x){
    return (l - 1 <= x && x <= r + 1);
}

int sol(){
    for(int i = 0; i < n; i++)
        if(i < n - 1 && abs(a[i] - a[i + 1]) <= 1)
            return 0;

    for(int i = 0; i < n - 1; i++){
        int l = min(a[i], a[i + 1]);
        int r = max(a[i], a[i + 1]);

        if(i > 0 && check(l, r, a[i - 1]))
            return 1;

        if(i < n - 2 && check(l, r, a[i + 2]))
            return 1;
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++) cin>>a[i];
        
        cout<<sol()<<el;
    }
    return 0;
}