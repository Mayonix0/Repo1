#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100];
    int ele, ele1, ele2, size,posu, posi, posd, i;

    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    printf("Enter the element in the array:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("List before Updation of element is:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\nEnter the new element you want to update in the array:\n");
    scanf("%d", &ele1);

    printf("Enter the position where you want to update the element:\n");
    scanf("%d", &posu);

    arr[posu] = ele1;

    printf("List after Updation of element is:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\nList before Insertion of element is:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\nEnter the element you want to insert in array:\n");
    scanf("%d", &ele);

    printf("Enter the position where you want to insert the element:\n");
    scanf("%d", &posi);

    for(i = size-1; i >= posi; i--)
        arr[i+1] = arr[i];
    arr[posi] = ele;

    printf("List after Insertion of element is:\n");
    for (i = 0; i < size+1; i++)
        printf("%d ", arr[i]);

    printf("\nEnter the position where you want to delete the element:\n");
    scanf("%d", &posd);

    for (i = posd; i <= size-1; i++)
        arr[i] = arr[i+1];

    printf("List after Deletion of element is:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}