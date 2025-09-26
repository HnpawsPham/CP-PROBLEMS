#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'

int tc;

int sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    if(n == 2) return 0;
    return min(a[n - 2] - a[0], a[n - 1] - a[1]);
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 3
// 3
// 2 8 3
// 5
// 2 4 9 6 5
// 2
// 1 100
