#include"../../head/AQueue.h"

int main()
{
    AQueue *Q = (AQueue *)malloc(sizeof(AQueue));
    InitAQueue(Q);
    Catalogue(Q);
    DestoryAQueue(Q);
    free(Q);
	system("pause");
    return 0;
}

