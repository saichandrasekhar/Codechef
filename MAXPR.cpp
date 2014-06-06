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

int n;
vector<int> a;
int cts[101];


int modPower(int a,int b)
{
    int ret=1;
    a%=MOD;

    while(b>0)
    {
        if(b&1)
        {
            ret*=a;
            ret%=MOD;
        }

        a*=a;
        a%=MOD;
        b/=2;
    }

    return ret;

}

int modd(int a)
{
    if(a<0)
    {
        a+=MOD;
    }
    a%=MOD;

    return a;
}


int main()
{

    freopen("Text/MAXPR.txt","r",stdin);

    int cases,t,i,j,curr;

    scanf("%d",&cases);

    while(cases--)
    {
        a.clear();
        memset(cts,0,sizeof(cts));

        scanf("%d",&n);

        for(i=0;i<n;++i)
        {
            scanf("%d",&t);
            a.PB(t);
            ++cts[t];
        }

        for(d=1;d<100;++d)
        {
            for(i=1;i<=d;++i)
            {
                k=i;
                while(k<=100)
                {
                    curr=0;
                    while(k<=100 && cts[k]==0)
                    {
                        k+=d;
                    }

                    if(k<=100)
                    {
                        while(k<=100 && cts[k]!=0)
                        {
                            curr+=cts[k];
                            k+=d;
                        }


                    }
                }
            }
        }

    }

	return 0;
}
