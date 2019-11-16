#include <iostream>
#include <string>

using namespace std;

void reverseCharacters(string& charString, size_t leftIndex, size_t rightIndex) {
    char temp;
    while(leftIndex < rightIndex) {
        temp = charString[leftIndex];
        charString[leftIndex] = charString[rightIndex];
        charString[rightIndex] = temp;
        leftIndex++;
        rightIndex--;
    }
}

void reverseWordChars(string& wordString) {
    size_t place=0;
    for(size_t i=0; i<wordString.size(); i++) {
        if(wordString[i] == ' ' && wordString[i-1] != ' ') {
            reverseCharacters(wordString, place, i-1);
            place = i+1;
        } else if(i==wordString.size()-1) {
            reverseCharacters(wordString, place, i);
        }
    }
}

void reverseWords(string& message)
{
    if(message.size() < 2) return;
    reverseCharacters(message, 0, message.size()-1);
    reverseWordChars(message);
}
