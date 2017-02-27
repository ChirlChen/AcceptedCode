/**************************************************
	Description :
	Editor	  	: Chirl
	EditDate	  : 2017/02/27
				      _	
	           /  \               
	          /|oo \              
	         (_|  /_)             
	           `@/  \    _        
	           |     \   \\       
	            \||   \   ))      
	            |||\ /  \//       
	          _//|| _\   /          
     ______(_/(_|(____/_________ 
**************************************************/

#ifndef _4_H_
#define _4_H_

#include <vector>

using namespace std;

//Definition for binary tree
struct TreeNode {
int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

namespace Chirl
{
    class Solution_4 {
    public:
        struct TreeNode* reConstructBinaryTree(const vector<int> &pre,const vector<int> &in) {
            // 		if (pre.size() != in.size())
            // 		{
            // 			return NULL;
            // 		}
            if (in.empty())
            {
                return NULL;
            }
            int parentIdx = 0;
            TreeNode *rootNode = new TreeNode(pre[0]);

            parentIdx = FindElementIdx(in, pre[0]);
            if (parentIdx > 0)
            {
                rootNode->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + (parentIdx + 1)), 
                    vector<int>(in.begin(), in.begin() + parentIdx)
                    );	
            }
            else 
                rootNode->left = NULL;

            int inMaxIdx = in.size() - 1;
            if (parentIdx < inMaxIdx)
            {
                rootNode->right = reConstructBinaryTree(vector<int>(pre.begin() + (1 + parentIdx), pre.end()), 
                    vector<int>(in.begin()+ (1 + parentIdx), in.end())
                    );
            }
            else 
                rootNode->right = NULL;

            return rootNode;

        }

        int FindElementIdx(const vector<int> &v, int element)
        {
            if (v.empty())
            {
                return -1;
            }

            int idx = 0;
            while (idx < v.size() && v[idx] != element)
            {
                idx++;
            }

            return idx;
        }

        static void test()
        {
            int tmpPre[] = {1,2,4,7,3,5,6,8};
            int tmpIn[] = {4,7,2,1,5,3,8,6};

            vector<int> pre(tmpPre, tmpPre+sizeof(tmpPre)/sizeof(int));
            vector<int> in(tmpIn, tmpIn+sizeof(tmpIn)/sizeof(int));

            Solution_4 su;
            TreeNode *head = su.reConstructBinaryTree(pre, in);
        }
    };

}

#endif // !_4_H_
