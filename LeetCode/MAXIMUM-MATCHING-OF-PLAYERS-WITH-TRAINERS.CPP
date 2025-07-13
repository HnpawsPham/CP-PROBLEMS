#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int j = 0; j < m; j++) cin>>b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0, cnt = 0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            cnt++;
            i++;
            j++;
        }
        else j++;
    }
    cout<<cnt;
    return 0;
}