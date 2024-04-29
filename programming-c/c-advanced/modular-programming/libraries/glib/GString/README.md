# GLib: GString

A GString is an object that handles the **memory management of a C string** 
for us. The emphasis of GString is on text, typically UTF-8. 

Crucially, the `str` member of a GString is guaranteed to have a trailing 
null character.


## Functions

```C
    GString *	g_string_new ()
    GString *	g_string_new_len ()
    GString *	g_string_sized_new ()
    GString *	g_string_assign ()
    void	g_string_vprintf ()
    void	g_string_append_vprintf ()
    void	g_string_printf ()
    void	g_string_append_printf ()
    GString *	g_string_append ()
    GString *	g_string_append_c ()
    GString *	g_string_append_unichar ()
    GString *	g_string_append_len ()
    GString *	g_string_append_uri_escaped ()
    GString *	g_string_prepend ()
    GString *	g_string_prepend_c ()
    GString *	g_string_prepend_unichar ()
    GString *	g_string_prepend_len ()
    GString *	g_string_insert ()
    GString *	g_string_insert_c ()
    GString *	g_string_insert_unichar ()
    GString *	g_string_insert_len ()
    GString *	g_string_overwrite ()
    GString *	g_string_overwrite_len ()
    guint	g_string_replace ()
    GString *	g_string_erase ()
    GString *	g_string_truncate ()
    GString *	g_string_set_size ()
    gchar *	g_string_free ()
    GBytes *	g_string_free_to_bytes ()
    GString *	g_string_up ()
    GString *	g_string_down ()
    guint	g_string_hash ()
    gboolean	g_string_equal ()
```

## Types and Values

```C
struct GString {
  gchar  *str;
  gsize len;
  gsize allocated_len;
};
```

## References

* [GLib Reference Manual: Strings](https://developer-old.gnome.org/glib/unstable/glib-Strings.html)

*Egon Teiniker, 2020-2024, GPL v3.0* 