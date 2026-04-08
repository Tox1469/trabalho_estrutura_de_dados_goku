#include <stdio.h>

int main() {
    int arr[5];
    int *ptr = arr;
    int i;

    printf("Digite 5 numeros inteiros:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", (ptr + i));
    }

    printf("\nDobro de cada valor:\n");
    for (i = 0; i < 5; i++) {
        printf("%d * 2 = %d\n", *(ptr + i), *(ptr + i) * 2);
    }

    return 0;
}
