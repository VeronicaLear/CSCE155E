/**
 * Author: Veronica Lear
 * Date: 2026/10/15
 *
 * Function definitions for operations on arrays
 */

 #include <stdlib.h>

 #include "array_utils.h"

 int contains(const int *arr, int size, int x) {
    if(arr == NULL) {
        return 2;
    } else if(size < 0) {
        return 3;
    }
    int containsX = 0;
    for(int i=0; i<size; i++) {
        if(arr[i] == x) {
            containsX = 1;
        }
    }
    return containsX;
 }


 int containsWithin(const int *arr, int size, int x, int i, int j)  {
    if(arr == NULL) {
        return 2;
    } else if(size < 0) {
        return 3;
    }
    int xInRange = 0;
    for(int index=i; index<=j; index++) {
        if(arr[index] == x) {
            xInRange = 1;
        }
    }
    return xInRange;
 }


 int * paddedCopy(const int *arr, int oldSize, int newSize) {
    if(arr == NULL) {
        return NULL;
    } else if(oldSize < 0 || newSize < 0) {
        return NULL;
    }

    int *newArr = (int *) malloc(newSize * sizeof(int));

    if(newSize <= oldSize) {
        for(int i=0; i<newSize; i++) {
            newArr[i] = arr[i];
        }
    } else {
        for(int i=0; i<oldSize; i++) {
            newArr[i] = arr[i];
        }
        for(int i=oldSize; i<newSize; i++) {
            newArr[i] = 0;
        }
    }
    return newArr;
 }


 void reverse(int *arr, int size){
    if(arr == NULL) {
        return;
    } else if(size < 0) {
        return;
    }
    int *tempArr = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++) {
        tempArr[i] = arr[i];
    }
    int tempIndex = size - 1;
    for(int i=0; i<size; i++) {
        arr[i] = tempArr[tempIndex];
        tempIndex -= 1;
    }
    free(tempArr);
    return;
 }


 int * reverseCopy(const int *arr, int size){
    if(arr == NULL) {
        return NULL;
    }
    int *NewArr = (int *) malloc(size * sizeof(int));

    int tempIndex = size - 1;
    for(int i=0; i<size; i++) {
        NewArr[i] = arr[tempIndex];
        tempIndex -= 1;
    }
    return NewArr;
 }
