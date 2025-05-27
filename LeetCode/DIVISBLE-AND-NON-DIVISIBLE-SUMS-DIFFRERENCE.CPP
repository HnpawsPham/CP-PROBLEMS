#include <bit/stdc++.h>
using namespace std;
#define el "\n"

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int sum = 0, sum1 = 0;

    for(int i = 1; i <= n; i++)
        if(i % m == 0) sum += i;
        else sum1 += i;

    cout<<sum1 - sum;
    return 0;
}