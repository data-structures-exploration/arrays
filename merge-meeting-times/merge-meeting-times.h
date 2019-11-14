#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int startTime;
    unsigned int endTime;
} Meeting;

int compareMeetings(const void* p1, const void* p2) {
    const Meeting* m1 = (const Meeting*) p1;
    const Meeting* m2 = (const Meeting*) p2;
    return (m1->startTime - m2->startTime);
}

int max(int a, int b) {
    if(a<b) return b;
    else return a;
}

size_t mergeRanges(const Meeting *input, size_t inputLength,
                   Meeting *output, size_t maxOutputLength)
{
    //check input
    assert(inputLength > 0);
    assert(maxOutputLength == inputLength);

    //copy the input to avoid modifying it
    Meeting* sortedMeetings;
    size_t meetingSize = sizeof(Meeting);
    sortedMeetings = malloc(meetingSize*inputLength);
    memcpy(sortedMeetings, input, meetingSize*inputLength);

    qsort(sortedMeetings, inputLength, meetingSize, compareMeetings);

    //prepare the output
    output[0] = sortedMeetings[0];
    int mergedMeetingsLength = 1;

    for(int j=1; j<inputLength; j++) {
        Meeting* lastMergedMeeting = &output[mergedMeetingsLength-1];
        Meeting* currentMeeting = &sortedMeetings[j];
        if(lastMergedMeeting->endTime >= currentMeeting->startTime) {
            lastMergedMeeting->endTime = max(lastMergedMeeting->endTime, currentMeeting->endTime);
        } else {
            output[mergedMeetingsLength] = sortedMeetings[j];
            mergedMeetingsLength++;
        }
    }

    //free memory
    free(sortedMeetings);

    // for(int i=0; i<mergedMeetingsLength; i++) {
    //     printf("(%d, %d), ", output[i].startTime, output[i].endTime);
    // }
    // printf("\n");

    return mergedMeetingsLength;
}