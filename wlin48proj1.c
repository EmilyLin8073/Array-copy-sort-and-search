/*----------------------------------------------------------------------------------------
 wlin48Proj1.c

 Project 1
 Class : CS 211
 Author : Emily Lin
 System : Xcode
 ---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

void arrayCopy (int fromArray[], int toArray[], int size);
void myFavorateSort (int arr[], int size);
int linSearch (int arr[], int size, int target, int* numComparisons);
int binSearch (int arr[], int size, int target, int* numComparisons);


//In this funciton, we are copying one array to another
void arrayCopy (int fromArray[], int toArray[], int size)
{
   //Using a for loop to copy entire array to another array
   for(int i = 0; i < size + 1; i++)
      toArray[i] = fromArray[i];
}


//In this function, I'm using bubble sort to sort the array
void myFavorateSort(int arr[], int size)
{
   int temp;

   for(int pass = 1; pass < size; pass++)
   {
      for(int j = 0; j < (size - pass); j++)
      {
         if(arr[j] > arr[j + 1])
         {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}


//In this fuction, we are using linear research to find the target number
int linSearch (int arr[], int size, int target, int *linearNumComparsions)
{
   int positionFound; //Variable to store the position for the target
   *linearNumComparsions = 0;

   //A for loop to go through the entire array in order to find the target number
   for(positionFound = 0; positionFound < size; positionFound++)
   {
      if(arr[positionFound] == target) // If we find the target number, we stop
         break;

      (*linearNumComparsions)++; //We add the number of comparison each time
   }

   //To check if the target is in the array or not, if not, we return -1
   if(positionFound == size)
      return -1;
   else
      return positionFound;
}


//In this function, we are using binary researc to find the target number
int binSearch (int arr[], int size, int target, int *binaryNumComparsions)
{
   int first = 0;                     //The lower boundary of the array
   int last = size + 1;               //The higher boundary of the array
   int middle = ((first + last) - 1) / 2;   //The middle element of the section
   int positionFound = 0;             //Position found for the target number

   *binaryNumComparsions = 0;

   while(first <= last)
   {
      if(arr[middle] < target)       //If the target number we want to find is smaller than the
         first = middle + 1;         //middle number, we continue to find the right side of the array

      else if(arr[middle] > target)  //If the target number we want to find is larger than the
         last = middle - 1;          //middle number, we continue to find the left side of the array

      else
      {
         positionFound = middle;    //We find the target number and returning the index
         break;
      }

      middle = (first + last) / 2; //Reset the middle each search

      (*binaryNumComparsions)++;     //We add the number of comparison each time
   }

   //If the target number is not in the array, we return -1, else we return the position
   //found for the target number
   if(first > last)
      return -1;
   else
      return positionFound;
}


int main()
{
   int size = 100;
   int *arr1 = (int *)malloc(size *sizeof(int));
   int userInput = 0;
   int count = 0;
   int target = 0;
   int positionFound = 0;
   int linearNumComparsions, binaryNumComparsions;

   //Ask user to enter the value
   printf ("Enter in a list of numbers followed by the terminal value of -999 : \n");
   scanf ("%d", &userInput);

   //Loop until user input -999
   while(userInput != -999)
   {
      arr1[count] = userInput; //Store user input into the array
      count = count + 1;  //Count how many number user enter

      //Check whether the array is full or not
      if(count >= size)
      {
         //Grow the array
         int *temp;
         temp = (int *) malloc ( size * 2 * sizeof(int) );

         for (int i = 0 ; i < size ; i++)
            temp[i] = arr1[i];

         free(arr1);
         arr1 = temp;
         size = size * 2;
      }

      scanf("%d", &userInput);
   }

   int arr2[count];  //Array variable for copy the array

   //Print out the original array
   printf("\nOriginal array : ");

   for(int i = 0; i < count; i++)
      printf("\t%d", arr1[i]);


   //Print out the copy array
   printf("\n \nCopied array : ");
   arrayCopy(arr1, arr2, count);

   for(int i = 0; i < count; i++)
      printf("\t%d", arr2[i]);


   //Print out the sorted array
   printf("\n \nSorted array : ");
   myFavorateSort(arr2, count);

   for(int i = 0; i < count; i++)
      printf("\t%d", arr2[i]);


   //Ask user which number they want to find
   printf("\n \nEnter the number you want to find followed by the terminal value of -999 : ");
   scanf("%d", &target);

   while(target != -999)
   {
      //Using linear search
      positionFound = linSearch(arr1, count, target, &linearNumComparsions);

      //If the number thye want to find is in the array, we print out this statement
      if(positionFound != -1)
         printf("\nThe number %d you want to find after using linear search for a unsorted array is at position %d and we have compared to %d numbers \n",
                target, positionFound, linearNumComparsions + 1);

      //If the number is not in the array, we print out this statement
      else
         printf("\nAfter using linear search for a unsorted array and compared to %d numbers, didn't find the number %d. The index for %d is %d\n",
                linearNumComparsions, target, target, positionFound);


      //Using binary search
      positionFound = binSearch (arr2, count, target, &binaryNumComparsions);

      //If the number thye want to find is in the array, we print out this statement
      if(positionFound != -1)
         printf("\nThe number %d you want to find after using binary search for a sorted array is at position %d and we have compared to %d numbers \n",
                target, positionFound, binaryNumComparsions + 1);

      //If the number is not in the array, we print out this statement
      else
         printf("\nAfter using binary search for a sorted array and compared to %d numbers, didn't find the number %d. The index for %d is %d\n",
                binaryNumComparsions, target, target, positionFound);

      scanf("%d", &target);
   }

   return 0;
}













