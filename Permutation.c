#include <stdio.h>
#include <string.h>
#include <time.h>
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permutation(char *name, int start, int end)
{
    int i;
    if (start == end)
        printf("%s\n", name);
    else
    {
        for (i = start; i <= end; i++)
        {
            swap((name+start), (name+i));
            permutation(name, start+1, end);
            swap((name+start), (name+i));
        }
    }
}
int main()
{
    clock_t start_t, end_t, total_t, total_clock;
    start_t = clock();
    char name[] = "NECDETALPER";
    int length = strlen(name);
    permutation(name, 0, length-1);
    end_t = clock();
    total_t = (end_t - start_t)/CLOCKS_PER_SEC;
    total_clock=end_t - start_t;
    printf("Total clock: %lu\n", total_clock);
    printf("Total time taken by CPU: %lu\n", total_t);
    return 0;
}

