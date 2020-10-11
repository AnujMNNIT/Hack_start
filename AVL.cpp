#include<bits/stdc++.h>
using namespace std;
class AVL
{
	public:
	int key;
	AVL *left;
	AVL *right;
	int height;  //Augmented height.......................
	AVL(int val) //AVL tree constructor 
	{
		this->key=val;
		this->height=1;
		this->left=NULL;
		this->right=NULL;
	}
};


//Program to find height ................................

int height(AVL* root)
{
	if(root==NULL)return 0;
	return root->height;
}

//Balance factor of node.................................

int balance(AVL* root)
{
	if(root==NULL)return 0;
	return height(root->left)-height(root->right);
}

//Right rotation........................................


AVL *rightrotate(AVL *root)
{
	//Right rotation.................
	AVL *p=root->left;
	root->left=p->right;
	p->right=root;
	//Height update.................
	p->right->height=1+max(height(p->right->left),height(p->right->right));
	p->height=1+max(height(p->left),height(p->right));
	return p;
}

//Left rotation .........................................

AVL *leftrotate(AVL *root)
{
	//Left Rotation....................
	AVL *p=root->right;
	root->right=p->left;
	p->left=root;
	//Height update....................
	p->left->height=1+max(height(p->left->left),height(p->left->right));
	p->height=1+max(height(p->left),height(p->right));
	return p;	
}

//Insert.....................................................

AVL *Insert(AVL* root,int key)
{
	if(root==NULL)
	return new AVL(key);
	if(key<root->key)
	 root->left=Insert(root->left,key);
	else
	 root->right=Insert(root->right,key);   //Simple insert in BST............................
	root->height=1+max(height(root->left),height(root->right));  //Height ko update kara 
	int factor=balance(root);
	if(factor==2)      //updated node left subtree me hai
	{
		if(key<root->left->key) //updated node left subtree ke left subtree me hai
		 root=rightrotate(root); //RR Rotation
		else   //updated node left subtree ke right subtree me hai
		{
			root->left=leftrotate(root->left); //RL rotation pahle left rotation then right rotation  
			root=rightrotate(root);
		}
	}
	if(factor==-2)   //updated node right subtree me hai..
	{
		if(key>root->right->key) //updated node right subtree ke right subtree me hai........
	     root=leftrotate(root);  //LL Rotation
	    else //updated node right subtree ke left subtree me hai..............
	    {
	       root->right=rightrotate(root->right); //LR Rotation 
	       root=leftrotate(root);
		}
	}
	return root;	
}
AVL *InorderSuccessor(AVL *root)
{
	if(root->left==NULL)
	 return root;
	return InorderSuccessor(root->left);
}

//Deletion ....................................................

AVL *Delete(AVL* root,int key)
{
	if(root==NULL)
    	return root;
	if(key<root->key)
	root->left=Delete(root->left,key);
	else if(key>root->key)
	root->right=Delete(root->right,key);
	else
	{
		if(root->left==NULL||root->right==NULL)
		{
			AVL *temp=root->left?root->left:root->right;
			if (temp == NULL)  
            {  
                temp = root;  //temp me root ko store kar liya so that memory free kar sake 
                root = NULL;  
            }  
            else
            {
            	*root=*temp;
			}
			free(temp);
		}
		else
		{
			AVL *temp=InorderSuccessor(root->right);
			root->key=temp->key;
			root->right=Delete(root->right,temp->key);
		}
		
	} //Simple BST Deletion
	if (root == NULL)  
    return root;  
    root->height=1+max(height(root->left),height(root->right));  //Height ko update kara 
    int factor=balance(root);
	if(factor==2)      //updated node left subtree me hai
	{
		if(balance(root->left)>=0) //updated node left subtree ke left subtree me hai
		 root=rightrotate(root); //RR Rotation
		else   //updated node left subtree ke right subtree me hai
		{
			root->left=leftrotate(root->left); //RL rotation pahle left rotation then right rotation  
			root=rightrotate(root);
		}
	}
	if(factor==-2)   //updated node right subtree me hai..
	{
		if(balance(root->right)<=0) //updated node right subtree ke right subtree me hai........
	     root=leftrotate(root);  //LL Rotation
	    else //updated node right subtree ke left subtree me hai..............
	    {
	       root->right=rightrotate(root->right); //LR Rotation 
	       root=leftrotate(root);
		}
	}
	return root;
}

//Search in Binary search tree..................................

bool search(AVL* root,int key)
{
	if(root==NULL)
	  return false;
	else if(key<root->key)
	  return search(root->left,key);
	else if(key>root->key)
	  return search(root->right,key);
	else
	  return true;
}
//Inorder traversal which will generate sorted array..................

void Inorder(AVL* root)
{
	if(root==NULL)
	return;
	Inorder(root->left);
	cout<<root->key<<" "<<root->height<<endl;
	Inorder(root->right);
}

int main()
{
   int n,a;
   cout<<"Insert number of nodes"<<endl;
   cin>>n;
   AVL *root=NULL;
   cout<<"Insert nodes"<<endl;
   while(n--)
   {
   	 cin>>a;
   	 root=Insert(root,a);
   }
    Inorder(root);	
    root=Delete(root,5);
    Inorder(root);
    cout<<search(root,6);
}
