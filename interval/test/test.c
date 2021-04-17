
#include <stdio.h>
#include <stdlib.h>
#include "interval.h"





int main(void)
{
    node* root = NULL;
    root= insert(root,createInterval(15,20));
    root= insert(root,createInterval(10,30));
    root= insert(root,createInterval(17,19));
    root= insert(root,createInterval(5,20));
    root= insert(root,createInterval(12,15));
    root= insert(root,createInterval(30,40));
    inorder(root);
    
    
    interval temp_inter=createInterval(6,7);
    printf("overlap aranıyor[%d,%d]:\n",temp_inter.low,temp_inter.high );
    interval res = overlapSearch(root,temp_inter);

    if(res.low == 999  && res.high == 999){
        printf("no overlapped interval\n");
    }else{
        printf("overlap mevcut:[%d,%d]\n",res.low,res.high );
    }


    root=delete(root,createInterval(12,15));
    inorder(root);

    /*

    root=Delete(root,15);
    printf("\n 2 Nodes of the tree is deleted, and");
    
    printf("\n after deletion the inorder of BST is:");
    inorder(root);
    */
}