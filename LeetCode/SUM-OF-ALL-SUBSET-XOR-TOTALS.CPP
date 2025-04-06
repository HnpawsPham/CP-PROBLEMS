#include <bits/stdc++.h>
using namespace std;
#define bit(mask, i) ((mask >> i) & 1)

int n;
const int maxn = 13;
int a[maxn];

// int sol(int i, int sum){
//     if(i == n) return sum;

//     int choose = sol(i + 1, sum ^ a[i]);
//     int notchoose = sol(i + 1, sum);

//     return choose + notchoose;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0, sum;
    for(int i = 1; i < (1 << n); i++){
        sum = 0;

        for(int j = 0; j < n; j++)
            if(bit(i, j)) sum ^= a[j];

        res += sum;
    }
    cout<<res;
    
    // cout<<sol(0, 0);
    cout<<res;
    return 0;
}