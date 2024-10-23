#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    freopen(".\\txt\\FIRS.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int cnt = 0, last = 0;
    int a[n];
    bool check[n] = {false};
    for(int i = 0; i < n;i++) cin>>a[i];

    while(true){
        int pos = lower_bound(a, a + n, last) - a;

        while(pos < n && check[pos]) pos++;
        if(pos == n || check[pos]) break;
        
        last = a[pos];
        check[pos] = 1;
        if (pos - 1 >= 0) check[pos - 1] = 1; 
        if (pos + 1 < n) check[pos + 1] = 1; 
        cnt++;
    }
    cout<<cnt<<el;
    return 0;
}