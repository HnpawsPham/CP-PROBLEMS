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

    int j = 0, cnt = 0;
    for(int x : a){
        if(x != k){
            swap(x, a[j++]);
            cnt++;
        }
    }
    a.erase(a.begin() + cnt, a.end());

    cout<<a.size()<<el;
    for(int x : a) cout<<x<<" ";

    return 0;
}