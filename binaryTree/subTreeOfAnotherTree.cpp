class Solution {
public:
    bool isIdentical(TreeNode*p,TreeNode*q){
        if(p==nullptr||q==nullptr){
            return p==q;
        }
        bool isleftSame= isIdentical(p->left,q->left);
        bool isrightSame= isIdentical(p->right,q->right);
        return isleftSame && isrightSame && p->val == q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL){
            return root==subRoot;
        }
        if(root->val == subRoot->val && isIdentical(root,subRoot)){
            return true;
        }
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
