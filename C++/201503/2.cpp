#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Object
{
public:
    Object(int n){num = n; time = 1;}
    int num;
    int time;
};

vector<Object> v;

void increase(int i)
{
    for (vector<Object>::iterator it = v.begin(); it != v.end(); it++)
        if ((*it).num == i)
        {
            (*it).time++;
            return;
        } else if ((*it).num > i){
            v.insert(it, Object(i));
            return;
        }
    v.insert(v.end(), Object(i));   //i is max in this case
}

bool cmp(Object o1, Object o2)
{
    return o1.time > o2.time;
}

int main(void)
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int j;
        cin>>j;
        increase(j);
    }

    stable_sort(v.begin(), v.end(), cmp);   //sort is not stable

    for (vector<Object>::iterator it = v.begin(); it != v.end(); it++)
        cout<<it->num<<" "<<it->time<<endl;
}


