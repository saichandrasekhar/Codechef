#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>

using namespace std;

#define PB push_back
#define i64 long long


#define MOD 1000000007

//#define gc getchar_unlocked
#define gc getchar

int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;


}

int n,q;
vector<i64> a;
i64 x;


double NthRoot(double m_nValue, double index)
{
       double guess,pc;
       pc=50;
       double mn=0;
       double mx=min(1,(int)m_nValue);
       guess=(mn+mx)/2.0;
       double result = guess;
       double result_next;
       do
       {
           result_next = (1.0/index)*((index-1.0)*result+(m_nValue)/(pow(result,(index-1.0))));
           result = result_next;
           pc--;
       }while(pc>1);
       return result;
}

i64 solve()
{
    int i,j;

    i64 ret=0;
    i64 p;
    for(i=1;i<=n;++i)
    {
        //p=pow(x,1/(double)i);
        p=NthRoot(x,i);
        p%=MOD;
        p=p*a[i-1];
        p%=MOD;
        ret+=p;
        ret%=MOD;
    }

    return ret;
}



int main()
{

    freopen("Text/FUNC.txt","r",stdin);

    int cases,i,j;
    i64 tl;

    scanf("%d",&cases);

    while(cases--)
    {
        a.clear();
        scanf("%d %d",&n,&q);

        for(i=0;i<n;++i)
        {
            scanf("%lld",&tl);
            a.PB(tl);
        }

        for(i=1;i<=q;++i)
        {
            scanf("%lld",&x);
            if(i<q)
            {
              printf("%lld ",solve());
            }
            else
            {
                printf("%lld\n",solve());
            }

        }

    }

	return 0;
}
