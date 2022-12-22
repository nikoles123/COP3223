//Nikole Solano
//Homework 2 "homework3.c"
//COP3223C Section 1, Fall 2020

#include <stdio.h>
#include <string.h>

//problem 1
//The function takes a text and returns the number of words in it
//“words” are anything separated with the following symbols:
//space, comma, dot, colon, semi-colon, question sign, or exclamation sign
//outputs # of words in the string
unsigned long long CountWords(char text[])
{
    int wordcount=0;
    //this finds the length of the string
    int length=strlen(text);
    //this is how we are going to check if there is a word or not
    int text2[length];
    
    //this iteraties through the entire array
    for(int i = 0; i <= length-1; i++)
    {
        //this checks to see if there is any of the following symbols
        if(text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == ';'||text[i] == '?' || text[i] == '!')
        {
            //if there is, text2 is set to 1
            text2[i]=1;
        }
        else
        {
            //if there is not, text2 is set to 0
            text2[i]=0;
        }
    }
    for(int i = 0; i <= length-1; i++)
    {
        //this checks to see if there is a symbol and a "word" next to each other
        //if they are nto equal, it means that there is a new word
        //so we can add one to the wordcount
        if(text2[i] != text2[i+1])
        {
            wordcount = wordcount + 1;
        }
    }
    return (wordcount/2); //we divide wordcount by 2 because it is checking if there is a change before and a change after the int
}

//problem 2
//takes the array and the array’s size as arguments
//finds the place the index of the outlier, fixes the array in place, and returns the old index where the outlier was found. 
//In case there was no outlier, the function should return -1.
long long int fix_sorted_array(double arr[], size_t arr_size)
{
    //we will start off by assuming the array is sorted
    int index = -1;
    if(arr_size == 0)
    {
        return -1;
    }
    for(int i=0; i < (arr_size - 2); i++)
    {
        //the number goes down
        if(arr[i] > arr[i+1] && arr[i] <= arr[i+2])
        {
            //this is a special case
            index= i + 1;
        }
        else if(arr[i] > arr[i+1] && arr[i]>= arr[i+2])
        {
            //this returns the index of the outlier
            index = i;
            break;
        }
    }
    
    //this checks to see if the last element is unsorted
    //since the above loop doesn't check the last element
    if(index == -1)
    {
        if(arr[arr_size-2] > arr[arr_size-1])
        {
            index = arr_size-1;
        }
    }
    
    //this checks from beginning to end
    //swaps the outlier to make the array sorted
    for(int i = 0; i < arr_size - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            double temp = arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    //this checks from end to beginning
    //swaps the outlier to make the array sorted
    for(int i = arr_size - 2; i>=0; i--)
    {
        if(arr[i]>arr[i+1])
        {
            double temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    return index;
}

int main()
{
    char text[]="H ello World ! ";
    unsigned long long wordcount = CountWords(text);
    printf("%llu \n", wordcount);
    
    double arr[5]= {1,2,3,4,5};
    size_t arr_size = 5;
    long long int sorted = fix_sorted_array(arr, arr_size);
    printf("%lld \n", sorted);
    
    return 0;
}
