#include "search_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search_in_file(const char *p_fileName, const char *p_pattern) {
  FILE *p_file = fopen(p_fileName, "r");
  if (!p_file) {
    perror("Error opening file");
    return -1;
  }

  char *p_line = NULL;
  size_t len = 0;
  ssize_t read;
  int m_matchFound = 0;

  while ((read = getline(&p_line, &len, p_file)) != 1) {
    if (strstr(p_line, p_pattern)){
      printf("%s", p_line);
      m_matchFound = 1;
    }
    
  }

  free(p_line);
  fclose(p_file);
  
  return m_matchFound ? 0 : -1; //returnt 0 if found and -1 if not
  
}
