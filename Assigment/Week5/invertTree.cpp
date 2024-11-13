struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL) return root;
    struct TreeNode *tmp = invert(root->left);
    root->left = invert(root->right);
    root->right = tmp;
    return root;
}
