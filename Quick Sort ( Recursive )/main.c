/**********************************************
            Bubble Sort
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100


/******************  Global declarations  ***************/

int Data_array[MAX];

int No_of_elements;

/*********************************************************/

/************************ Prototype of the Functions *****************/

void getData();

void generateData();

void display();

//_______________________ Necessary Functions for Quick Sort ________

int partition(int,int);

void quick_sort(int,int);

void swap(int,int);

/*********************************************************************/


// _____________________ Utility Functions ________________

int menu();

void run();

/********************************************************/

//________________________ Main Function ________________

int main()
{
    run();
    return 0;
}

//__________________END of Main Function ________________


/*****************   Function Definitions  ***************/

void getData()
{
    int i;
    printf("\nEnter %d data one by one \n",No_of_elements);
    for(i=0;i<No_of_elements;i++)
    {
        printf("\nEnter data number %d = ",i+1);
        scanf("%d",&Data_array[i]);
    }
}

void generateData()
{
    int i;
    srand(time(0));
    for(i=0;i<No_of_elements;i++)
        Data_array[i]=rand()%100;
}

void display()
{
    int i;
    printf("\nThe elements in the array :-\n");
    for(i=0;i<No_of_elements;i++)
        printf("  %d",Data_array[i]);
    printf("\n");
}


int partition(int low,int high)
{
    int pivot=Data_array[low];
    int i=low,j=high;
    while(i<j)
    {
        while(Data_array[i]<=pivot)
            i++;
        while(Data_array[j]>pivot)
            j--;

        if(i<j)
            swap(i,j);
    }
    swap(low,j);
    return j;
}

void quick_sort(int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(low,high);
        quick_sort(low,j);
        quick_sort(j+1,high);
    }
}

