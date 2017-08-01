/************************************************
  FileName    : 34.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/28                      ;
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
#ifndef _34_H_
#define _34_H_
#include <vector>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_34
    {
    public:
        int InversePairs(vector<int> data) {
            if(data.empty()) return 0;

            const int UP_LIMITS = 1000000007; 
            long long cnt = 0;
            vector<int> sorted = MergeSort(data, 0, data.size(), cnt);
            
            return cnt % UP_LIMITS;
        }

    private:

        vector<int> MergeSort(const vector<int> &data, int left, int right, long long &cnt){
            if(left == right-1){
                return vector<int>(&data[0] + left, &data[0] + right);
            }

            
            int mid = (left + right) / 2; 
            vector<int> leftArr, rightArr;
            leftArr = MergeSort(data, left, mid, cnt);
            rightArr = MergeSort(data, mid, right, cnt);

            return Merge(leftArr, rightArr, cnt);
        }

        vector<int> Merge(vector<int> &left, vector<int> &right, long long &cnt){
            vector<int> sorted;
            sorted.reserve(left.size() + right.size());
     
            int i = 0, j = 0;
            while(i < left.size() && j < right.size()){
                if(left[i] <= right[j]){
                    sorted.push_back(left[i++]);
                }
                else{
                    sorted.push_back(right[j++]);
                    cnt += left.size() - i;
                }
            }

            while(i < left.size()){
                sorted.push_back(left[i++]);
            }

            while(j < right.size()){
                sorted.push_back(right[j++]);
            }

            return sorted;
        }
  public:
        static void test()
        {
            int tmp[] = {1, 2, 5, 6, 0, 3, 4};
            Solution_34 su;
            int ans = su.InversePairs(vector<int>(begin(tmp), end(tmp)));
        }
    };
  
}


#endif //!_34_H_
