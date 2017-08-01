/************************************************
  FileName    : 38.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/31                      ;
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
#ifndef _38_H_
#define _38_H_
#include <math.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
};
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_38
    {
    public:
        bool IsBalanced_Solution(TreeNode* pRoot) {
            if(pRoot == nullptr) return true;

            char ans = 1;
            TreeDepth(pRoot, ans);

            return ans;
        }

        int TreeDepth(TreeNode *pRoot, char &ans) {
            if(pRoot == nullptr) {
                ans = 1;
                return 0;
            }

            int leftDepth = TreeDepth(pRoot->left, ans);
            int rightDepth = TreeDepth(pRoot->right, ans);

            ans = ans && abs(leftDepth - rightDepth) <= 1;

            return max(1+leftDepth, 1+rightDepth);
        }
  
        static void test()
        {
            Solution_38 su;
            char ans = 1;
            ans &= (1 > 0);
        }
    private:
        int max(int a, int b){
            return a > b ? a : b;
        }
    };
  
}


#endif //!_38_H_
