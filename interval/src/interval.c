#include "interval.h"

node* createNode(interval i){
    node* temp=(node*)malloc(sizeof(node));

    interval* temp_interval = (interval*)malloc(sizeof(interval));
    temp_interval->low = i.low;
    temp_interval->high = i.high;

    temp->i = temp_interval;
    temp->max = i.high;
    temp->left = NULL;
    temp->right= NULL;

    return temp;
}

interval createInterval(int low,int high){
    interval* temp_interval = (interval*)malloc(sizeof(interval));
    temp_interval->low = low;
    temp_interval->high = high; 
    return *temp_interval;
}

node* insert(node* root, interval i ){
   
    if(root == NULL){
        return createNode(i);
    }

    int l = root->i->low;

    if (i.low <l){
        root->left = insert(root->left,i);
    }else{
        root->right= insert(root->right,i);
    }

   if(root->max < i.high){
    root->max = i.high;
   }
   
   return root;

}


int overlap(interval i1,interval i2){
    if(i1.low <= i2.high && i2.low <=i1.high){
        return 1;
    }
    return 0;
}

interval overlapSearch(node* root ,interval i){
    
    if(root== NULL){
        printf("root null");
        return createInterval(999,999);
        
    }{
         if(overlap((*root->i),i)==1){
        return *root->i;
    }

    if(root->left !=NULL && root->left->max >= i.low){
        return overlapSearch(root->left,i);
    }

    return overlapSearch(root->right,i);
    }
    
   

}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    printf("[%d,%d] max =%d\n",root->i->low,root->i->high,root->max );
    inorder(root->right);

}


node *minimum( node *x)
{
    while (x->right!=NULL)
    {
        x=x->right;
    }
    return x;
}




node* delete( node *root, interval key)
{
    if(root == NULL) return root;

    else if(key.low < root->i->low) root->left = delete(root->left,key);    
    
    else if (key.high > root->i->high) root->right = delete(root->right,key); 
    
    
    else {
        
        if(root->left == NULL && root->right == NULL)                   
        {
            free (root);
            root = NULL;
        }
        
        else if(root->left == NULL)// 1 paidi
        {
            node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            node *temp = root;
            root = root->left;
            free (temp);
        }
        
        else 
        {
            node *temp = minimum(root->right);
            root->i->low = temp->i->low;
            root->right = delete(root->right,*temp->i);
        }
    }
    return root;
}



