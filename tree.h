#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED



typedef struct bin_tree{

int id;
bin_tree* left;
bin_tree* right;

} tree;

void add(tree *&root, int num){

if (!root){
    root=new tree;
    root->id=num;
    root->left=NULL;
    root->right=NULL;
}
else{
    if (num>root.id){
        add(root->right,num);
    }else{
    add(root->left,num);
    }
}
}

int pop(tree *&root,int num){
if (num > root->id){
    pop(root->right,num);
}else if ( num<root->id){
pop(root->left,num);
}


}





#endif // TREE_H_INCLUDED
