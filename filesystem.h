#ifndef FILESYSTEM_H
#define FILESYSTEM_H

typedef struct
{
    char *path;
    char *content;
    } 
FileEntry;

typedef struct 
{
    FileEntry *entries;
    size_t     count;
} FileSystem;

FILE* open_file(const char *fname);
char *view_file(const char *fname);
int delete_file(const char *fname);
char *new_filesystem ();
int modify_file(const char *fname, const char *new_content);
#endif 
