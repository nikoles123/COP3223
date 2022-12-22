//Nikole Solano
//NID: 5252251
//Homework 2 "homework2.c"
//COP3223C Section 1, Fall 2020

#include <stdio.h>
#include <ctype.h>
#include <string.h>

//probelm 1
//takes a string and checks if it is a valid decimal representation of an integer number
_Bool IsDecimalInteger(char str[])
{
    _Bool integer = 1; //this is what we will return
    //this is going through the string until it reaches the end
    for(int i = 0; str[i] != '\0'; i++)
    {
        
        //checks to see if # is NOT an integer value
        //integer remains 1 if the #s are all integer values
        if(str[i] < '0' || str[i] > '9')
        {
            integer = 0; //is not a decimal integer
        }
        
        //checks to see if the first char is a negative sign
        //- is only allowed in the first char for it to be considered an integer value
        if(i == 0 && str[i] == '-')
        {
            integer = 1; //is a decimal integer
        }
    }
    
    return integer;
    
}

//problem 2
// checks if the array array is sorted, reverse sorted, unsorted, empty array
//or constant
//returns -1:empty, 1:sorted, 2:reverse sorted, 3:constant, 0:unsorted
char GetSortingOrder(double arr[], size_t arr_size)
{
    int i=0; //this represents the first char in the array
    int j=1; //this represents the 2nd char in the array
    char sortorder; //this is what the function will return
    char prevsortorder; //this checks if the array is unsorted
    
    if(arr_size==0) //empty array
    {
        return -1;
    }
    
    //this is going through the array until it reaches the end
    for(i=0; i<arr_size-1; i++)
    {
        if(i>0)
        {
            //the return values start out being the same
            prevsortorder=sortorder;
        }
        if(arr[i]<arr[j]) //sorted
        {
            //this adds 1 to j to run through the whole array
            j++;
            sortorder = 1;
        }
        else if(arr[i]>arr[j]) //reverse sorted
        {
            j++;
            sortorder = 2;
        }
        else if(arr[i]==arr[j]) //constant
        {
            j++;
            sortorder = 3;
        }
        //this is going to check if the array is unsorted
        //if the return changes throughout the for loop and it is not changing to a constant
        //then its unsorted
        if(i>0 && (prevsortorder != sortorder) && (sortorder != '3' && prevsortorder != '3'))
        {
            sortorder=0;  //unsorted
            //if its unsorted you can break out of the for loop
            break;
        }
    }
    return sortorder; //this is going to output the different values for different types of arrays
}

//problem 3
//takes a text and removes the extra spaces
void RemoveExtraSpaces(char txt[])
{
    //this is how you tell if you should continue deleteing spaces
    _Bool keep_going = 1;
    int length=strlen(txt) - 1;
    
    //while we have keep_going set to 1, which happens where there is more than one space in a row
    //the string is going to continue to shift to the left
    while(keep_going == 1)
    {
        //this is running through the txt string
        for(int i=0; txt[i] != '\0'; i++)
        {
            //this checks if there are two white spaces
            if(isspace(txt[i]) && isspace(txt[i+1]))
            {
                //this will shift the characters
                for(int j = i; txt[j] != '\0'; j++)
                {
                    txt[j] = txt[j+1];
                    
                }
            }
        }
        //this checks if there are still two spaces or if the loop can stop
        keep_going = 0; //there are not two spaces next to each other
        for(int i = 0; txt[i] != '\0'; i++)
        {
            if(isspace(txt[i]) && isspace(txt[i+1]))
            {
                keep_going = 1;
            }
        }
        
    }
    //this checks to see if there is a space at the beginning of the string
    if(isspace(txt[0]))
    {
        //if there is a space, the string gets shifted once
        for(int i = 0; txt[i] != '\0'; i++)
        {
            txt[i] = txt[i+1];
        }
    }
    //this checks to see if there is a space at the end of the string
    int i = strlen(txt) - 1;
    while(isspace(txt[i]))
        i--;
    //this makes the space at the ends become the end of the string
    txt[i + 1] = '\0';
    
    //this will print the modified string
    printf("%s", txt);
}

int main()
{
    char str[6] = "12345";
    _Bool order = IsDecimalInteger(str);
    //this is going to print the return value of IsDecimalInteger
    printf("%d \n", order);

    double arr[4]={1,1,1,1};
    double arr_size=4;
    char c=GetSortingOrder(arr, arr_size);
    printf("%d\n", c);

    char txt[]=" Hello,  Students  ! ";
    RemoveExtraSpaces(txt);

    return 0;
}
