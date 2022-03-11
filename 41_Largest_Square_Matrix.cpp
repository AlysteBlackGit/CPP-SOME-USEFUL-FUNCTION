#include <bits/stdc++.h>
using namespace std;
int DFS(int a[100][100], int x, int y, int matrix_order)
{
    int temp_maximum = matrix_order;
    bool Zero_checking = false;
    for (int i = x; i <= x + temp_maximum - 1; i++)
    {
        if (i == x || i == x + temp_maximum - 1)
            for (int j = y; j <= y + temp_maximum - 1; j++){
                if (a[i][j] == 0)
                {
                    Zero_checking = true; 
                    break;
                }
            }
        else if (i > x && i < x + temp_maximum - 1 && (a[i][y] == 0 || a[i][y + temp_maximum - 1] == 0)){
            Zero_checking = true;    
        }
        if (Zero_checking){
            return DFS(a, x, y, --temp_maximum);
            break;
        }
    }
    return temp_maximum;
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n, row = 0, col = 0;
        cin >> n;
        int a[100][100];
        for (int i = 0; i <= n + 10; i++)
            for (int j = 0; j <= n + 10; j++)
                a[i][j] = 0;
        int maximum = 0;
        cin.ignore();
        string s[1000];
        for (int i = 1; i <= n; ++i){
            getline(cin, s[i]);
            ++row;
            col = 0;
            for (int j = 0; j < s[i].length(); ++j){
                if (s[i][j] == 'X'){
                    ++col;
                    a[row][col] = 1;
                }
                else if (s[i][j] == 'O'){
                    ++col;
                    a[row][col] = 0;
                }
            }
        }
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++)
                if (a[i][j] == 1)
                {
                    int k = DFS(a, i, j, n);
                    if (k > maximum)
                        maximum = k;
                }
        cout << maximum << endl;
    }
}
