//记忆化搜索 和 动态规划

#include <bits/stdc++.h>
using namespace std;
long long rpt[25][25][25];
long long w(long long a, long long b, long long c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(rpt[a][b][c] != 0)
        return rpt[a][b][c];
    else if(a > 20 || b > 20 || c > 20) rpt[a][b][c] = w(20,20,20);
    else if(a < b && b < c) rpt[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    else rpt[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    return rpt[a][b][c];
}
int main()
{
    long long a,b,c;
    while(scanf("%lld%lld%lld", &a, &b, &c) == 3)
    {
        memset(rpt,0,sizeof(rpt));
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = ",a,b,c);
        if(a > 20) a = 21;
        if(b > 20) b = 21;
        if(c > 20) c = 21;
        printf("%lld\n",w(a,b,c));
    }
    return 0;
}
