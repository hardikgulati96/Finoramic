void func(TreeNode *root, int sum,vector<int> &path, vector<vector<int> > &ans)
 {
     if(root==NULL) return;
     
     path.push_back(root->val);
     if(sum==root->val && root->left==NULL && root->right==NULL )
     {
         ans.push_back(path);              // leaf reached with given sum
     }
     func(root->left,sum-root->val,path,ans);
     func(root->right,sum-root->val,path,ans);
     path.pop_back();                           // backtrack for another path
 }
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int> > ans;
    vector<int> path;
    func(root,sum,path,ans);
    return ans;
    
}
