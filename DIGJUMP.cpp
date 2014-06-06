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

    char a[100005];
    int n,sz;
    int mn[100005];
    vector<int> ct[10];
    queue<int> q;
    bool vis[10];


int main()
{

    freopen("Text/DIGJUMP.txt","r",stdin);



    int i,j,num,idx;

    scanf("%s",a);
    n=strlen(a);


    for(i=0;i<n;++i)
    {
        ct[a[i]-'0'].PB(i);
    }

    mn[0]=1;
    if(n>1)
    {
        q.push(0);
        while(mn[n-1]==0 && !q.empty())
        {
            idx=q.front();
            q.pop();

            num=a[idx]-'0';

        if(!vis[num])
        {
            sz=ct[num].size();
            for(i=0;i<sz;++i)
            {
                if(mn[ct[num][i]]==0)
                {
                    mn[ct[num][i]]=mn[idx]+1;
                    q.push(ct[num][i]);
                }
            }

            vis[num]=true;
        }

            if(idx>0 && mn[idx-1]==0)
            {
                mn[idx-1]=mn[idx]+1;
                q.push(idx-1);
            }


            if((idx+1)<n && mn[idx+1]==0)
            {
                mn[idx+1]=mn[idx]+1;
                q.push(idx+1);
            }
        }
    }



    printf("%d\n",mn[n-1]-1);




	return 0;
}
