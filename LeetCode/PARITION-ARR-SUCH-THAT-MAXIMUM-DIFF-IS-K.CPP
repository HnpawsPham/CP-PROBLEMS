#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    int cnt = 1, minn = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] - minn > k){
            minn = a[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}