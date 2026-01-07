#pragma once

#ifndef UTILS_H
#define UTILS_H

#define NUMBER_SIZE 64
#define BUFFER_SIZE 128
#define FORMAT_SIZE 8

int extractNumberFormat(const char* buffer, char* number, char* format);
long ascii_to_integer(const char* number);

int converter(char* res, const char* number, const char* format);

#endif