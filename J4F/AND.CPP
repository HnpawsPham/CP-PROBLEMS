#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int t, x;

void sol(){
    int n = 1, num = 1;
    while(((num << 1) | 1) - 1 <= x){
        num = ((num << 1) | 1);
        n++;
    }
    cout<<n<<el;

    for(int i = 0; i < n; i++)
        cout<<(num - (1 << i))<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>x;
        sol();
        cout<<el;
    }

    return 0;
}

// 10
// 4
// 5
// 6
// 9
// 10
// 45
// 483
// 568696
// 2346
// 690767