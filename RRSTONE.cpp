#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <set>
#include <queue>

using namespace std;
#define i64 long long

#define maxn 100001

struct pt
{
    i64 a,b;

    bool operator<(const pt &y) const
    {
        return a<y.a;
    }
};

pt ar[maxn];
i64 n,k,mxx,mx2;
int mx,mn;


int main()
{
    freopen("C:/Users/Deepak/Desktop/Deepak/Programs/Codechef/Text/RRSTONE.txt","r",stdin);

    int i,j,temp;

    scanf("%lld %lld",&n,&k);
    mx=mn=0;

    for(i=0;i<n;++i)
    {
        scanf("%d",&temp);
        ar[i].a=temp;
        ar[i].b=i;

        if(ar[mn].a>ar[i].a)
        {
            mn=i;
        }
        else if(ar[mx].a<ar[i].a)
        {
            mx=i;
        }
    }

    if(k!=0)
    {
        mxx=ar[mx].a-ar[mn].a;
        mx2=ar[mx].a;

        for(i=0;i<n;++i)
        {
            ar[i].a=mx2-ar[i].a;
        }

        if(!(k&1))
        {
            for(i=0;i<n;++i)
            {
                ar[i].a=mxx-ar[i].a;
            }
        }
    }

    for(i=0;i<n-1;++i)
    {
        printf("%lld ",ar[i].a);
    }

    printf("%lld\n",ar[i].a);

    //sort(ar,ar+n);

    return 0;
}

