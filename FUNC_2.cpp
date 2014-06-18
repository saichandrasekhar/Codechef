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
#include<bitset>
#include<map>

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VLL vector<i64>



//#define gc getchar_unlocked
#define gc getchar


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}



inline i64 readPosLLD()
{
    i64 ret=0;
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

inline i64 readLLD()
{
    i64 ret=0;
    bool negg=false;
    char c;
    c=gc();

    while((c<'0' || c>'9') && c!='-')
    {
        //scanf("%c",&c);
        c=gc();
    }

    if(c=='-')
    {
        negg=true;
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    if(negg)
    {
        ret=-ret;
    }

    return ret;
}



inline int readPosInt()
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

inline int readInt()
{
    int ret=0;
    bool negg=false;
    char c;
    c=gc();

    while((c<'0' || c>'9') && c!='-')
    {
        //scanf("%c",&c);
        c=gc();
    }

    if(c=='-')
    {
        negg=true;
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    if(negg)
    {
        ret=-ret;
    }

    return ret;
}


#define MOD 1000000007
#define RANGE 1000000000000000001LL


i64 lookup[1000001][61];

int lookupfun(i64 x,int n,i64 prev)
{
    prev=prev>1000000 ? 1000000 : prev;
    int hi=prev,lo=1,mid,res;

    while(lo<=hi)
    {
        mid=(lo+hi)>>1;

        if(lookup[mid][n]<=x)
        {
            res=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }

    return res;
}


void pre()
{
    int i,j;
    i64 f;
    FOR(i,1,1000001)
    {
        f=1;

        REP(j,60)
        {
            lookup[i][j]=f;
            if(f>(RANGE-1)/i)
            {
                f=RANGE;
            }
            else
            {
                f*=i;
            }
        }
    }
}

i64 mysqrt(i64 x)
{
    return sqrt(x);
}

i64 root(i64 x,int n,i64 pre)
{
    if(n>=60)
    {
        return 1;
    }
    if(n==1)
    {
        return x;
    }

    if(n==2)
    {
        return mysqrt(x);
    }

    return lookupfun(x,n,pre);
}

int main()
{
    freopen("Text/FUNC.txt","r",stdin);

    pre();

    int cases,i,j,n,q;
    i64 x,ans,val,inter,arr[100010],brr[100010],tll;

    scanf("%d",&cases);
    //printf("DD\n");
    while(cases--)
    {
        scanf("%d %d",&n,&q);

        REP(i,n)
        {
            scanf("%lld",arr+i);
            arr[i]%=MOD;
            if(arr[i]<0)
            {
                arr[i]+=MOD;
            }
            brr[i]=arr[i];
        }

        for(i=n-2;i>=0;--i)
        {
            brr[i]+=brr[i+1];

            brr[i]%=MOD;

            if(brr[i]<0)
            {
                brr[i]+=MOD;
            }
        }

        REP(i,q)
        {
            ans=0;
            scanf("%lld",&x);
            val=x;

            for(j=1;j<=n;++j)
            {
                val=root(x,j,val);

                if(val==1)
                {
                    ans+=brr[j-1];
                    ans%=MOD;

                    if(ans<0)
                    {
                        ans+=MOD;
                    }
                    break;
                }

                val%=MOD;
                if(val<0)
                {
                    val+=MOD;
                }

                tll=val*arr[j-1];
                tll%=MOD;
                if(tll<0)
                {
                    tll+=MOD;
                }

                ans+=tll;
                if(ans<0)
                {
                    ans+=MOD;
                }
            }

            if(i==q-1)
            {
                printf("%lld\n",ans);
            }
            else
            {
                printf("%lld ",ans);
            }
        }

        printf("\n");
    }

	return 0;
}
