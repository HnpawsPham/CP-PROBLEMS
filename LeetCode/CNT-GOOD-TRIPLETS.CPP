#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, a, b, c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b>>c;
    int arr[n];
    int cnt = 0;

    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++)
            for(int k = j + 1; k < n; k++)
                if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    cnt++;
    cout<<cnt;
    return 0;
}