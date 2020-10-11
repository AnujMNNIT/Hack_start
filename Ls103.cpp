/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        int flag=0;
        long long n,i;
        while(!q.empty())
        {
            n=q.size();
            vector<int> v(n);
            if(flag==0)
            {
                for(i=0;i<n;i++)
                {
                    temp=q.front();
                    v[i]=q.front()->val;
                    q.pop();
                    if(temp->left!=NULL)
                        q.push(temp->left);
                    if(temp->right!=NULL)
                        q.push(temp->right);
                    
                }
                ans.push_back(v);
                flag=1;
            }
            else if(flag==1)
            {
                for(i=n-1;i>=0;i--)
                {
                    temp=q.front();
                    v[i]=temp->val;
                    q.pop();
                    if(temp->left!=NULL)
                        q.push(temp->left);
                    if(temp->right!=NULL)
                        q.push(temp->right);
                    
                }
                ans.push_back(v);
                flag=0;
            }
        }
        return ans;    
            
    }
};
