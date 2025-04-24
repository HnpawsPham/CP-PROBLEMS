#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    unordered_map<int, int> mp;
    unordered_set<int> s;

    for(int x : a) s.insert(x);

    int len = s.size(), r = 0, cnt = 0;

    for(int l = 0; l < n; l++){
        if(l > 0){
            int x = a[l - 1];
            mp[x]--;
            if(!mp[x]) mp.erase(x);
        }

        while(r < n && mp.size() < len){
            int x = a[r];
            mp[x]++;
            r++;
        }
        if(mp.size() == len)   
            cnt += (n - r + 1);
    }
    cout<<cnt;

    return 0;
}