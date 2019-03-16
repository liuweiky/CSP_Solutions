#include <cstdio>
#include <vector>
#include <algorithm>

#define IN 1
#define OUT -1

#define MAX_N 1024

using namespace std;

struct event
{
    int key_id;
    int type;
    int time_tag;
};

int N, K;

vector<event> events;
bool key_container[MAX_N];
int container_keyid[MAX_N];

bool cmp(event e1, event e2)
{
    if (e1.time_tag != e2.time_tag)
        return e1.time_tag < e2.time_tag;
    if (e1.type != e2.type)
        return e1.type > e2.type;
    if (e1.type == IN)
        return e1.key_id < e2.key_id;
    return false;
}

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++)
    {
        key_container[i] = false;
        container_keyid[i] = i;
    }

    for (int i = 0; i < K; i++)
    {
        int w, s, c;
        scanf("%d %d %d", &w, &s, &c);
        event e1, e2;
        e1.key_id = e2.key_id = w;
        e1.time_tag = s; e1.type = OUT;
        e2.time_tag = s + c; e2.type = IN;
        events.push_back(e1);
        events.push_back(e2);
    }

    sort(events.begin(), events.end(), cmp);

    for (int i = 0; i < events.size(); i++)
    {
        event& e = events[i];
        if (e.type == OUT)
        {
            for (int j = 1; j <= N; j++)
            {
                if (container_keyid[j] == e.key_id)
                {
                    key_container[j] = true;
                    break;
                }
            }
        }
        else
        {
            for (int j = 1; j <= N; j++)
            {
                if (key_container[j])
                {
                    container_keyid[j] = e.key_id;
                    key_container[j] = false;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", container_keyid[i]);
    }

    return 0;
}
