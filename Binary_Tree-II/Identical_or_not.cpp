
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(!root1 && !root2)
        return true;
    
    if(!root1 || !root2)
        return false;
    
    return ((root1->data==root2->data) && 
            identicalTrees(root1->left,root2->left) &&
            identicalTrees(root1->right,root2->right));
}

// void inorder(BinaryTreeNode<int>* root,vector<int> &ans){
//     if(!root)
//         return;
//     inorder(root->left,ans);
//     ans.push_back(root->data);
//     inorder(root->right,ans);
// }
// bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    
// if(!root1 && !root2)
//     return true;

// if(!root1 || !root2)
//     return false;
//     vector<int> arr1;
//     vector<int> arr2;
//     inorder(root1,arr1);
//     inorder(root2,arr2);
//     for(int i=0;i<arr1.size(); i++){
//         if(arr1[i]!=arr2[i])
//             return false;
//     }
//     return true;
// }
