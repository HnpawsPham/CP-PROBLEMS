#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int main(){
    int n, k;
    cin>>n>>k;

    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    int cnt = 0;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] == a[j] && i * j % k == 0)
                cnt++;
    cout<<cnt;
    return 0;
}