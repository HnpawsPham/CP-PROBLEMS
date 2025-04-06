#include <bits/stdc++.h>
using namespace std;

const int n = 9;
char a[n][n];

bool check_square(int i, int j){
    bool cnt[10] = {};

    for(int u = i; u < i + 3; u++)
        for(int v = j; v < j + 3; v++){
            if(a[u][v] == '.') continue;

            if(cnt[a[u][v] - '0']) return 0;
            cnt[a[u][v] - '0'] = 1;
        }
    return 1;
}

bool check_horizontal(int i){
    bool cnt[10] = {};

    for(int j = 0; j < n; j++){
        if(a[i][j] == '.') continue;

        if(cnt[a[i][j] - '0']) return 0;
        cnt[a[i][j] - '0'] = 1;
    }
    return 1;
}

bool check_vertical(int j){
    bool cnt[10] = {};

    for(int i = 0; i < n; i++){
        if(a[i][j] == '.') continue;

        if(cnt[a[i][j] - '0']) return 0;
        cnt[a[i][j] - '0'] = 1;
    }
    return 1;
}

bool sol(){
    for(int i = 0; i < n; i++){
        if(!check_vertical(i)) return 0;
        if(!check_horizontal(i)) return 0;
    }

    for(int i = 0; i < n; i+= 3)
        for(int j = 0; j < n; j+= 3)
            if(!check_square(i, j)) return 0;

    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    cout<<sol();
    return 0;
}