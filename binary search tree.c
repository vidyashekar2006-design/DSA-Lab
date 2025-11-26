#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;
NODE creatbst(NODE root,int key)
{
    NODE temp,cur,prev;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        return temp;
    cur=root;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        if(key<cur->data)
            cur=cur->left;
        else
            cur=cur->right;

    }
    if(key<prev->data)
        prev->left=temp;
    else
        prev->right=temp;
        return root;
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
void inorder(NODE root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void postorder(NODE root)
{
    if (root!=NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);

    }
}
int main()
{
    NODE root=NULL;
    int item,ch;
    for(;;)
    {
        printf("\n1.insert\n2.preorder\n3.inorder\n4.postorder\n");
        printf("\n enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n enter the item to be inserted:");
                   scanf("%d",&item);
                   root=creatbst(root,item);
                   break;
            case 2:printf("\n preorder traversal \n");
                   preorder(root);
                   break;
            case 3:printf("\n inorder traversal\n");
                   inorder(root);
                   break;
            case 4:printf("\n postorder traversal\n");
                   postorder(root);
                   break;
            default:exit(0);
        }
    }
    return 0;
}
