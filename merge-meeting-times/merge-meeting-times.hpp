#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};

bool compareStarts(const Meeting& m1, const Meeting& m2) {
    return m1.getStartTime() < m2.getStartTime();
}

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
    vector<Meeting> sortedMeetings(meetings);
    sort(sortedMeetings.begin(), sortedMeetings.end(), compareStarts);

    vector<Meeting> mergedMeetings;
    mergedMeetings.push_back(sortedMeetings.front());
    for(int i=0; i<sortedMeetings.size(); i++) {
        Meeting& lastMergedMeeting = mergedMeetings.back();
        if((sortedMeetings[i].getStartTime() <= lastMergedMeeting.getEndTime())) {
            lastMergedMeeting.setEndTime(sortedMeetings[i].getEndTime() > lastMergedMeeting.getEndTime() ? sortedMeetings[i].getEndTime() : lastMergedMeeting.getEndTime());
        } else mergedMeetings.push_back(sortedMeetings[i]);
    }
    return mergedMeetings;
}