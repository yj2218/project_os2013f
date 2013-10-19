#ifndef _RBTREE_H_

#include <assert.h>
#include <stdlib.h>

enum rbtree_node_color { RED, BLACK };

typedef struct rbtree_node_t {
    void* key;
    void* value;
    struct rbtree_node_t* left;
    struct rbtree_node_t* right;
    struct rbtree_node_t* parent;
    enum rbtree_node_color color;
} *rbtree_node;

typedef struct rbtree_t {
    rbtree_node root;
} *rbtree;

typedef int (*compare_func)(void* left, void* right);

rbtree rbtree_create(); //rb tree를 만들고, 이 리턴값에 tree->root 에 루트노드가 할당된다.
void* rbtree_lookup(rbtree t, void* key, compare_func compare);
rbtree_node_t * rbtree_insert(rbtree t, void* key, void* value, compare_func compare); //이 인서트를 홀용,
void rbtree_delete(rbtree t, void* key, compare_func compare);

#endif


