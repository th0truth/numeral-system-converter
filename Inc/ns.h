#pragma once

#ifndef NS_H
#define NS_H

int checkBin(const char* bin);
long binToDec(const char* bin);
long binToOctal(const char* bin);

long hexToBin(const char* hex);
long hexToDec(const char* hex);
long hexToOct(const char* hex);

long octToDec(const char *oct);
long octToBin(const char* oct);

char* decToBin(const char* dec);  
#endif
