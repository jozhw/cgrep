// search_file.h
#ifndef SEARCH_FILE_H
#define SEARCH_FILE_H

#include <stddef.h>

// Searches for a pattern in and file and print matching lines
// Returns 0 on success or -1 if an error occurs.
int search_in_file(const char *p_fileName, const char *p_pattern);



#endif // SEARCH_FILE_H
