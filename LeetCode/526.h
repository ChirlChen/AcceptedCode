#ifndef _526_H_
#define _526_H_
#include <iostream>
#include <vector>
using namespace std;
namespace Sansan
{
    class Solution_526
    {
    public:
        int dfs(vector<int>& visit,int n,int x)
        {   int cont=0;
            if(x==0)
                return 1;
            for (int i=1;i<=n;i++)
               if (!visit[i] && (x%i==0 || i%x==0))
               {
                  visit[i]=1;
                  cont+=dfs(visit,n,x-1);//递归调用，visi[n]保存已经被放置数字的位置
                   visit[i]=0;
                }
            return cont;
        }
        int countArrangement(int N) 
        {
            vector<int>visi(N+1,0);
            int ret=dfs(visi,N,N);
            return ret;
        }
        void static test()
        {
            Solution_526 tes;
            cout<<tes.countArrangement(4)<<endl;
        }
    };
}
#endif
