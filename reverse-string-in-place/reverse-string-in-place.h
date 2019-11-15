#include <stdio.h>

void reverse(char *str)
{
    // in C, char* are null terminated, so we can check their length by using strlen() or by iterating with a counter
    int strLen = 0, terminated=0;
    while(!terminated) {
        if(str[strLen] == '\0') terminated=1;
        else strLen++;
    }
    if(strLen <= 1) return;

    char temp = 't';
    for(int i=0; i<=(strLen/2); i++) {
        temp = str[i];
        str[i] = str[strLen-1-i];
        str[strLen-1-i] = temp;
    }
    

}
