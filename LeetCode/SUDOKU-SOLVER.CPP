#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n = 9;
vector<vector<char>> a(n, vector<char>(n, '.'));

bool check_horizon(int i, int j, char t){
    for(int x = 0; x < n; x++) 
        if(x != j && a[i][x] == t) return 0;
    return 1;
}

bool check_vertical(int i, int j, char t){
    for(int x = 0; x < n; x++) 
        if(x != i && a[x][j] == t) return 0;
    return 1;
}

bool check_block(int i, int j, char t){
    int si = (i / 3) * 3;
    int sj = (j / 3) * 3;

    for(int x = si; x < si + 3; x++)
        for(int y = sj; y < sj + 3; y++)
            if((x != i || j != y) && a[x][y] == t) return 0;
    
    return 1;
}

bool sol(int i, int j){
    if(i == n) return 1;
    
    int ii = (j == 8) ? i + 1 : i;
    int jj = (j + 1) % 9;

    if(a[i][j] == '.'){
        for(char ch = '1'; ch <= '9'; ch++)
            if(check_block(i, j, ch))
                if(check_horizon(i, j, ch))
                    if(check_vertical(i, j, ch)){
                        a[i][j] = ch;
                        if (sol(ii, jj)) return 1;
                        a[i][j] = '.';
                    }
        return 0;
    }      
    else return sol(ii, jj);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    sol(0, 0);

    cout<<el<<el;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout<<a[i][j]<<" ";
        cout<<el;
    }
    return 0;
}

// 5 3 . . 7 . . . .
// 6 . . 1 9 5 . . .
// . 9 8 . . . . 6 .
// 8 . . . 6 . . . 3
// 4 . . 8 . 3 . . 1
// 7 . . . 2 . . . 6
// . 6 . . . . 2 8 .
// . . . 4 1 9 . . 5
// . . . . 8 . . 7 9
