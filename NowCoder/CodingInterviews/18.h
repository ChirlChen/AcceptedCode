/************************************************
  FileName    : 18.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/20                      ;
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
#ifndef _18_H_
#define _18_H_
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
    class Solution_18
    {
    public:
        void Mirror(TreeNode *pRoot) {
            dfs(pRoot);		
        }
        void dfs(TreeNode *pRoot){
            if(pRoot == nullptr) return;

            SwapChildren(pRoot);
            dfs(pRoot->left);
            dfs(pRoot->right);
        }
        void SwapChildren(TreeNode *pRoot){
            TreeNode *node = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = node;
        }
  
        static void test()
        {
            Solution_18 su;
            su.Mirror(NULL);
        }
    };
  
}
namespace Wcytem
{
    class Solution_18 {
    public:
        void Mirror(TreeNode *pRoot) {
            if(pRoot == NULL)
                return;
            TreeNode *rightNode = pRoot->right;
            TreeNode *leftNode = pRoot->left;
            pRoot->left = rightNode;
            pRoot->right = leftNode;
            Mirror(leftNode);
            Mirror(rightNode);
        }
    };
}


#endif //!_18_H_
