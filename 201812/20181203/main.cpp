#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

struct ip
{
    int digit[4];
    int len;
    long long addr;
    pair<long long, long long> ip_range;
    ip(int d0, int d1, int d2, int d3, int l)
    {
        digit[0] = d0; digit[1] = d1; digit[2] = d2; digit[3] = d3;
        len = l;
        addr = 0;
        long long p = 1;
        for (int i = 0; i < 4; i++)
        {
            addr += p * digit[i];
            p *= 256;
        }
        long long tail = pow(2, 32 - len);
        long long s = (addr / tail) * tail;
        long long t = s + pow(2, 32 - len) - 1;
        ip_range = pair<long long, long long> (s, t);
        //printf("%d.%d.%d.%d/%d\n", d3, d2, d1, d0, len);
    }

};

vector<ip> ips;
int n;

ip parse_ip(string str)
{
    if (str.find("/") == string::npos)
    {
        int a = 0, b = 0, c = 0, d = 0;
        int r = sscanf(str.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
        ip ret = ip(d, c, b, a, r * 8);
        return ret;
    }
    int pos = str.find("/");
    string ls = str.substr(pos + 1, str.size() - pos - 1);
    int len;
    sscanf(ls.c_str(), "%d", &len);
    int a = 0, b = 0, c = 0, d = 0;
    sscanf(str.substr(0, pos).c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
    ip ret = ip(d, c, b, a, len);
    return ret;
}

bool cmp(ip& p1, ip& p2)
{
    if (p1.addr != p2.addr)
        return p1.addr < p2.addr;
    return p1.len < p2.len;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char buf[32];
        scanf("%s", buf);
        ip p = parse_ip(buf);
        ips.push_back(p);
    }
    sort(ips.begin(), ips.end(), cmp);

    for (int i = 0; i < ips.size() - 1; i++)
    {
        ip p1 = ips[i];
        ip p2 = ips[i + 1];
        pair<long long, long long>& pa1 = p1.ip_range;
        pair<long long, long long>& pa2 = p2.ip_range;
        //printf("%lld %lld, %lld %lld\n", pa1.first, pa1.second, pa2.first, pa2.second);
        if (pa1.first <= pa2.first && pa1.second >= pa2.second)
        {
            ips.erase(ips.begin() + i + 1);
            if (i + 1 <= ips.size() - 1)
                i--;
        }
    }

    for (int i = 0; i < ips.size() - 1; i++)
    {
        ip p1 = ips[i];
        ip p2 = ips[i + 1];
        if (p1.len == p2.len)
        {
            ip ipnew = ip(p1.digit[0], p1.digit[1], p1.digit[2], p1.digit[3], p1.len - 1);
            if (p1.ip_range.first == ipnew.ip_range.first && p1.ip_range.second + 1 == p2.ip_range.first && p2.ip_range.second == ipnew.ip_range.second)
            {
                ips.erase(ips.begin() + i + 1);
                ips[i] = ipnew;
                if (i - 1 >= 0)
                    i--;
                i--;
            }
        }
    }

    for (int i = 0; i < ips.size(); i++)
    {
        printf("%d.%d.%d.%d/%d\n", ips[i].digit[3], ips[i].digit[2], ips[i].digit[1], ips[i].digit[0], ips[i].len);
    }
    return 0;
}
