#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector)
{
    vector<int> merged;
    int mySize = myVector.size();
    int aliceSize = alicesVector.size();
    if(aliceSize == 0 && mySize==0) return merged;
    if(mySize == 0) return alicesVector;
    if(aliceSize == 0) return myVector;

    int i=0, j=0;
    while(merged.size() < (mySize+aliceSize)) {
        if(i == mySize) {
            merged.push_back(alicesVector[j]);
            break;
        } else if(j == aliceSize) {
            merged.push_back(myVector[i]);
            break;
        } else if(myVector[i] <= alicesVector[j]) {
            merged.push_back(myVector[i]);
            i++;
        } else {
            merged.push_back(alicesVector[j]);
            j++;
        }
    }

    return merged;
}
