#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
vector<int> a;

int findDominant(){
    int res = a[0], cnt = 1;

    for(int i = 1; i < n; i++){
        if(a[i] == res) cnt++;
        else cnt--;

        if(cnt == 0){
            res = a[i];
            cnt = 1;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    int x = findDominant(), freq = 0, cnt = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == x) freq++;
    

    for(int i = 0; i < n; i++){
        if(a[i] == x){
            cnt++;
            freq--;
        }

        if(cnt * 2 > i + 1 && freq * 2 > n - i - 1) return cout<<i, 0;
    }
    cout<<-1;
    return 0;
}