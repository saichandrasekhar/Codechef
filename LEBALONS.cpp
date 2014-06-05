#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

#define PB push_back
#define i64 long long


i64 dp[41][41];
i64 dp2[41][41];
i64 cost[41],num[41];
i64 p2[41];

int n,m,maxc;
double ans;

void solve()
{
    int i,j;

    for(i=1;i<=maxc;++i)
    {
        if(num[i]>0)
        {
            dp[i][1]=dp[i-1][1]+p2[num[i]]-1;
            dp2[i][1]=dp2[i-1][1]+cost[i]*p2[num[i]-1];
        }
        else
        {
            dp[i][1]=dp[i-1][1];
            dp2[i][1]=dp2[i-1][1];
        }
    }

    for(i=2;i<=maxc;++i)
    {
        for(j=2;j<=i;++j)
        {
            if(num[i]>0)
            {
                dp[i][j]+=dp[i-1][j];
                dp[i][j]+=dp[i-1][j-1]*(p2[num[i]]-1);


                //printf("DD%lld\n",dp2[i][j]);

                dp2[i][j]+=dp2[i-1][j];
                //printf("DD%lld\n",dp2[i][j]);
                dp2[i][j]+=dp2[i-1][j-1]*(p2[num[i]]-1);
                //printf("DD%lld\n",dp2[i][j]);
                dp2[i][j]+=dp[i-1][j-1]*cost[i]*p2[num[i]-1];
                //printf("DD%lld\n",dp2[i][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                dp2[i][j]=dp2[i-1][j];
            }

        }
    }

    for(i=0;i<=maxc;++i)
    {
        for(j=0;j<=maxc;++j)
        {
            //printf("%lld,%lld\t",dp[i][j],dp2[i][j]);
        }

        //printf("\n");
    }

    double numerator=0;
    double denominator=0;

    for(i=m;i<=maxc;++i)
    {
        numerator+=dp2[maxc][i];
        denominator+=dp[maxc][i];
    }

    if(m==0)
    {
        ++denominator;
    }



    //printf("%lld\t%lld\n",numerator,denominator);
    //ans=numerator/(double)denominator;

    printf("%.9lf\n",(double)(numerator/denominator));

}


void prepo()
{
    int i,j;
    p2[0]=1;

    for(i=1;i<41;++i)
    {
        p2[i]=p2[i-1]*2;
    }
}

int main() {

    freopen("Text/LEBALONS.txt","r",stdin);
    int cases,i,j,x,y;

    scanf("%d",&cases);

    //printf("%d\n",cases);

    prepo();

    while(cases--)
    {
        maxc=0;
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        memset(cost,0,sizeof(cost));
        memset(num,0,sizeof(num));

        scanf("%d %d",&n,&m);

        for(i=0;i<n;++i)
        {
            scanf("%d %d",&x,&y);
            //printf("%d\t%d\n",x,y);

            cost[x]+=y;
            ++num[x];
            if(x>maxc)
            {
                maxc=x;
            }
        }

        solve();

        //printf("%.9lf\n",ans);

    }

	return 0;
}
