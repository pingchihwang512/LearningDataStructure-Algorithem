/*  
    Array ADT
    1. Data
        - Array Space in stack or heap
        - What is the size of this array
        - How many elements inside the array
    2. Operation
        - Display()             O(n)
            Using loop to print each index, beacuse we using loop, times of iterative is important.     

        - Add(x) / Append(x)    O(1)
            Notice that add here is to increase the size of the array and initialize it. 

        - Insert(index,x)       O(n)
            Update the elements after the index you want to insert, check the size of array and update the possible elements' value to the proper location 

        - Delete(index)         O(n)

        - Search(x)             
            linear Searh        O(n)
                Transposition
                Move to Front/Head
            Binary Search       O(log n)    *Must be sorted and has three elements

            *Sequential Search is the best we can use for find a value in an unsorted array
            *Binary Search is the best we can use for find a value in a sorted array

    3. Understand the syntax of struct in C
    4. Understand the way to contruct an ADT of array
        - Create an array in heap memory, and use a pointer to point at it 
        - Create a fixed size array in stack.
    5. C++ Member(dot & arrow) Operators
        - Dot operator is applied to the "actual" object
        - Arrow operator is used with a pointer to an object.
*/

#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d \n", arr.A[i]);
}

void Append(struct Array *arr, int x){
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr, int index, int x){
    int i;

    if(index>=0 && index <=arr->length){
        for(i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index] = x;
        arr -> length++;
    }else{
        printf("\nInsert Error");
    }
}

void Delete(struct Array *arr, int index){
    int x=0;
    int i;
    if( index >= 0 && index < arr->length ){
        x = arr -> A[index];
        for(i = index; i<arr->length-1 ; i++)
            arr -> A[i] = arr -> A[i+1];
        arr -> length--;
        Display(*arr);
    }else{
        printf("\nDelete Error");
    }
}

int linearSearch(struct Array arr, int target){
    int i;
    for(i=0;i<arr.length;i++){
        if(target == arr.A[i]){
            printf("found");
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Array arr, int target){
    int low, mid, high;
    low = 0;
    high = arr.length-1;
    while(low<=high){
        mid = ( high + low ) / 2;
        if(target==arr.A[mid]){
            printf("got it!");
            return mid;
        }else if(target<arr.A[mid]){
            high = mid-1;
        }else{
            low = mid +1;
        }
    }
    return -1;
}

int rBinarySearch(struct Array arr, int target, int low, int max){
    int mid = 0;
    if(low<=max){
        mid = (low+max)/2;
        if(target==arr.A[mid]){
            printf("found!");
            return mid;
        }else if(target<arr.A[mid]){
            return rBinarySearch(arr,target,low,mid-1);
        }else{
            return rBinarySearch(arr,target,mid+1,max);
        }
    }
    return -1;
}

int main(){
    struct Array arr;
    int n,i;

    printf("Enter the size of an array");
    scanf("%d", &arr.size);
    arr.A=(int *)malloc(arr.size * sizeof(int));
    arr.length=0;

    printf("Enter number of numbers");
    scanf("%d", &n);

    printf("Enter all the Elements\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr.A[i]);
    }
    arr.length=n;

    Display(arr);
    //Append(&arr, 5);
    //Insert(&arr, 5, 6);
    //Delete(&arr, 3);
    //linearSearch(arr,15);
    //binarySearch(arr,15);
    //rBinarySearch(arr,35,0,arr.length);

}