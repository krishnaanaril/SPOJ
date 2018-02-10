#include <stdio.h>

int main()
{
    int h=8;
    int ans = h++ + h++ + h++;
    printf("%d %d\n", ans, h);
    return 0;
}
