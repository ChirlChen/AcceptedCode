/************************************************
  FileName    : 26.h           ;
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
#ifndef _26_H_
#define _26_H_
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
     思      路：搜索树转双向链表; 
     算法复杂度：
     ************************************************************************/
    class Solution_26
    {
    public:
        TreeNode* Convert(TreeNode* pRootOfTree) {
            if (pRootOfTree == nullptr) {
                return nullptr;
            }
            
            TreeNode *ptr = nullptr;
            DoConvert(pRootOfTree, ptr);
            while(pRootOfTree->left){
                pRootOfTree = pRootOfTree->left;
            }

            return pRootOfTree;
        }

        void DoConvert(TreeNode *root, TreeNode *&lastNode){
            if(root == nullptr) {
                return;
            }

            if(root != nullptr) {
                DoConvert(root->left, lastNode); 
            }

            if (lastNode) {
                lastNode->right = root;
            }
            root->left = lastNode;
            lastNode = root;

            if(root != nullptr) {
                DoConvert(root->right, lastNode);
            }
            return;
        }
  
        static void test()
        {
            //5, 7, 6, 9, 11, 10, 8,
            TreeNode *pRoot = new TreeNode(8);
            TreeNode *curPtr = pRoot;
            curPtr->left = new TreeNode(6);
            curPtr->right = new TreeNode(10);
            curPtr = curPtr->left;
            curPtr->left = new TreeNode(5);
            curPtr->right = new TreeNode(7);
            curPtr = pRoot->right;
            curPtr->left = new TreeNode(9);
            curPtr->right = new TreeNode(11);

            Solution_26 su;
            TreeNode *ans = su.Convert(pRoot);

        }
    };
  
}


#endif //!_26_H_
