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


int main()
{
    freopen("C:/Users/Deepak/Desktop/Deepak/Programs/Codechef/Text/OJUMPS.txt","r",stdin);

    i64 a;

    scanf("%lld",&a);
    a%=6;
    if(a==0 || a==1 || a==3)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}

