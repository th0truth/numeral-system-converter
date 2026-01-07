#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "ns.h"

int extractNumberFormat(const char* buffer, char* number, char* format)
{
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

int compare(const char* s1, const char* s2)
{
  for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      return (s1[i] > s2[i]) ? 1 : 1;
    }
  }
}


long ascii_to_integer(const char* number)
{
  long n = 0;
  for (int i = 0; number[i] != '\0'; i++) {
    if (number[i] > '9' || number[i] < '0') {
      return -1;
    }
    n = n * 10 + number[i] - '0';
  }
  return n;
}

int converter(char* res, const char* number, const char* format)
{
  for (int i = 0; number[i] != '\0'; i++) {
    if (number[0] == '0') {
      if ((number[1] == 'b' || number[1] == 'B') && checkBin(number + 2) == 1) {
        if (compare(format, "dec") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", binToDec(number + 2));
        } else if (compare(format, "oct") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", binToOctal(number + 2));
        } else if (compare(format, "hex") == 0) {
          snprintf(res, BUFFER_SIZE, "%X", binToDec(number + 2));
        } else { return 1; }
      } else if (number[1] == 'x' || number[1] == 'X') {
        if (compare(format, "dec") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", hexToDec(number + 2));
        } else if (compare(format, "bin") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", hexToBin(number + 2));
        } else if (compare(format, "oct") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", hexToOct(number + 2));
        } else { return 1; }
      } else {
        if (compare(format, "dec") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", octToDec(number + 1));
        } else if (compare(format, "bin") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", octToBin(number + 1));
        } else if (compare(format, "hex") == 0) {
          snprintf(res, BUFFER_SIZE, "%X", octToDec(number + 1));
        } else { return 1; }
      }
      break;
    }
  }
  return 0;
}