#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vi gud(32), res(n);
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 32; j++){
            if(a[i] & (1 << j))
                gud[j] = i;  
        }

        int pos = i;
        for(int j = 0; j < 32; j++){
            if(gud[j] != -1) 
                pos = max(pos, gud[j]);
        }
        res[i] = pos - i + 1;
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}