#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, key, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>key>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> res;
    int l, r, st = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == key){
            l = max(st, i - k);
            r = min(n - 1, i + k);

            while(l <= r)
                res.push_back(l++);

            st = r + 1;
        }
    for(int x : res) cout<<x<<" ";
    return 0;
}