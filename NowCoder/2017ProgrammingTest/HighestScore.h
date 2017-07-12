/************************************************
  FileName    : HighestScore.h           ;
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
#ifndef _HIGHESTSCORE_H_
#define _HIGHESTSCORE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_HighestScore
    {
    public:
        void HighestScore(){
            

            int N, M;
            cin >> N >> M;

            vector<int> scores(N+1, 0);
            for(int i = 1; i <= N; ++i){
                cin >> scores[i];
            }

            char op;
            int A, B;
            for(int i = 0; i < M; ++i){
                cin >> op >> A >> B;
                switch(op){
                case 'Q':
                    cout << max(scores, A, B) << endl;
                    break;

                case 'U':
                    scores[A] = B;
                    break;
                }
            }

            
            return;
        }
  
        static void test()
        {
            Solution_HighestScore su;
            su.HighestScore();
        }

    private:

        int max(const vector<int> &scores, int A, int B){
            if (A > B) swap(A, B);
            if(A <= 0 || B >= scores.size()){
                return -1;
            }
            int maxNum = scores[A];
            for(int i = A+1; i <= B; i++){
                maxNum = scores[i] > maxNum ? scores[i] : maxNum; 
            }

            return maxNum;
        }

    };
  
}


#endif //!_HighestScore_H_
