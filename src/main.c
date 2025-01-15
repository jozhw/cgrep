#include <stdio.h>
#include <stdlib.h>

#include "search_file/search_file.h"


const int LINE_SIZE = 1024;


// char *argv[] represents an array of strings
int main(int argc, char *argv[]){

  if (argc != 3){
    // %s is a format specifier for printf that is used to substitute
    printf("Usage: %s <file name> <pattern>\n", argv[0]);
    return 1;
  }
  
  // * refers to the pointer, thus meaning pointer to the argv[1]
  const char *p_fileName = argv[1];
  const char *p_pattern = argv[2];

  if (search_in_file(p_fileName, p_pattern) == -1){
    fprintf(stderr, "Pattern not found or an error occured.\n");

    return EXIT_FAILURE;
    
  }

  return EXIT_SUCCESS;
}
