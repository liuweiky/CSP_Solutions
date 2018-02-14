#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int a[1024];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int min=10000;  //题目说明给定的数不超过10000

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int m=a[i]-a[j];
            m=abs(m);
            if(m<min)
                min=m;
        }
    }

    cout<<min;
    return 0;
}
