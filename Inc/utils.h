#pragma once

#ifndef UTILS_H
#define UTILS_H

#define NUMBER_SIZE 1024
#define BUFFER_SIZE 4096
#define FORMAT_SIZE 8

int extractNumberFormat(const char* buffer, char* number, char* format);
int converter(char* res, const char* number, const char* format);

#endif