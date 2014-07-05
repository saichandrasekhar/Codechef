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

i64 MOD=1000000007;
#define MAXN 1000000

i64 a[MAXN+1];
i64 b[MAXN+1];
bitset<MAXN+1> bs;
vector<i64> vt,vc,primes;
int vsz,num_primes;
bool pr[MAXN+1];

int res[MAXN+1];
int fa[MAXN+1];

void sieve()
{
    i64 i,j;

    for(i=2;i<=MAXN;++i)
    {
        if(!pr[i])
        {
            //pr[i]=true;
            primes.PB(i);

            for(j=i*i;j<=MAXN;j+=i)
            {
                pr[j]=true;
            }
        }
    }

    num_primes=primes.size();
}


i64 gcd(i64 u, i64 v) {

  i64 t;

  if(u<v)
  {
      t=u;
      u=v;
      v=t;
  }

  while (v) {
    t = u;
    u = v;
    v = t % v;
  }
  return u < 0 ? -u : u;
}


int fast_pow(i64 base,i64 n,i64 M)
{
    if(n==0)
    {
        return 1;
    }

    if(n==1)
    {
        return base;
    }

    i64 halfn=fast_pow(base,n/2,M);

    if((n%2)==0)
    {
        return ( halfn * halfn ) % M;
    }
    else
    {
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
    }
}

int findMMI_fermat(i64 n,int M)
{
    return fast_pow(n,M-2,M);
}


int main()
{
    freopen("Text/SGARDEN.txt","r",stdin);
    int cases,i,j;
    i64 ct,gd,igd,n,tll;
    i64 ans;
    scanf("%d",&cases);
    //printf("%d\n",cases);

    sieve();

    //printf("DD\n");

    while(cases--)
    {
        bs.reset();
        vc.clear();
        //MSET(b,-1);
        vt.clear();


        scanf("%lld",&n);

        for(i=1;i<=n;++i)
        {
            scanf("%lld",a+i);
            b[i]=-1;
            //printf("A\t%d\n",a[i]);
        }

        for(i=1;i<=n;++i)
        {
            if(b[i] == -1)
            {
                //printf("IIIII\t%d\n",i);
                ct=1;
                vt.clear();

                j=i;
                vt.PB(j);
                while(a[j]!=i)
                {
                    j=a[j];
                    vt.PB(j);
                    ++ct;
                }

                for(j=0;j<ct;++j)
                {
                    //printf("VVVVVV\t%d\n",vt[j]);
                    b[vt[j]]=ct;
                }

                if(!bs.test(ct))
                {
                    //printf("CT\t%d\n",ct);
                    bs.set(ct);
                    vc.PB(ct);
                }
            }
        }

        vsz=vc.size();

        MSET(res,0);

        for(i=0;i<vsz;++i)
        {
            j=0;
            MSET(fa,0);

            tll=vc[i];

            while(tll>1)
            {
                if(( (tll%primes[j])==0 ))
                {
                    while( (tll%primes[j])==0 )
                    {
                        tll/=primes[j];
                        ++fa[j];
                    }
                }
                res[j]=max(res[j],fa[j]);
                ++j;
            }
        }
        ans=1;

        for(i=0;i<num_primes;++i)
        {
            ans*=((i64)pow(primes[i],res[i])%MOD);
            ans%=MOD;
        }


        printf("%lld\n",(ans)%MOD);
    }

	return 0;
}
