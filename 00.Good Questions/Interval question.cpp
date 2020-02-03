//Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
//For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
-------------------------------------------------------------------------------------------------------------------------------------------
//O(N^2) Approach(https://www.geeksforgeeks.org/check-if-any-two-intervals-overlap-among-a-given-set-of-intervals/)
-------------------

//Some basic pre-written functions might have been copied from www.geeksforgeeks.org or cp-algorithms.com//

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

struct Interval
{
    int start, end;
};

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

int answer(Interval a[], int n)
{
     sort(a,a+n,compareInterval);

     int count=0;
     for(int i=1;i<n;i++)
     {
         for(int j=0;j<i;j++)
         {
             if(a[j].end > a[i].start)
             {
                 count++;
             }
         }
     }
     return count;
}

int32_t main()
{   IOS;

    int n;
    cin >> n;
    Interval a[n];

    for(int i=0;i<n;i++)
    {
        cin >> a[i].start >> a[i].end;
    }

    int k = sizeof(a) / sizeof(a[0]);

    cout << answer(a,k);
    return 0;
}
