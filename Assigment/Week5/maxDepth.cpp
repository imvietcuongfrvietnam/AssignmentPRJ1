int maxDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    int val_left = 1 + maxDepth(root->left);
    int val_right = 1 + maxDepth(root->right);
    return val_left>=val_right?val_left:val_right;
}
