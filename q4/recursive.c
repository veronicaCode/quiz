#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MIN (-10000)

int max (int a, int b)
{
    return ((a > b)? a : b);
}

int maxSubArray(int A[], int start, int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return max(0, A[start]);
    int middle = (start + end)/2;
    int i = 0, left = MIN, right = MIN, sum;
    sum = 0;
    for (i = middle + 1; i <= end; i++) {
        sum += A[i];
        if (sum > right)
            right = sum;
    }
    sum = 0;
    for (i = middle; i >= start; i--) {
        sum += A[i];
        if (sum > left)
            left = sum;
    }
    sum = left + right;

    return (max(sum, max(maxSubArray(A, start, middle), maxSubArray(A, middle + 1, end))));
}

int main()
{
    int sum, count = 0, i = 0;
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
        sum = maxSubArray(A, 0, count-1);
        printf("%d\n", sum);
    }
    return 0;
}
