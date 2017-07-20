/************************************************
  FileName    : 22.h           ;
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
#ifndef _22_H_
#define _22_H_

#include <vector>
#include <queue>
using namespace std;

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
    class Solution_22
    {
    public:
        vector<int> PrintFromTopToBottom(TreeNode* root) {
            vector<int> res;
            if(root == nullptr) return res;

            queue<TreeNode *> q;
            q.push(root);
            while(!q.empty()){
                TreeNode *cur = q.front();
                q.pop();
                res.push_back(cur->val);

                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }
            return res;
        }
  
        static void test()
        {
            Solution_22 su;
            su.PrintFromTopToBottom(nullptr);
        }
    };
  
}


#endif //!_22_H_
