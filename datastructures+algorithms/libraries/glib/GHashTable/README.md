# GLib: Hash Tables

A GHashTable provides associations between keys and values which is optimized so that given a key, 
the associated value can be found, inserted or removed in **amortized O(1)**. 

Neither keys nor values are copied when inserted into the `GHashTable`, so they must exist 
for the lifetime of the `GHashTable`.

_Example:_ Setup and teardown of a `GHashTable`
```C    
GHashTable *table = NULL;

void setUp(void)
{
    table = g_hash_table_new(g_direct_hash, g_direct_equal);
    g_hash_table_insert(table, GINT_TO_POINTER(1), "one");
    g_hash_table_insert(table, GINT_TO_POINTER(2), "two");
    g_hash_table_insert(table, GINT_TO_POINTER(3), "three");
}

void tearDown(void)
{
    g_hash_table_destroy(table);
    table = NULL;
}
```

* `g_hash_table_new()` creates a new hash table.
    - `g_direct_hash` and `g_direct_equal` are used because keys are direct 
        pointers (actually small integers stored as pointers).

* `g_hash_table_insert()` inserts a new key-value pair into the hash table.
    - `GINT_TO_POINTER()` is a macro that converts an integer to a pointer.

* `g_hash_table_destroy()` frees the hash table and all its contents.    


_Example:_ Retrieving the size of a `GHashTable`
```C
void test_size(void)
{
    size_t size = g_hash_table_size(table);
    TEST_ASSERT_EQUAL(3, size);
}
```

* `g_hash_table_size()` returns the number of key-value pairs in the hash table.

_Example:_ Retrieving a value from a `GHashTable`
```C
void test_get(void) 
{
    TEST_ASSERT_EQUAL_STRING("two", g_hash_table_lookup(table, GINT_TO_POINTER(2)));
    TEST_ASSERT_EQUAL_STRING("one", g_hash_table_lookup(table, GINT_TO_POINTER(1)));
    TEST_ASSERT_EQUAL_STRING("three", g_hash_table_lookup(table, GINT_TO_POINTER(3)));
}
```

* `g_hash_table_lookup()` retrieves the value associated with a given key.
    - `GINT_TO_POINTER()` is used to convert the integer key to a pointer.

_Example:_ Check is the key is in the `GHashTable`
```C
void test_contains(void)
{
    gboolean contains = g_hash_table_contains(table, GINT_TO_POINTER(2));
    TEST_ASSERT_TRUE(contains);
}
```

* `g_hash_table_contains()` checks if a key is present in the hash table.
    - `GINT_TO_POINTER()` is used to convert the integer key to a pointer.


_Example:_ Remove a key/value pair from a `GHashTable`
```C 
void test_remove(void)
{
    g_hash_table_remove(table, GINT_TO_POINTER(2));
    
    gboolean contains = g_hash_table_contains(table, GINT_TO_POINTER(2));
    TEST_ASSERT_FALSE(contains);
}
``` 
* `g_hash_table_remove()` removes a key-value pair from the hash table.
    - `GINT_TO_POINTER()` is used to convert the integer key to a pointer.


_Example:_ Iterate over a `GHashTable`
```C
void print_entry(gpointer key, gpointer value, gpointer user_data) 
{
    int int_key = GPOINTER_TO_INT(key);
    char *str_value = (char *)value;
    printf("Key: %d, Value: \"%s\"\n", int_key, str_value);
}

void test_print(void)
{
    g_hash_table_foreach(table, print_entry, NULL);
}

```

* `g_hash_table_foreach()` iterates over all key-value pairs in the hash table.
    - `print_entry` is a function that will be called for each entry in the hash table.


## Functions

```C
    GHashTable *g_hash_table_new ()
    GHashTable *g_hash_table_new_full ()
    GHashTable *g_hash_table_new_similar ()
    guint (*GHashFunc) ()
    gboolean (*GEqualFunc) ()
    gboolean g_hash_table_insert ()
    gboolean g_hash_table_replace ()
    gboolean g_hash_table_add ()
    gboolean g_hash_table_contains ()
    guint g_hash_table_size ()
    gpointer g_hash_table_lookup ()
    gboolean g_hash_table_lookup_extended ()
    void g_hash_table_foreach ()
    gpointer g_hash_table_find ()
    void (*GHFunc) ()
    gboolean g_hash_table_remove ()
    gboolean g_hash_table_steal ()
    gboolean g_hash_table_steal_extended ()
    guint g_hash_table_foreach_remove ()
    guint g_hash_table_foreach_steal ()
    void g_hash_table_remove_all ()
    void g_hash_table_steal_all ()
    GList *g_hash_table_get_keys ()
    GList *g_hash_table_get_values ()
    gpointer *g_hash_table_get_keys_as_array ()
    gboolean (*GHRFunc) ()
    #define	g_hash_table_freeze()
    #define	g_hash_table_thaw()
    void g_hash_table_destroy ()
    GHashTable *g_hash_table_ref ()
    void g_hash_table_unref ()
    void g_hash_table_iter_init ()
    gboolean g_hash_table_iter_next ()
    GHashTable *g_hash_table_iter_get_hash_table ()
    void g_hash_table_iter_replace ()
    void g_hash_table_iter_remove ()
    void g_hash_table_iter_steal ()
    gboolean g_direct_equal ()
    guint g_direct_hash ()
    gboolean g_int_equal ()
    guint g_int_hash ()
    gboolean g_int64_equal ()
    guint g_int64_hash ()
    gboolean g_double_equal ()
    guint g_double_hash ()
    gboolean g_str_equal ()
    guint g_str_hash ()
```


## References

* [GLib Reference Maunal: Hash Tables](https://gnome.pages.gitlab.gnome.org/libsoup/glib/glib-Hash-Tables.html)

*Egon Teiniker, 2020-2025, GPL v3.0* 