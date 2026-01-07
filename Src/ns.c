#include <string.h>

#include "utils.h"
#include "ns.h"

int checkBin(const char* bin)
{
  int i = 0;
  while (bin[i] != '\0') {
    if (bin[i] != '0' && bin[i] != '1') {
      return 0;
    }
    i++;
  }
  return 1;
}


long binToDec(const char* bin)
{
  int dec = 0, base = 1, reminder;
  
  while (*bin) {
    dec = dec * 2 + (*bin - '0');
    bin++;
  }

  return dec;
}


long binToOctal(const char* bin)
{
  int octal = 0, base = 1, reminder;

  // Binary to decimal
  long dec = binToDec(bin);

  // Decimal to octal
  while (dec != 0) {
    reminder = dec % 8;
    octal += reminder * base;
    base *= 10;
    dec /= 8;
  }

  return octal;
}


long hexToDec(const char* hex)
{
  int decimal = 0, base = 1, i;
  for(i = strlen(hex) - 1; i >= 0; i--) {
    if(hex[i] >= '0' && hex[i] <= '9') {
      decimal += (hex[i] - 48) * base;
    } else if(hex[i] >= 'A' && hex[i] <= 'F') {
      decimal += (hex[i] - 55) * base;
    } else if(hex[i] >= 'a' && hex[i] <= 'f') {
      decimal += (hex[i] - 87) * base;
    }
    base *= 16;
  }
  return decimal;
}


long hexToBin(const char *hex)
{
  long bin = 0ll;
  for (int i = 0; hex[i] != '\0'; i++) {
    bin *= 10000;
    switch (hex[i])
    {
      case '0': bin += 0; break;
      case '1': bin += 1; break;
      case '2': bin += 10; break;
      case '3': bin += 11; break;
      case '4': bin += 100; break;
      case '5': bin += 101; break;
      case '6': bin += 110; break;
      case '7': bin += 111; break;
      case '8': bin += 1000; break;
      case '9': bin += 1001; break;
      case 'a': case 'A': bin += 1010; break;
      case 'b': case 'B': bin += 1011; break;
      case 'c': case 'C': bin += 1100; break;
      case 'd': case 'D': bin += 1101; break;
      case 'e': case 'E': bin += 1110; break;
      case 'f': case 'F': bin += 1111; break;
    }
  }

  return bin;
}