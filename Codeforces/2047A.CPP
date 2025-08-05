#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int t, n, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        int cnt = 0, k = 0, sum = 0;
        while(n--){
            cin>>x;
            sum += x;

            while((4 * k * (k + 1) + 1) <= sum){
                if((4 * k * (k + 1) + 1) == sum)
                    cnt++;
                k++;
            }
        }
        cout<<cnt<<el;
    }
    return 0;
}