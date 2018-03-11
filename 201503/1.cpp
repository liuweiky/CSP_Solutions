#include <iostream>

using namespace std;

int main(void)
{
    int n,m;
    cin>>n>>m;

    int a[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>a[i][j];

    for (int i = m-1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
            cout<<a[j][i]<<" ";
        cout<<endl;
    }
}
