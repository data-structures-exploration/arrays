#include <iostream>
#include <string>

using namespace std;

void reverse(string& str)
{
    char temp;
    int leftIndex=0, rightIndex=str.length()-1;
    while(leftIndex < rightIndex) {
        temp = str[leftIndex];
        str[leftIndex] = str[rightIndex];
        str[rightIndex] = temp;
        leftIndex++;
        rightIndex--;
    }

}
