#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin>>t[i];

    vector<int> a = {t[0]};
    a.push_back(t[0]);
    for(int i = 1; i < n; i++)
        if(t[i] != t[i - 1]) a.push_back(t[i]);
    a.push_back(a.back());

    int cnt = 0, m = a.size();
    for(int i = 1; i < m - 1; i++){
        if((a[i - 1] < a[i] && a[i + 1] < a[i])
        || (a[i - 1] > a[i] && a[i + 1] > a[i])) 
        cnt++;
    }
    cout<<cnt;
    return 0;
}

// 6
// 2 4 1 1 6 5