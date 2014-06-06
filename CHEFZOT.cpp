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

int main()
{

    freopen("Text/CHEFZOT.txt","r",stdin);

    int n,t,lp=-1,mx=0,tp,i;

    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&t);
        if(t==0)
        {
            tp=i-lp-1;
            if(tp>mx)
            {
                mx=tp;
            }
            lp=i;
        }
    }

    tp=i-lp-1;
    if(tp>mx)
    {
        mx=tp;
    }


    printf("%d\n",mx);



	return 0;
}
