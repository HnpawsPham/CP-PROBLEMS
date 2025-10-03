#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

string sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            for(int k = 0; k < n; k++)
                if(k != j && a[i] + a[j] == a[k]) return "YES";
        }

    // sort(a, a + n);

    // for(int i = 2; i < n; i++){
    //     int l = 0, r = i - 1;
    //     while(l < r){
    //         while(a[l + 1] == 0) l++;

    //         int sum = a[l] + a[r];
    //         if(sum == a[i]) return "YES";
    //         else if(sum > a[i]) r--;
    //         else l++;
    //     }
    // }
    return "NO";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 3
// 3
// 1 2 3
// 5
// 0 1 2 6 9
// 5
// 3 1 7 -9 4