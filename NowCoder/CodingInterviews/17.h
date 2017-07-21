/************************************************
  FileName    : 17.h           ;
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
#ifndef _17_H_
#define _17_H_


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
    class Solution_17
    {
    public:
        bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            if(pRoot1 == nullptr || pRoot2 == nullptr) return false;
           
            return dfs(pRoot1, pRoot2);
        }

        bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
            if(pRoot2 == nullptr) return true;  //p1 == p2 == nullptr;
            else if(pRoot1 == nullptr) return false;

            if(pRoot2->val == pRoot1->val){
                bool resLeft  = IsSubtree(pRoot1->left, pRoot2->left);
                bool resRight = IsSubtree(pRoot1->right, pRoot2->right);
                return resLeft && resRight;
            }
            else
                return false;
        }

        bool dfs(TreeNode* pRoot1, TreeNode* pRoot2){
            if(pRoot1 == nullptr){
                return false;
            }
            if(pRoot1->val == pRoot2->val){
                if(IsSubtree(pRoot1, pRoot2)) return true;
            }

            bool isSub = false;
            isSub = dfs(pRoot1->left, pRoot2);
            if(isSub) return isSub;
            isSub = dfs(pRoot1->right, pRoot2);
            if(isSub) return isSub;

            return false;
        }
        static void test()
        {
            Solution_17 su;
            su.HasSubtree(nullptr, nullptr);
        }
        
    };
  
}
namespace Wcytem
{
    class Solution_17
    {
    public:
        bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            if(pRoot2 == NULL)
                return false;

        }
        bool SameNodeSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            if (pRoot1 == NULL && pRoot2 == NULL)
            {
                return true;
            }
            if (pRoot1 == NULL || pRoot2 == NULL)
            {
                return false;
            }
            if (pRoot1->val == pRoot2->val)
            {
                return SameNodeSubtree(pRoot1->left,pRoot2->left)&&SameNodeSubtree(pRoot1->right,pRoot2->right);
            } 
            else
            {
                return false;
            }
        }
        //中文注释测试;输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
        static void test()
        {
            Solution_17 su;
            su.HasSubtree(NULL,NULL);

        }
    };

}

#endif //!_17_H_
