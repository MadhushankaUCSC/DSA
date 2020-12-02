#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<vector>



node* rr_rotation(node *parent){
	
    node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

node* ll_rotation(node *p){
	
    node *temp;
    temp = p->left;
    p->left = temp->right;
    temp->right = p;
    return temp;
}
 


node* rl_rotation(node *p){
	
    node *temp;
    temp = p->right;
    p->right = ll_rotation (temp);
    return rr_rotation (p);
}
 

node* balance(node *temp){
	
    int bf = diff(temp);
    
    if(bf>1){
        if(diff(temp->left)>0) temp=ll_rotation(temp);
        else temp = lr_rotation (temp);
    }
    else if (bf<(-1)){
        if(diff (temp->right)>0) temp=rl_rotation(temp);
        else temp=rr_rotation(temp);
    }
    return temp;
}
 

node* insert(node *root, int val){
	
    if(root==NULL){
        root = new node;
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (val<(root->data)){
    	
        root->left = insert(root->left, val);
        root = balance(root);
    }
    else if (val>=(root->data)){
    	
        root->right = insert(root->right, val);
        root = balance (root);
    }
    return root;
}

void inorder(node *tree){
	
	int i = 0;
	
    if(tree==NULL) return;   
    inorder (tree->left);
    int val= tree->data;
	vec.push_back(val);
    inorder (tree->right);
}


int main(){
	
	avlTree avl;
	int n=0;
	int min,max,diff,counter = 0;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		int val;
		cin>>val;
		root = insert(root,val);
	}
	inorder(root);

	for(int i=0;i<n-1;i++){
		if(i==0){
			min = vec[i];
			max = vec[i+1];
			diff = max-min;
			counter++;
		}
		else{
			if(vec[i]<vec[i+1]){
				max = vec[i+1];
				diff = max-min;
				if(diff>4){
					counter++;
					min = max;
				}
			}
		}
	}
	cout<<counter<<endl;
	return 0;
}
