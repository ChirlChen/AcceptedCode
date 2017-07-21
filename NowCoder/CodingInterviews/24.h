/************************************************
  FileName    : 24.h           ;
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
#ifndef _24_H_
#define _24_H_
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};


namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_24
    {
    public:
        vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
            if(root == nullptr) return m_ans;
            vector<int> path;
            FindPath(root, expectNumber, path);

            return m_ans;
        }

        void FindPath(TreeNode* root, int expNum, vector<int> path){
            if(expNum == root->val && (root->left == nullptr && root->right == nullptr)){
                path.push_back(root->val);
                m_ans.push_back(path);   
                return;
            }
            if(expNum < 0 || root == nullptr){
                return;
            }

            path.push_back(root->val);
            if(root->left)
                FindPath(root->left, expNum-root->val, path);
            if(root->right)
                FindPath(root->right, expNum-root->val, path);
        }
    private:
        vector<vector<int> > m_ans;
  
    public:
        static void test()
        {
            Solution_24 su;
            su.FindPath(nullptr, 20);
        }
    };
  
}


#endif //!_24_H_
