#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int maxx = *max_element(a.begin(), a.end());

    int len = 0, res = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == maxx) len++;
        else len = 0;

        res = max(res, len);
    }
    
    cout<<res;
    return 0;
}