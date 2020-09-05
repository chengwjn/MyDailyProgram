#include <stdio.h>
void loveyou(int n)
{
    int i = 1;
    while (i <= n)
    {
        i++;
        printf("I love you %d\n", i);
        for (int j = 1; j <= n; j++)
            printf("I am Iron Man\n");
    }
    printf("I love you More than %d\n", n);
}
int main()
{
    loveyou(100);
}