#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, sum = 0;

int count(int x){
    int cnt = 1 + (x != 1);

    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) cnt += 2;
        if(i * i == x) cnt--;
    }

    return cnt;
}

int main(){
    freopen(".\\txt\\CONG-PHA.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i<n;i++){
        cin>>a[i];
        sum += a[i] * count(a[i]);
    }
    cout<<sum<<el;

    return 0;
}