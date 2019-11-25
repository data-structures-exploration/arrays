#include <iostream>
#include <vector>

using namespace std;

bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders) {
    if(servedOrders.empty() || dineInOrders.empty() || takeOutOrders.empty()) return true;
    if(servedOrders.size() != dineInOrders.size()+takeOutOrders.size()) return false;
    vector<int>::const_iterator i = takeOutOrders.cbegin(), j = dineInOrders.cbegin(), k=servedOrders.cbegin();
    bool iEnd=false, jEnd=false;
    while(!iEnd || !jEnd) {
        if(iEnd) {
            if(*j != *k) return false;
            j++;
        } else if(jEnd) {
            if(*i != *k) return false;
            i++;
        } else {
            if(*i < *j) {
                if(*i != *k) return false;
                i++;
            } else {
                if(*j != *k) return false;
                j++;
            }
        }
        k++;
        iEnd = i == takeOutOrders.cend();
        jEnd = j == dineInOrders.cend();
    }
    return true;
}
