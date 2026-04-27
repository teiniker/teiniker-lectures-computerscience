# GLib: Stack

GLib does not provide a dedicated stack type. Instead, a stack can be implemented
using **GQueue** by restricting operations to the head of the queue.

`g_queue_push_head()` pushes a new element onto the top of the stack, and
`g_queue_pop_head()` removes and returns the top element — giving classic
**LIFO** (Last In, First Out) behaviour.

## Key Functions

```C
    GQueue *  g_queue_new ()
    void      g_queue_free ()
    void      g_queue_clear ()

    void      g_queue_push_head ()   // push
    gpointer  g_queue_pop_head ()    // pop  (returns NULL if empty)
    gpointer  g_queue_peek_head ()   // peek (top element, no removal)

    gboolean  g_queue_is_empty ()
    guint     g_queue_get_length ()
```

## Example

```C
GQueue *stack = g_queue_new();

g_queue_push_head(stack, "one");
g_queue_push_head(stack, "two");
g_queue_push_head(stack, "three");

// LIFO order: three, two, one
printf("%s\n", (char *) g_queue_pop_head(stack));  // three
printf("%s\n", (char *) g_queue_pop_head(stack));  // two
printf("%s\n", (char *) g_queue_pop_head(stack));  // one

g_queue_free(stack);
```

## References

* [GLib Reference Manual: Double-ended Queues](https://docs.gtk.org/glib/struct.Queue.html)

*Egon Teiniker, 2020-2026, GPL v3.0*
