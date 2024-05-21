#include <stdio.h>

#include <glib.h>
#include <gio/gio.h>
#include <gio/gfile.h>

int main(void) 
{
    GError *error = NULL;

    // Create a GFile object
    GFile *file = g_file_new_for_path("example.txt");

    // Query attributes of the file
    GFileInfo *info = g_file_query_info(file, "standard::*", G_FILE_QUERY_INFO_NONE, NULL, &error);
    
    if (!info) 
    {
        printf("Error retrieving file info: %s\n", error->message);
        g_error_free(error);
    } 
    else 
    {
        // Get file size
        guint64 size = g_file_info_get_size(info);
        printf("File size: %llu bytes\n", (unsigned long long)size);

        // Get file type
        GFileType type = g_file_info_get_file_type(info);
        printf("File type: %d\n", type);  // G_FILE_TYPE_REGULAR, G_FILE_TYPE_DIRECTORY, etc.

        // Clean up
        g_object_unref(info);
    }

    // Clean up
    g_object_unref(file);

    return 0;
}
