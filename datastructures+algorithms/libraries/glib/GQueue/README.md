# GLib: Queue

GLib provides a **GQueue** type that implements a double-ended queue. When
operations are restricted to `push_tail` (enqueue) and `pop_head` (dequeue),
it behaves as a classic **FIFO** (First In, First Out) queue.

## Key Functions

```C
    GQueue *  g_queue_new ()
    void      g_queue_free ()
    void      g_queue_clear ()

    void      g_queue_push_tail ()   // enqueue
    gpointer  g_queue_pop_head ()    // dequeue (returns NULL if empty)
    gpointer  g_queue_peek_head ()   // peek at front element (no removal)

    gboolean  g_queue_is_empty ()
    guint     g_queue_get_length ()
```

## Example

```C
GQueue *queue = g_queue_new();

g_queue_push_tail(queue, "one");
g_queue_push_tail(queue, "two");
g_queue_push_tail(queue, "three");

// FIFO order: one, two, three
printf("%s\n", (char *) g_queue_pop_head(queue));  // one
printf("%s\n", (char *) g_queue_pop_head(queue));  // two
printf("%s\n", (char *) g_queue_pop_head(queue));  // three

g_queue_free(queue);
```

## References

* [GLib Reference Manual: Double-ended Queues](https://docs.gtk.org/glib/struct.Queue.html)

*Egon Teiniker, 2020-2026, GPL v3.0*
