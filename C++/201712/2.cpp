#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(i+1);
    }

    vector<int>::iterator it=v.begin();
    int m=1;

    while(v.size()>1)
    {
        if(m%k==0||m%10==k)
        {
            v.erase(it);
        }else
        {
            it++;
        }
        if(it==v.end())
        {
            it=v.begin();
        }
        m++;
    }

    cout<<*(v.begin());

    return 0;
}


