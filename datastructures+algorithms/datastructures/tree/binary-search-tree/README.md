# Binary Search Tree

A **Binary Search Tree (BST)** is a tree in which all the nodes follow the below-mentioned properties:

* The value of the key of the **left sub-tree** is less than the value of its parent (root) node's key.

* The value of the key of the **right sub-tree** is greater than or equal to the value of its parent (root) node's key.

![Binary Search Tree](figures/binary_search_tree.jpg)

BST is a collection of nodes arranged in a way where they maintain BST properties. 
Each node has a **key** and an associated value. 
While searching, the desired key is compared to the keys in BST and if found, the associated value is retrieved.

## Insert Operation

Start searching from the root node, then if the data is less than the key value, search for the empty location 
in the left subtree and insert the data. Otherwise, search for the empty location in the right subtree and insert 
the data.

_Example_: Insert node into a search tree
```C
node_t *tree_insert(node_t *node_ptr, int value)
{
    if(node_ptr == NULL)
        return node_new(value);

    if(value < node_ptr->value)
        node_ptr->left_ptr = tree_insert(node_ptr->left_ptr, value);
    else 
        node_ptr->right_ptr = tree_insert(node_ptr->right_ptr, value);    

    return node_ptr;
}
```


## Search Operation

Whenever an element is to be searched, start searching from the root node. 
Then if the data is less than the key value, search for the element in the left subtree. 
Otherwise, search for the element in the right subtree. 
Follow the same algorithm for each node.

_Example_: Search a node in a search tree
```C
node_t *tree_search(node_t *node_ptr, int value)
{
    if(node_ptr == NULL || node_ptr->value == value)
        return node_ptr;

    if(value < node_ptr->value)
        return tree_search(node_ptr->left_ptr, value);
    else 
        return tree_search(node_ptr->right_ptr, value);    
}
```

## Sort Operation

An **in-order traversal** of binary search tree always produces sorted output.

_Example_: Print values a sorted tree
```C
void tree_print(node_t *node_ptr)
{
    if(node_ptr == NULL)
        return;

    tree_print(node_ptr->left_ptr);
    printf("%d ", node_ptr->value);
    tree_print(node_ptr->right_ptr);
}
```


## References
* [Data Structure and Algorithms - Binary Search Tree](https://www.tutorialspoint.com/data_structures_algorithms/binary_search_tree.htm)


* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
    * Chapter 9: Trees     