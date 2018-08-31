#include <iostream>

using namespace std;

int days_normal[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_of_normal_year = 365;
int days_of_leap_year = 366;

bool isLeap(int y)
{
    if (y % 400 ==0)
        return true;
    else if (y % 100 != 0 && y % 4 == 0)
        return true;
    return false;
}

/** 1849/12/31 Mon. */
int getLastDayOfMonth(int y, int m)
{
    int days_before_y = 0;
    for (int i = 1850; i < y; i++)
        if(isLeap(i)) days_before_y += 366;
        else days_before_y += 365;

    int days_of_y = 0;
    int *a;
    if (isLeap(y))
        a = days_leap;
    else a = days_normal;
    for (int i = 0; i < m; i++)
        days_of_y += a[i];

    int total_days = days_before_y + days_of_y;

    return 1 + total_days % 7;
}

int main(void)
{
    int a,b,c,y1,y2;

    cin>>a>>b>>c>>y1>>y2;

    int global_count = 0;

    for (int y = y1; y <= y2; y++)
    {
        int day_of_previous_month;  //the day of the last day of the previous month
        if (a == 1)
            day_of_previous_month = getLastDayOfMonth(y - 1, 12);
        else day_of_previous_month = getLastDayOfMonth(y, a - 1);

        int d = day_of_previous_month;
        int count = 0;

        if (a == 2 && isLeap(y))
        {
            for (int i = 1; i <= 29; i++)
            {
                d = d + 1;
                if (d == 8) d = 1;
                if (d == c)
                    count++;
                if (count == b)
                {
                    global_count++;
                    cout<<y<<"/"<<(a < 10 ? "0" : "")<<a<<"/"<<(i < 10 ? "0" : "")<<i<<endl;
                    break;
                }
            }
        } else
        {
            for (int i = 1; i <= days_normal[a - 1]; i++)
            {
                d = d + 1;
                if (d == 8) d = 1;
                if (d == c)
                    count++;
                if (count == b)
                {
                    global_count++;
                    cout<<y<<"/"<<(a < 10 ? "0" : "")<<a<<"/"<<(i < 10 ? "0" : "")<<i<<endl;
                    break;
                }
            }
        }
    }

    if (global_count == 0)
        cout<<"none";
}
