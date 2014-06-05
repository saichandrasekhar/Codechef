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

#define maxl 1000004



char a[maxl];
int len,ct=0,pos;

int main()
{
    bitset<100000> aa[10000];
    freopen("C:/Users/Deepak/Desktop/Deepak/Programs/Codechef/Text/COMPILER.txt","r",stdin);
    int cases,i,j;

    scanf("%d",&cases);

    while(cases--)
    {
        ct=0;
        pos=-1;
        scanf("%s",a);
        len=strlen(a);

        for(i=0;i<len;++i)
        {
            if(a[i]=='<')
            {
                ++ct;
            }
            else
            {
                --ct;
                if(ct<0)
                {
                    break;
                }
                else if(ct==0)
                {
                    pos=i;
                }
            }
        }

        printf("%d\n",pos+1);
    }
    return 0;
}

