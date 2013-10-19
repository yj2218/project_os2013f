

#include "rbtree.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h> 


static int compare_int(void* left, void* right);
static void print_tree(rbtree t);
static void print_tree_helper(rbtree_node n, int indent);
//비교함수
int compare_int(void* leftp, void* rightp) {
    int left = (int)leftp;
    int right = (int)rightp;
    if (left < right) 
        return -1;
    else if (left > right)
        return 1;
    else {
        assert (left == right);
        return 0;
    }
}

//테스트코드는 구글링해서 가져옴.
#define INDENT_STEP  4

void print_tree_helper(rbtree_node n, int indent);

void print_tree(rbtree t) {
    print_tree_helper(t->root, 0);
    puts("");
}

void print_tree_helper(rbtree_node n, int indent) {
    int i;
    if (n == NULL) {
        fputs("<empty tree>", stdout);
        return;
    }
    if (n->right != NULL) {
        print_tree_helper(n->right, indent + INDENT_STEP);
    }
    for(i=0; i<indent; i++)
        fputs(" ", stdout);
    if (n->color == BLACK)
        printf("%d\n", (int)n->key);
    else
        printf("<%d>\n", (int)n->key);
    if (n->left != NULL) {
        print_tree_helper(n->left, indent + INDENT_STEP);
    }
}
void printnode(rbtree_node n){
	if(n==NULL){
		return;
	}
	 printf("%d\n", (int)n->key);
	 printnode(n->left);
	 printnode(n->right);
}
int main(){
	int i;
    rbtree t = rbtree_create();
    print_tree(t);
    for(i=0; i<5; i++) {
        int x = rand() % 10;
        int y = rand() % 10;
	printf("Inserting %d -> %d\n\n", x, y);
	rbtree_insert(t, (void*)x, (void*)y, compare_int);
	print_tree(t);
	printnode(t->root); //preorder print
	}
	return 0;
}
   
