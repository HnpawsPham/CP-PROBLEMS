#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = (int)1e6 + 5;
bool a[maxn] = {0};
int p[maxn], s[maxn] = {0};
int t;

bool checkTwin(int x){
    if (a[x]) return false;
    string ss = to_string(x);
    reverse(ss.begin(), ss.end());
    int rx = stoi(ss);
    return !a[rx] && rx != x && rx > 9;
}

void sieve(){
    a[0] = a[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++){
        if(!a[i])
            for(int j = i + i; j < maxn; j += i) 
                a[j] = 1;
    }
    return;
}

int main(){
    freopen(".\\txt\\TWINS.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    p[0]= s[0] = 0;

    for(int i = 1; i < maxn; i++) {
        p[i] = p[i - 1];
        if(!a[i]) p[i] += i;
        s[i] = s[i - 1] + checkTwin(i);
    }
    
    cin>>t;

    while (t--)
    {
        int l, r;
        cin>>l>>r;

        cout<<p[r] - p[l - 1]<<" "<<s[r] - s[l - 1]<<el;
    }
    
    return 0;
}