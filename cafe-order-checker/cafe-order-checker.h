#include <assert.h>
#include <stdio.h>

int isFirstComeFirstServed(const int* takeOutOrders, size_t takeOutOrdersSize,
                           const int* dineInOrders, size_t dineInOrdersSize,
                           const int* servedOrders, size_t servedOrdersSize)
{
    if(takeOutOrdersSize + dineInOrdersSize != servedOrdersSize) return 0;
    for(int j=0, k=0; j+k < servedOrdersSize;) {
        if(j==takeOutOrdersSize) {
            if(dineInOrders[k] != servedOrders[j+k]) return 0;
            k++;
        } else if(k==dineInOrdersSize) {
            if(takeOutOrders[j] != servedOrders[j+k]) return 0;
            j++;
        } else if(takeOutOrders[j] < dineInOrders[k]) {
            if(takeOutOrders[j] != servedOrders[j+k]) return 0;
            j++;
        } else {
            if(dineInOrders[k] != servedOrders[j+k]) return 0;
            k++;
        }
    }

    return 1;
}
