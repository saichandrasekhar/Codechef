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


struct data
{
    int x,sn;

    data(int a,int b)
    {
        sn=a;
        x=b;
    }

    bool operator<(const data &b) const
    {
        return x<b.x;
    }
};

#define MAXN 100000
vector<data> a;
int poss[MAXN],gp[MAXN];

int main()
{
    freopen("Text/FROGV.txt","r",stdin);
    int n,k,p,i;
    int x,y;

    scanf("%d %d %d",&n,&k,&p);

    REP(i,n)
    {
        scanf("%d",&x);
        a.PB(data(i,x));
    }

    sort(a.begin(),a.end());


    REP(i,n)
    {
        poss[a[i].sn]=i;
    }

    x=0;
    gp[a[0].sn]=0;

    FOR(i,1,n)
    {
        if((a[i].x-a[i-1].x)>k)
        {
            ++x;
        }

        gp[a[i].sn]=x;
    }

    REP(i,p)
    {
        scanf("%d %d",&x,&y);
        --x;
        --y;

        if(gp[x]==gp[y])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }


	return 0;
}
