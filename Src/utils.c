#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "ns.h"

int extractNumberFormat(const char* buffer, char* number, char* format) {
  int i = 0, space = 0;
  for (; buffer[i] != '\0'; i++) {
    if (buffer[i] != ' ') {
      number[i] = buffer[i];  
    } else {
      space = i;
      break;
    }
  }
  number[i+1] = '\0';
  
  if (!space) {
    return 1;
  }

  int j = 0;
  for (i = space+1; buffer[i] != '\0'; j++, i++)
    format[j] = buffer[i];
  format[j+1] = '\0';
  return 0;
}

int compare(const char* s1, const char* s2) {
  for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      return (s1[i] > s2[i]) ? 1 : 1;
    }
  }
}

int converter(char* res, const char* number, const char* format) {
  ull decimal;
  if (number[0] == '0') {
    if (number[1] == 'b' || number[1] == 'B') {
      if (checkBin(number+2) != 1) {
        return 1;
      }
      decimal = to_decimal(number+2, BIN);
    } else if (number[1] == 'x' || number[1] == 'X') {
      decimal = to_decimal(number+2, HEX);
    } else {
      decimal = to_decimal(number+1, OCT);
    }
  } else {
    decimal = to_decimal(number, DEC);
  }

  if (compare(format, "bin") == 0) {
    char *binary = to_binary(decimal);
    snprintf(res, BUFFER_SIZE, "%s", binary);
    free(binary);
  } else if (compare(format, "dec") == 0) {
    snprintf(res, BUFFER_SIZE, "%llu", decimal);
  } else if (compare(format, "oct") == 0) {
    char *octal = to_octal(decimal);
    snprintf(res, BUFFER_SIZE, "%s", octal);
    free(octal);
  } else if (compare(format, "hex") == 0) {
    snprintf(res, BUFFER_SIZE, "%X", decimal);
  }

  return 0;
}