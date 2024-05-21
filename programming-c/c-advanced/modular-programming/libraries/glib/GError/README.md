# GError

`GError` is a struct used in GLib to manage errors in a systematic way across 
various functions and libraries that use GLib. It is designed to make error 
reporting and handling more consistent and flexible compared to traditional 
error handling mechanisms in C, such as returning special error codes or setting 
global variables like errno.


The GError structure is defined as follows:

```Java
struct GError {
    GQuark domain;
    gint code;
    gchar *message;
};
```

* **domain**: A `GQuark` (a unique integer associated with a string) that identifies 
    the "error domain". This domain typically corresponds to the **module or library** 
    where the error originated, helping to categorize the errors.

* **code**: An integer that specifies the **error code** within the domain. Each domain 
    can define its own set of error codes.

* **message**: A human-readable string that **describes the error**. This string is 
    intended to be detailed enough to help developers or users understand what went wrong.


## Usage of GError

`GError` is used in a way that functions taking a `GError**` argument can report errors. 
It's up to the caller to pass a pointer to a `GError*` that is initially set to `NULL`. 

If an error occurs, the function sets the `GError*` to point to a newly allocated `GError` 
containing details about the error. If no error occurs, the `GError*` remains `NULL`.






## References

* [GLib Reference Manual: Error Reporting](https://developer-old.gnome.org/glib/unstable/glib-Error-Reporting.html)

*Egon Teiniker, 2020-2024, GPL v3.0* 