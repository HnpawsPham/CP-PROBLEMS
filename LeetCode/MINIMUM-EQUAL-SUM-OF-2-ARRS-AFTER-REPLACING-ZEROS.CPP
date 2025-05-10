#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>n>>m;
    vi<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    int zero1 = 0, zero2 = 0, sum1 = 0, sum2 = 0;
    for(int x : a){
        if(x == 0) zero1++;
        sum1 += x;
    }

    for(int x : b){
        if(x == 0) zero2++;
        sum2 += x;
    }

    if(sum1 + zero1 > sum2 && zero2 == 0
    || sum2 + zero2 > sum1 && zero1 == 0) return cout<<-1, 0;
    
    cout<<max(sum1 + zero1, sum2 + zero2);
    return 0;
}