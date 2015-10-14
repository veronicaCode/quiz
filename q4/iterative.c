#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int maxSubArray(int A[], int n)
{
    int max_so_far = 0;
    int max_end_here = 0;
    int i = 0;
    for (i = 0; i < n; i++) {
        max_end_here = A[i] + max_end_here;
        if (max_end_here < 0)
            max_end_here = 0;
        if (max_so_far < max_end_here)
            max_so_far = max_end_here;
    }
    return max_so_far;
}

int main()
{
    int count = 0, i = 0;
    int *A;
    while (1) {
        scanf("%d", &count);
        if (count == 0)
            break;
        assert((count > 0) && "Error! The number of array should bigger than 0.");
        i = 0;
        A = (int *) malloc(count * sizeof(int));
        while (i < count) {
            scanf("%d", &A[i]);
            i++;
        }
        count = maxSubArray(A, 9);
        printf("%d\n", count);
    }
    return 0;
}
