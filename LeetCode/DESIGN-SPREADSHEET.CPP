#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

class Spreadsheet {
public:
    vector<vi> a;

    Spreadsheet(int n) {
        a.assign(26, vi(n, 0));    
    }
    
    pii getCell(string cell){
        int i = int(cell[0] - 'A');
        int j = stoi(cell.substr(1)) - 1;
        return {i, j};
    }
    
    void setCell(string cell, int val) {
        auto [i, j] = getCell(cell);
        a[i][j] = val;
    }
    
    void resetCell(string cell) {
        auto [i, j] = getCell(cell);
        a[i][j] = 0;
    }
    
    int getValue(string s) {
        string x = "", y = "";
        int n = s.length();
        for(int i = 1; i < n; i++){
            if(s[i] == '+') swap(x, y);
            else x += s[i];
        }

        int sum = 0;
        if('A' <= x[0] && x[0] <= 'Z'){
            auto[i, j] = getCell(x);
            sum += a[i][j];
        } 
        else sum += stoi(x);

        if('A' <= y[0] && y[0] <= 'Z'){
            auto[i, j] = getCell(y);
            sum += a[i][j];
        } 
        else sum += stoi(y);
        return sum;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}