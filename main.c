#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "ns.h"

int main(void) {  
  char buffer[BUFFER_SIZE];
  char number[BUFFER_SIZE];
  char format[FORMAT_SIZE];

  // Store data in the buffer
  fgets(buffer, BUFFER_SIZE, stdin);

  // Extract number and format from buffer
  int extract = extractNumberFormat(buffer, number, format);
  if (extract == 1) {
    fprintf(stderr, "Failed to extract data from buffer.\n");
    return 1;
  }

  // Allocate memory for a result 
  char *res = malloc(BUFFER_SIZE * sizeof(char));
  if (res == NULL) {
    fprintf(stderr, "Failed to allocate memory.\n");
    return 1;
  }

  // Convert number into specified format
  int convert = converter(res, number, format);
  if (convert == 1) {
    fprintf(stderr, "An error occured while converting number.\n");
    return 1;
  }

  printf("Result: %s\n", res);
  free(res);
 
  return 0;
}
