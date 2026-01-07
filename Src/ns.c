#include <string.h>
#include <stdio.h>
#include <math.h>

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
  int base = 1, reminder;
  long decimal = 0; 
  while (*bin != 0) {
    decimal = decimal * 2 + (*bin - '0');
    bin++;
  }
  return decimal;
}


long binToOctal(const char* bin)
{
  int octal = 0, base = 1, reminder;

  // Binary to decimal
  long decimal = binToDec(bin);

  // Decimal to octal
  while (decimal != 0) {
    reminder = decimal % 8;
    octal += reminder * base;
    base *= 10;
    decimal /= 8;
  }
  return octal;
}


long hexToDec(const char* hex)
{
  long decimal = 0;
  for(int base = 1, i = strlen(hex) - 1; i >= 0; i--) {
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


long hexToBin(const char* hex)
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


long hexToOct(const char* hex)
{
  int reminder, value;
  long octal = 0ll;
  
  // Convert hex to bin, then bin to octal
  long bin = hexToBin(hex); 
  for (int i = 1; bin > 0; i *= 10)
  {
    reminder = bin % 1000;
    switch (reminder)
    {
      case 0: value = 0; break;
      case 1: value = 1; break;
      case 10: value = 2; break;
      case 11: value = 3; break;
      case 100: value = 4; break;
      case 101: value = 5; break;
      case 110: value = 6; break;
      case 111: value = 7; break;
    }
    octal = (value * i) + octal;
    bin /= 1000;
  }
  return octal;
}


long octToDec(const char* oct)
{
  long decimal = 0;
  long octal = ascii_to_integer(oct);
  for (int i = 0; octal != 0; i++) {
    decimal = decimal + (octal % 10) * pow(8, i);
    octal /= 10;
  }
  return decimal;
}


long octToBin(const char* oct)
{
  long binary = 0;
  
  // Convert octal to decimal, then decimal to binary 
  long decimal = octToDec(oct);
  for (int i = 1; decimal != 0; i *= 10) {
    binary += ((decimal % 2) * i);
    decimal /= 2;
  }
  return binary;
}