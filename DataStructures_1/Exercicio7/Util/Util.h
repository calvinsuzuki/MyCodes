#ifndef UTIL_H
#define UTIL_H

#define TRUE 1
#define FALSE 0

typedef int boolean;

void boolean_print(boolean bool);

char *readLine();

char *readUntil(char stopChar);

#endif //UTIL_H
