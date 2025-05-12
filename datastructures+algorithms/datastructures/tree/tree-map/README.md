# Tree Map 




## Remove a Key/Value Pair

The function `node_remove()` removes a node with the specified key from a binary search tree (BST). 

### Concept 

To guarantee the properties of a BST, the function handles three cases based on the number of 
children of the node to be deleted:

* **Case 1: Deleting a Leaf Node** 

    Before Deletion:
    ```
         50
        /  \
      30    70
      / \   / \
    20  40 60  80
    ```

    Deleting Node 20 (a leaf node):
    ```
         50
        /  \
       30   70
        \   / \
        40 60  80
    ```

    Node `20` is a leaf node with no children. 
    It can be removed directly without affecting other nodes.


* **Case 2: Deleting a Node with One Child** 

    Before Deletion:
    ```
         50
        /  \
       30   70
      / \     \
     20  40    80
    ```

    Deleting Node 70 (has one child - 80):
    ``` 
         50
        /  \
      30    80
      / \
    20  40
    ```

    Node `70` has one child (`80`). 
    After deletion, its child (`80`) takes its place.


* **Case 3: Deleting a Node with Two Children**
    
    Before Deletion:
    ```
         50
        /  \
      30    70
      / \   / \
    20  40 60  80
    ```

    Deleting Node 50 (has two children):
    ```
         60
        /  \
      30    70
      / \     \
    20  40    80 
    ```

    Node `50` has two children. We find its in-order successor 
    (smallest node in the right subtree), which is `60`. 
    Replace `50` with `60`, and then delete the original `60` node.



### Implementation

```C
if (root == NULL)
    return NULL;
```

*  If the current subtree is empty, nothing to delete—return `NULL`.


```C
if (key < root->key)
    root->left_ptr = node_remove(root->left_ptr, key);
else if (key > root->key)
    root->right_ptr = node_remove(root->right_ptr, key);
```

* If the **key is less than the current node's key**, recurse into the left subtree.

* If the **key is greater**, recurse into the right subtree.



```C
else 
{
    // We've found the node to remove
```

**Case 1: Node has no left child**:

```C
    if (root->left_ptr == NULL) 
    {
        node_t* temp = root->right_ptr;
        free(root);
        return temp;
    }
```

* Just replace the node with its right child (can be NULL too).
* This works if the node has no children or only a right child.


**Case 2: Node has no right child**:
```C
    else if (root->right_ptr == NULL) 
    {
        node_t* temp = root->left_ptr;
        free(root);
        return temp;
    }
```
* Similar to Case 1, but the node only has a left child.


**Case 3: Node has two children**:

```C
    node_t* temp = find_min(root->right_ptr);
    root->key = temp->key;
    root->value = temp->value;
    root->right_ptr = node_remove(root->right_ptr, temp->key);
```

* Find the in-order successor (smallest node in the right subtree).
* Copy its key and value into the current node.
* Delete the successor recursively from the right subtree.

```C
    return root;
}
```
* After possible modifications, return the current subtree root up the recursion stack.

