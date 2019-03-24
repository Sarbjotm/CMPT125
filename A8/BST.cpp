#include "BST.h"
#include "BT-visualize.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <string>

// Implement the following five methods
// inserts val into BST rooted at x and returns the tree's new root
//Traverse until we see an empty node (NULL) and place there
BTnode * insert(BTnode * x, int val) {
    if (x == NULL){
        BTnode* temp = new BTnode;
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (val <= x->val){
        x->left = insert(x->left, val);
    }
    else{
        x->right = insert(x->right, val);
    }
    return x;
}
// returns true iff target in tree rooted at x
bool search(BTnode * x, int target){
    //Root is x
    if (x == NULL){
        return false; //This means the tree is empty
    }
    if(x->val == target){ //If root->val == target then we have found it
        return true;
    }
    else if(x->val < target){
        //This means target is greater so check right subtree
        return search(x->right, target);
    }
    else{ // val <= x->val so search left tree
        return search(x->left, target);
    }
}

// Find the maximum value of a tree rooted at x
int findmax(BTnode * x) {
    //just keep on going right until null since max value is at numm
    //Base case if x->right == NULL
    if (x == NULL){
        return 0;
    }
    while(x->right != NULL){ //traverse right
        x = x->right;
    }
    return x->val;
}

// Find the manimum value of a tree rooted at x
int findmin(BTnode * x) {
    //jusr keep on going left untill null x->left == NULL
    if (x == NULL){
        return 0;
    }
    while(x->left != NULL){ //traverse left
        x = x->left;
    }
    return x->val;
}


void printnumbers(BTnode* x){
    if (x == NULL){
        return; // if nothing is in the tree (root is NULL)
    }
    printnumbers(x->left);
    printf(" %d", x->val );
    printnumbers(x->right);
}

// Given a binary tree, print its nodes in in-order
void printAscendOrder(BTnode * x){
    //now we want to go to left most print then parent print, then child on right print go back up
    printnumbers(x);
    printf("\n");
}



// You don't need to worry about these methods below
BTascii print_helper(BTnode * x);

void print(BTnode * x) {
    BTascii ret = print_helper(x);
    ret.display();
}

BTascii print_helper(BTnode * x) {
    if (x == NULL) return BTascii();
    BTascii left = print_helper(x->left);
    BTascii right = print_helper(x->right);
    char buf[25];
    sprintf(buf, "%d", x->val); return join(left, right, std::string(buf)); 

}
void postfree(BTnode * x) {
    if (x == NULL) return;
    postfree(x->left);
    postfree(x->right);
    delete x;
}
