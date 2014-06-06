#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>

using namespace std;

#define PB push_back
#define i64 long long

i64 gcd(i64 a,i64 b)
{
    i64 t;
    while(b!=0)
    {
        t=a;
        a=b;
        b=t%b;
    }

    return a;
}

int main()
{

    freopen("Text/GUESS.txt","r",stdin);



    i64 n,m,cases,num,den,gcdd;

    scanf("%lld",&cases);

    while(cases--)
    {
        //printf("DD\n");
        scanf("%lld %lld",&n,&m);
        den=n*m;
        num=(i64)((n+1)/2)*(i64)(m/2)+(i64)((m+1)/2)*(i64)(n/2);
        gcdd=gcd(den,num);
        printf("%lld/%lld\n",num/gcdd,den/gcdd);

    }



	return 0;
}
