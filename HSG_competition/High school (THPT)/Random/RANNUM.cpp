#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxa = 1e6 + 5;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    vector<int> pos(maxa, -1), k(maxa, 0);

    for(int i = 0; i <n; i++){
        cin>>a[i];
        a[i] = abs(a[i]) * (1 + (a[i] > 0));
    }

    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        k[a[i]] = max(k[a[i]], i - pos[a[i]]);
        pos[a[i]] = i;
    }  
    
    for(int i = 0; i < n; i++){
        k[a[i]] = max(k[a[i]], n - pos[a[i]]);
        res = min(res, k[a[i]]);
    } 
    cout<<res;

    return 0;
}