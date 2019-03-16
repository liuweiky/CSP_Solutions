#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <sstream>
#include <climits>
#include <algorithm>

#define TRUE -1
#define FALSE -2

using namespace std;

int P, R, U, Q;
map<string, int> pri_max_lev;
map<string, vector<pair<string, int> > > role_priv;
map<string, vector<string> > user_roles;

void add_priv(string s)
{
    int pos = s.find(":");
    if (pos == string::npos)
        pri_max_lev[s] = -1;
    else
    {
        string name = s.substr(0, pos);
        string slevel = s.substr(pos + 1, s.size() - pos - 1);
        stringstream ss;
        ss << slevel;
        int level;
        ss >> level;
        pri_max_lev[name] = level;
    }
}

void add_role_priv(string role_name, pair<string, int> priv)
{
    if (role_priv.find(role_name) == role_priv.end())
    {
        vector<pair<string, int> > v;
        role_priv[role_name] = v;
    }
    role_priv[role_name].push_back(priv);
}

void add_user_role(string uname, string rname)
{
    if (user_roles.find(uname) == user_roles.end())
    {
        vector<string> v;
        user_roles[uname] = v;
    }
    user_roles[uname].push_back(rname);
}

pair<string, int> parse_priv(string s)
{
    pair<string, int> p;
    int pos = s.find(":");
    if (pos == string::npos)
    {
        p.first = s;
        p.second = -1;
    }
    else
    {
        string name = s.substr(0, pos);
        string slevel = s.substr(pos + 1, s.size() - pos - 1);
        stringstream ss;
        ss << slevel;
        int level;
        ss >> level;
        p.first = name;
        p.second = level;
    }
    return p;
}

int q1(string uname, string priv)
{
    vector<string> roles = user_roles[uname];

    for (int i = 0; i < roles.size(); i++)
    {
        string r = roles[i];
        vector<pair<string, int> > r_priv = role_priv[r];
        for (int j = 0; j < r_priv.size(); j++)
        {
            if (priv == r_priv[j].first)
                return TRUE;
        }
    }
    return FALSE;
}

int q2(string uname, string priv, int level)
{
    vector<string> roles = user_roles[uname];

    for (int i = 0; i < roles.size(); i++)
    {
        string r = roles[i];
        vector<pair<string, int> > r_priv = role_priv[r];
        for (int j = 0; j < r_priv.size(); j++)
        {
            if (priv == r_priv[j].first && level <= r_priv[j].second)
                return TRUE;
        }
    }
    return FALSE;
}

int q3(string uname, string priv)
{
    int max_priv = INT_MIN;
    vector<string> roles = user_roles[uname];

    for (int i = 0; i < roles.size(); i++)
    {
        string r = roles[i];
        vector<pair<string, int> > r_priv = role_priv[r];
        for (int j = 0; j < r_priv.size(); j++)
        {
            if (priv == r_priv[j].first)
                max_priv = max(max_priv, r_priv[j].second);
        }
    }
    return max_priv == INT_MIN ? FALSE : max_priv;
}

int query(string uname, string priv)
{
    pair<string, int> p = parse_priv(priv);

    if (pri_max_lev[p.first] == -1)
        return q1(uname, p.first);

    if (p.second != -1)
        return q2(uname, p.first, p.second);

    return q3(uname, p.first);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> P;

    for (int i = 0; i < P; i++)
    {
        string inbuf;
        cin >> inbuf;
        add_priv(inbuf);
    }

    cin >> R;

    for (int i = 0; i < R; i++)
    {
        string rname;
        int pnum;
        cin >> rname >> pnum;
        for (int j = 0; j < pnum; j++)
        {
            string inbuf;
            cin >> inbuf;
            add_role_priv(rname, parse_priv(inbuf));
        }
    }

    cin >> U;

    for (int i = 0; i < U; i++)
    {
        string name;
        int rnum;
        cin >> name >> rnum;
        for (int j = 0; j < rnum; j++)
        {
            string inbuf;
            cin >> inbuf;
            add_user_role(name, inbuf);
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        string uname, inbuf;
        cin >> uname >> inbuf;
        int res = query(uname, inbuf);
        if (res == TRUE)
            cout << "true" << endl;
        else if (res == FALSE)
            cout << "false" << endl;
        else
            cout << res << endl;
    }

    return 0;
}
