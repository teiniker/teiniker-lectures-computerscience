# GLib: Doubly-Linked Lists

The GList structure and its associated functions provide a standard doubly-linked 
list data structure. 

The benefit of this data-structure is to provide insertion/deletion operations in 
O(1) complexity where access/search operations are in O(n). 

The benefit of GList over GSList (singly linked list) is that the worst case on 
access/search operations is divided by two which comes at a cost in space as we 
need to retain two pointers in place of one.

Each element in the list contains a piece of data, together with pointers which link 
to the previous and next elements in the list. Using these pointers it is possible 
to move through the list in both directions (unlike the singly-linked GSList, which 
only allows movement through the list in the forward direction).

## Functions

```C
    GList *	g_list_append ()
    GList *	g_list_prepend ()
    GList *	g_list_insert ()
    GList *	g_list_insert_before ()
    GList *	g_list_insert_before_link ()
    GList *	g_list_insert_sorted ()
    GList *	g_list_remove ()
    GList *	g_list_remove_link ()
    GList *	g_list_delete_link ()
    GList *	g_list_remove_all ()
    void	g_list_free ()
    void	g_list_free_full ()
    void	g_clear_list ()
    GList *	g_list_alloc ()
    void	g_list_free_1 ()
    guint	g_list_length ()
    GList *	g_list_copy ()
    GList *	g_list_copy_deep ()
    GList *	g_list_reverse ()
    GList *	g_list_sort ()
    gint	(*GCompareFunc) ()
    GList *	g_list_insert_sorted_with_data ()
    GList *	g_list_sort_with_data ()
    gint	(*GCompareDataFunc) ()
    GList *	g_list_concat ()
    void	g_list_foreach ()
    void	(*GFunc) ()
    GList *	g_list_first ()
    GList *	g_list_last ()
    #define	g_list_previous()
    #define	g_list_next()
    GList *	g_list_nth ()
    gpointer	g_list_nth_data ()
    GList *	g_list_nth_prev ()
    GList *	g_list_find ()
    GList *	g_list_find_custom ()
    gint	g_list_position ()
    gint	g_list_index ()
```


## References

* [GLib Reference Maunal: Singly-Linked Lists](https://gnome.pages.gitlab.gnome.org/libsoup/glib/glib-Singly-Linked-Lists.html)
* [GLib Reference Manual: Doubly-Linked Lists](https://gnome.pages.gitlab.gnome.org/libsoup/glib/glib-Doubly-Linked-Lists.html)

*Egon Teiniker, 2020-2025, GPL v3.0* 