#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define HASH_SIZE 500000
int hash_func(int v){
    int key = (v) % HASH_SIZE;
    return key < 0 ? key + HASH_SIZE : key; 
}

void insert(int *hash_table, int key, int value){   
    hash_table[hash_func(key)] = value;
}

int find(int *hash_table, int key){
    return hash_table[hash_func(key)];
}

int res[2];
int* twoSum(int* nums, int numsSize, int target){
    int hash[HASH_SIZE] = {0};
    
    for(int i = 0; i <numsSize; i++){
        int found = find(hash, target - nums[i]);
        if (found){
            res[1] = i;
            res[0] = found -1;
            return res;
        }
        insert(hash, nums[i], i+1);
    } 
    return res;
}


int main() {
   int n, target, *res;
    scanf("%d %d",&n,&target);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    res = twoSum(arr,n,target);
    for (int i = 0; i < 2; i++) 
        printf("%d ", res[i]);
 // for (int i = 0; i < n; i++) {
 //        printf("%d ", arr[i]);
 //    }
}