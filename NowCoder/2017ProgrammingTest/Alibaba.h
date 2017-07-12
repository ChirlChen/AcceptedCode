/************************************************
  FileName    : Alibaba.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/12                      ;
              _                                 ;
             /  \         吉                    ;     
            /|oo \         祥                   ;    
           (_|  /_)       物                    ;   
             `@/  \   _    镇                   ;    
             |     \  \\  楼                    ;   
              \||   \  ))  !!                   ;    
              |||\ / \//                        ; 
            _//|| _\  /                         ;
    ______(_/(_|(____/_________                 ;
*************************************************/
#ifndef _ALIBABA_H_
#define _ALIBABA_H_
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <limits>

using namespace std;

namespace Chirl
{
    /************************************************************************
     题      目: 给定一个数组inputs，从中任选两个数之差的绝对值构成A集合，任选两个数之和构成B集合;
                 然后从A中B中分别任选一个数之差的绝对值构成D集合，输出D中最大值，最小值以及D的size之和;
     思      路：暴力
     算法复杂度：
     ************************************************************************/
    class Solution_Alibaba
    {
    public:
        void dfs(const vector <int>& inputs, int idx, set<int> &A, set<int> &B) {
            if (inputs.size() - 1 == idx)
            {
                return;
            }

            int beg = inputs[idx];
            for (int i = idx+1; i < inputs.size(); ++i)
            {
                A.insert(abs(beg + inputs[i]));
                B.insert(abs(beg - inputs[i]));
            }

            dfs(inputs, idx+1, A, B);
        }



        int result(const vector <int>& inputs) {
            int sz = inputs.size() * (inputs.size() - 1) / 2;
            set<int> A; 
            set<int> B; 

            dfs(inputs, 0, A, B);

            set<int> D;
            for (auto itrA = A.begin(); itrA != A.end(); ++itrA)
            {
                for (auto itrB = B.begin(); itrB != B.end(); ++itrB)
                {
                    D.insert(abs(*itrA - *itrB));
                }
            }


            return *D.begin() + *D.rbegin() + D.size();
        }
  
        static void test()
        {
            int size = 0;
            cin >> size;
            cin.ignore (numeric_limits<std::streamsize>::max(), '\n');
            vector<int> points;
            for(size_t i=0; i<size; ++i) {
                int item;
                cin >> item;
                cin.ignore (numeric_limits<std::streamsize>::max(), '\n');
                points.push_back(item);
            }
            
            Solution_Alibaba su;
            int res = su.result(points);
            cout << res << endl;
            return;
        }
    };
  
}


#endif //!_Alibaba_H_
