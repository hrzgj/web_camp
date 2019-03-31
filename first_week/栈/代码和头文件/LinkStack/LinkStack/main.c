#include"LinkStack.h"

int main()
{
    int n=1;
    LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	initLStack(s);
    while(n == 1)
    {
        userFace(s);
        printf("\n\t\t\t\t你想继续吗？(1:继续/其他：否)");
        scanf("%d",&n);
    }
    destroyLStack(s);
    free(s);
    return 0;
}
