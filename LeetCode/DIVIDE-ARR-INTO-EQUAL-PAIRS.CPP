#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n % 2) return cout<<"false", 0;
    sort(a, a + n);
    
    for(int i = 0; i < n; i+= 2)
        if(a[i] != a[i + 1]) return cout<<"false",0;
    return cout<<"true", 0;
}