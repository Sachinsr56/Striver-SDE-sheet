// ------------using the inorder traversal-----


void inorder(BinaryTreeNode<int>* root, vector<int> &arr){
    if(!root)
        return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
    return;
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    if(!root)
        return {-1,-1};
    vector<int> arr;
    inorder(root,arr);
    int first=-1,second=-1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==key){
            if(i>0){
                first=arr[i-1];
            }
            if(i<arr.size()-1){
                second=arr[i+1];
            }
        }
    }
    return {first,second};
}

// ------------------------

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre=-1,suc=-1;
    while(root){
        if(root->data==key)
            break;
        if(root->data>key){
            suc=root->data;
            root=root->left;
        }
        else{
            pre=root->data;
            root=root->right;
        }
    }
    BinaryTreeNode<int>* predecessor=root->left;
    BinaryTreeNode<int>* successor=root->right;
    if(predecessor){
        pre=predecessor->data;
        while(predecessor->right){
            predecessor=predecessor->right;
            pre=predecessor->data;
        }
    }
    if(successor){
        suc = successor->data;
        while(successor->left){
            successor = successor->left;
            suc = successor->data;
        }
    }
    return {pre,suc};
}