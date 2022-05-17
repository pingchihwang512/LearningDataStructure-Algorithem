/*
    Final review and practice writing an array class using C++
    - Remind how to write a c++ class, have to have constructor and deconstructor
    - What is the difference between C and C++
        * structure has to pass into the function's parameter in order to access inside value in C
    - Rememeber the concpet of array. Where are you creating an array? 
*/
#include <iostream>

using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
    public:
        Array(){
            size = 10;
            A = new int [10];
            length = 0;
        }
        Array(int sz){
            size = sz;
            length=0;
            A=new int[size];
        }

        ~Array(){
            delete []A;
        }

        void Display();
        void Append(int x);
        void Insert(int index, int x);
        int Delete(int index);
        void swap(int *x, int *y);
        int LinearSearch(int key);
        int BinarySearch(int key);
        void Reverse();
};

void Array::Display(){
    for(int i=0; i<length; i++){
        cout<<A[i]<< " " << endl;
    }
}

void Array::Append(int x){
    if(length<size){
        A[length++]=x;
    }
}

void Array::Insert(int index, int x){
    int i;
    if(index>=0 && index <= length){
        for(i=length;i>index;i++){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }else{
        cout << "Insert Error!" << endl;
    }
}

int Array::Delete(int index){
    int x=0;
    int i;

    if(index >= 0 && index < length){
        x = A[index];
        for(i = index; i < length - 1; i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }else{
        cout << "Delete Error!" << endl;
    }
    return 0;
}

void Array::swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key){
    
    for(int i = 0; i<length; i++){
        if(key == A[i]){
            swap(&A[i],&A[0]);
            return i;
        }
    }
    return -1;
}

// Binary Search       O(log n)    *Must be sorted , every element is unique
int Array::BinarySearch(int key){
    int l, mid, h;
    l=0;
    h=length-1;

    while(l<=h){
        mid = (l+h)/2;

        if(key==A[mid])
            return mid;
        else if(key<A[mid])
            h = mid - 1;
        else     
            l = mid + 1;
    }
    return -1;
}

void Array::Reverse(){
    int *B;
    int i,j;

    B=(int *)malloc(length*sizeof(int));
    for(i=length-1,j=0;i>=0;i--,j++)
        B[j]=A[i];
     for(i=0;i<length;i++)
        A[i]=B[i];
}

int main(){
    Array *arr1;
    int ch,sz;
    int x, index;
    
    cout << "Enter Size of Array";
    cin >> sz;
    arr1 = new Array(sz);

    do{
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";

        cout<<"enter you choice ";
        cin>>ch;

        switch(ch){
            case 1: cout<<"Enter an element and index ";
                cin>>x>>index;
                arr1->Insert(index,x);
                break;
            case 2: cout<<"Enter index ";
                cin>>index;
                x=arr1->Delete(index);
                cout<<"Deleted Element is"<<x;
                break;
            case 3:cout<<"Enter element to search";
                cin>>x;
                index=arr1->LinearSearch(x);
                cout<<"Element index "<<index;
                break;
            case 4:arr1->Display();
        }
    }while(ch<5);
    return 0;
}

/*
Hint for writing c++ template for generic type

#include <iostream>
using namespace std;
template<class T>

class Array
{
    private:
        T *A;
        int size;
        int length;
    public:
        Array(){
            size=10;
            A=new T[10];
            length=0;
        }
        Array(int sz){
            size=sz;
            length=0;
            A=new T[size];
        }
        ~Array()
        {
            delete []A;
        }
        void Display();
        void Insert(int index,T x);
        T Delete(int index);
};

template<class T>
void Array<T>::Display()
{
    for(int i=0;i<length;i++)
    cout<<A[i]<<" ";
    cout<<endl;
}

template<class T>
void Array<T>::Insert(int index,T x)
{
    if(index>=0 && index<=length){
        for(int i=length-1;i>=index;i--)
            A[i+1]=A[i];
        A[index]=x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index)
{
    T x=0;
    if(index>=0 && index<length){
        x=A[index];
    for(int i=index;i<length-1;i++)
        A[i]=A[i+1];
    length--;
    }
    return x;
}

int main()
{
    Array<char> arr(10);

    arr.Insert(0,'a');
    arr.Insert(1,'c');
    arr.Insert(2,'d');
    arr.Display();
    cout<<arr.Delete(0)<<endl;
    arr.Display();
    return 0;
}
*/