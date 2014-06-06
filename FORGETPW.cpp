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
#define INF 99999999


#define MAXLEN 1000005

char s[MAXLEN];

char ascii[127];

int main()
{

    freopen("Text/FORGETPW.txt","r",stdin);
    int cases,i,j,n,len,dec;

    char x,y;

    scanf("%d",&cases);
    //printf("CASES\t%d\n",cases);

    while(cases--)
    {
        dec=-1;

        for(i=33;i<127;++i)
        {
            ascii[i]=i;
        }

        scanf("%d",&n);
        //printf("n\t%d\n",n);

        for(i=0;i<n;++i)
        {
            //scanf("%c %c\n",&x,&y);
            //getch(x);
            //getch(y);
            cin>>x>>y;
            //printf("%c\t%c\n",x,y);
            ascii[x]=y;
        }

        scanf("%s\n",s);
        //printf("s\t%s\n",s);
        len=strlen(s);

        for(i=0;i<len;++i)
        {

            s[i]=ascii[s[i]];
            if(s[i]=='.')
            {
                dec=i;
            }
        }

        //printf("%s\n",s);

        if(dec==-1)
        {
            i=0;

            while(i<len && s[i]=='0')
            {
                ++i;
            }

            if(i==len)
            {
                printf("0\n");
            }
            else
            {
                while(i<len)
                {
                    printf("%c",s[i]);
                    ++i;
                }
                printf("\n");
            }
        }
        else
        {
            i=0;

            while(i<dec && s[i]=='0')
            {
                ++i;
            }

            j=len-1;

            while(j>dec && s[j]=='0')
            {
                --j;
            }

            if(i==dec)
            {
                if(j==dec)
                {
                    printf("0\n");
                }
                else
                {
                    while(i<=j)
                    {
                        printf("%c",s[i]);
                        ++i;
                    }
                    printf("\n");
                }
            }
            else
            {
                if(j==dec)
                {
                    while(i<j)
                    {
                        printf("%c",s[i]);
                        ++i;
                    }
                    printf("\n");
                }
                else
                {
                    while(i<=j)
                    {
                        printf("%c",s[i]);
                        ++i;
                    }
                    printf("\n");
                }
            }
        }
    }



	return 0;
}
