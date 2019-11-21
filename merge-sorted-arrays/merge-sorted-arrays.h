#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int * mergeArrays(const int *myArray, size_t myLength,
                  const int *alicesArray, size_t alicesLength)
{   
    if(myLength == 0 && alicesLength == 0) return NULL;
    int* merged = malloc(sizeof(int) * (myLength + alicesLength));
    // always check to make sure malloc worked
    assert(merged != NULL);
    int i=0, j=0, iEmpty=0, aliceEmpty=0;
    while((i+j) < (myLength+alicesLength)) {
        iEmpty = i >= myLength;
        aliceEmpty = j >= alicesLength;
        if(iEmpty) {
            merged[i+j] = alicesArray[j];
            j++;
        } else if(aliceEmpty) {
            merged[i+j] = myArray[i];
            i++;
        } else if(myArray[i] <= alicesArray[j]) {
            merged[i+j] = myArray[i];
            i++;
        } else {
            merged[i+j] = alicesArray[j];
            j++;
        }
    }
    return merged;
}