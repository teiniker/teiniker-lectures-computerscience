# Binary Tree

A tree consists of elements called nodes organized in a hierarchical arrangement.

The node at the top of the hierarchie is called thr **root**.
The nodes directly below the root are its **children**, which in turn usually have children of their own.

With the exception of the root, each node in the hierarchy has exactly one **parent**, 
which is the node directly above it.

The number of children a node may parent depends on the type of tree.
This number is a tree's **branching factor**.
We focus on the **binary tree**, a relatively simple but powerful tree with a branching factor of 2.


## Binary Tree

A binary tree is a hierarchical arrangement of nodes, each having up to two nodes immediately below it.

![Binary Tree](figures/binary_tree.jpg)

Each node in a binary tree contains three parts: a data member and two pointers called left and right pointers.
If a node does not have a child to its left or right, we set the appropriate pointer to NULL.

_Example_: Tree node definition
```C
typedef struct node 
{
    int value;
    struct node *left_ptr;
    struct node *right_ptr;
} node_t;
```

**Traversing a binary tree** means visiting its nodes one at a time in a specific order.
Typically, one of four types or traversals is used:

* **Preorder Traversal**:
    For a given subtree, we **first traverse its root, then to the left, and then to the right**.
    The preorder traversal is a **depth-first exploration**.
    ```C
    void tree_traversal_preorder(node_t *node_ptr)
    {
        printf("%d ", node_ptr->value);
        tree_traversal_preorder(node_ptr->left_ptr);
        tree_traversal_preorder(node_ptr->right_ptr);
    }
    ```

* **Inorder Traversal**:
    For a given subtree, we **first traverse to the left, then to the root, and then to the right**.
    ```C
    void tree_traversal_inorder(node_t *node_ptr)
    {
        tree_traversal_preorder(node_ptr->left_ptr);
        printf("%d ", node_ptr->value);
        tree_traversal_preorder(node_ptr->right_ptr);
    }
    ```

* **Postorder Traversal**:
    For a given subtree, we **first traverse to the left, then to the right, and then to the root**.
    ```C
    void tree_traversal_postorder(node_t *node_ptr)
    {
        tree_traversal_preorder(node_ptr->left_ptr);
        tree_traversal_preorder(node_ptr->right_ptr);
        printf("%d ", node_ptr->value);
    }    
    ```

* **Level Order Traversal**:
    To traverse a binary tree in a level-order fashion, visit its nodes beginning at the root and proceed 
    downward, visiting the nodes at each level from left to right.
    The level-order traversal is a **breadth-first exploration**.

## References
* [Data Structure and Algorithms - Tree](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
    * Chapter 9: Trees     