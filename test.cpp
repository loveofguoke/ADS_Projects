#include <stdio.h>
#include <stdlib.h>

#include "BinaryHeap.h"
#include "LeftistHeap.h"

int main(){
    BinaryHeap H1;
    LeftistHeap H2 = NULL;
    H1 = Initialize(MaxN);

    Insert(1, H1);
    Insert(2, H1);

    printf("%d ", DeleteMin(H1));
    printf("%d ", FindMin(H1));

    H2 = Insert(1, H2);
    H2 = Insert(2, H2);
    H2 = DeleteMin(H2);
    printf("%d ", FindMin(H2));
}