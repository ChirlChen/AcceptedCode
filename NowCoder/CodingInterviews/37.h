/************************************************
  FileName    : 37.h           ;
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
#ifndef _37_H_
#define _37_H_

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
    class Solution_37
    {
    public:
        int TreeDepth(TreeNode* pRoot)
        {
            if(pRoot == nullptr) return 0;

            return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
        }
    
        static void test()
        {
            Solution_37 su;
  
        }

    private:
        int max(int a, int b){
            return a > b ? a : b;
        }
    };
  
}


#endif //!_37_H_
