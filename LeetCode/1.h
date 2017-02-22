#ifndef _1_H_
#define _1_H_

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

namespace Chirl
{
    class Solution_1 {
    public: 
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            multimap<int, int> idxMap;      //由于返回结果需要原数组的下标，故先记录原数组下标;
            for (int idx = 0; idx < nums.size(); ++idx) 
            {
                idxMap.insert(std::pair<int, int>(nums[idx], idx));
            }
            sort(nums.begin(), nums.end()); //对数组排序;

            int     numCnt      = nums.size();
            int     idxBeg      = 0;        
            int     idxEnd      = numCnt - 1;
            int     restNum     = target - nums[idxBeg];   
            while (idxEnd > idxBeg) 
            {
                //每次从数组头选定一个数a，再到数组尾部去比较有无合适的b，使得a+b=target;
                if (restNum < nums[idxEnd]) 
                {
                    idxEnd--; 
                }            
                else if (restNum > nums[idxEnd]) 
                {
                    restNum = target - nums[++idxBeg];
                    idxEnd  = numCnt-1 < idxEnd ? numCnt-1 : idxEnd;
                }
                else 
                {
                    int tmp[2] = {0};
                    multimap<int, int>::iterator itor;
                    itor = idxMap.find(nums[idxBeg]);
                    tmp[0] = itor->second;
                    idxMap.erase(itor);
                    itor = idxMap.find(nums[idxEnd]);
                    tmp[1] = itor->second;
                    return vector<int>(tmp, tmp+2);                  
                }
            }
            return vector<int>();
        }

        static int test()
        {
            Solution_1 su;
            int numArray[] = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};


            vector<int> nums(numArray, numArray + sizeof(numArray)/sizeof(int));

            vector<int> result = su.twoSum(nums, 542);

            return 0;
        }
    };


    
}



#endif