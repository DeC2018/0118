#include <stdio.h>
#include <stdlib.h>

// Return an array of arrays of size *returnSize.
// The sizes of the arrays are returned as *returnColumnSizes array.
// Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;
    int** result = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        result[i][0] = 1;
        result[i][i] = 1;
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    
    return result;
}

// Helper function to print Pascal's triangle
void printTriangle(int** triangle, int returnSize, int* returnColumnSizes) {
    printf("[");
    for (int i = 0; i < returnSize; ++i) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d", triangle[i][j]);
            if (j + 1 < returnColumnSizes[i]) printf(",");
        }
        printf("]");
        if (i + 1 < returnSize) printf(",");
    }
    printf("]\n");
}

int main() {
    int returnSize, *returnColumnSizes;
    int numRows1 = 5;
    printf("Input: numRows = %d\n", numRows1);
    int** triangle1 = generate(numRows1, &returnSize, &returnColumnSizes);
    printf("Output: ");
    printTriangle(triangle1, returnSize, returnColumnSizes);
    for (int i = 0; i < returnSize; ++i) free(triangle1[i]);
    free(triangle1);
    free(returnColumnSizes);

    int numRows2 = 1;
    printf("Input: numRows = %d\n", numRows2);
    int** triangle2 = generate(numRows2, &returnSize, &returnColumnSizes);
    printf("Output: ");
    printTriangle(triangle2, returnSize, returnColumnSizes);
    for (int i = 0; i < returnSize; ++i) free(triangle2[i]);
    free(triangle2);
    free(returnColumnSizes);

    return 0;
}
