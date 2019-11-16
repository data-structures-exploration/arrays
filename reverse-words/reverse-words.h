#include <assert.h>
#include <stdio.h>
#include <string.h>

void reverseStringChars(char* charStr, size_t leftIndex, size_t rightIndex) {
    char temp;
    while(leftIndex < rightIndex) {
        temp = charStr[leftIndex];
        charStr[leftIndex] = charStr[rightIndex];
        charStr[rightIndex] = temp;
        leftIndex++;
        rightIndex--;
    }
}

void reverseStringWordChars(char* charStr) {
    size_t place = 0;
    size_t length = strlen(charStr);
    for(size_t i=0; i<length; i++) {
        if(i == length-1) {
            reverseStringChars(charStr, place, i);
            return;
        } else if(charStr[i] == ' ') {
            reverseStringChars(charStr, place, i-1);
            place = i+1;
        }
    }
}

void reverseWords(char *message) {
    //handle edge cases
    size_t length = strlen(message);
    if(length < 2) return;
    //char* length is available via strlen(char*) or iteration with counter until null terminating character, '\0'
    reverseStringChars(message, 0, length-1);
    reverseStringWordChars(message);
}
