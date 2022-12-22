//Nikole Solano
//NID: 5252251
//Homework 4 "homework4.c"
//COP3223C Section 1, Fall 2020

#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 1000

//problem 1
//multiplies two decimal string representations of non-negative integers 
//parameters cx and cy, which are string decimal representations 
//returns their product as a string decimal representation

//Uses the function we made in class which adds two pointers together
_Bool SumCIntegers(char*cx, char*cy, char*res)
{
    size_t len_cx = strlen(cx), len_cy = strlen(cy);
    unsigned char cur_sum = 0, cur_remainder = 0;
    long long int i = 0;
    if(len_cx < len_cy)
    {
        for(i = len_cx; i >= 0; i--)
            *(cx + i + (len_cy-len_cx)) = *(cx+i);
        for(i = 0; i < (len_cy - len_cx); i++)
            *(cx+i)='0';
    }
    else if(len_cy < len_cx)
    {
        for(i = len_cy; i >= 0; i--)
            *(cy + i + (len_cx - len_cy)) = *(cy+i);
        for(i = 0; i < len_cx - len_cy; i++)
            *(cy+i) = '0';
    }
    len_cx = (len_cx > len_cy ? len_cx : len_cy);
    if(len_cx == 0)
    {
        *res = '\0';
        return 1;
    }
    *(res+len_cx) = '\0';
    for(i = len_cx - 1; i >= 0; i--)
    {
        if(*(cx+i) < '0'|| *(cx+i) > '9'|| *(cy+i) < '0'|| *(cy+i) > '9')
        {
            *res = '\0';
            return 0; //Error: at least one of the summands is not a non-negative integer
        }
        cur_sum = *(cx+i) + *(cy+i) - 2 * '0' + cur_remainder;
        cur_remainder = cur_sum/10;
        *(res+i) = cur_sum - (cur_remainder * 10) + '0';
    } //for i
    if(cur_remainder == 1)
    {
        if(len_cx == MAX_STR_LEN)//overflow
        {
            *res = '\0';
            return 0;
        }
        for(i = len_cx; i >= 0; i--)
            *(res+i+1) = *(res+i);
        *res = '1';
  }
    
    return 1;
}

_Bool MultiplyCIntegers(char* cx, char* cy, char* res)
{
    //checks to see if cy or cx are NULL strings
    if(MAX_STR_LEN > 1000 || cy == NULL || cx == NULL)
        //it will exit the function, you cannot mulitply with NULL
        return 0;
    
    //im going to keep track of how many times we add the strings together by using cmpstr and a counter
    //each time the counter != the smaller string, the SumCIntegers function runs again and the counter is incremented by 1
    char count[MAX_STR_LEN] = "0";
    char count2[MAX_STR_LEN] = "1";
    
    strcpy(res, "0");
    
    //checks to see which of the two strings is smaller which will make the program a bit more efficient
    if(strlen(cx) < strlen(cy))
    {
        //strcmp will output 0 if the strings are the same
        //so while they are not the same the SumCIntegers fucntion is called over and over again until the counter = the smaller length
        int result = strcmp(count,cx);
        while(result != 0)
        {
            SumCIntegers(cy,res,res);
            SumCIntegers(count,count2,count);
            result = strcmp(count,cx);
        }
    }
    else
    {
        int result = strcmp(count,cy);
        while(result != 0)
        {
            SumCIntegers(cx,res,res);
            SumCIntegers(count,count2,count);
            result = strcmp(count,cy);
        }
    }
    return 1;
}

//problem 2
// takes unsigned short n as parameter, and returns the decimal representation of n! as the res parameter
void GetFactorial(unsigned short n, char* res)
{
    char temp[1000] = "1";
    strcpy(res, "1");
    char one[1000] = "1";
    char counting_string[1000] = "1";
    int i = 0;
    
    //this is going to do 1*2*3....*n
    while(i < n)
    {
        //multiplies res * counting string and stores it in temp
        MultiplyCIntegers(res,counting_string, temp);
        //copies result from MulitplyCIntegers and stores it in res
        strcpy(res, temp);
        //increments counting string by 1
        SumCIntegers(counting_string, one, counting_string);
        //increments i by 1
        i++;
    }
}

int main(void)
{
    char cx[MAX_STR_LEN] = "1234";
    char cy[MAX_STR_LEN] = "5678";
    char res[MAX_STR_LEN];
    MultiplyCIntegers(cx,cy,res);
    printf("%s\n",res);
    unsigned short n = 10;
    GetFactorial(n, res);
    printf("%s\n",res);
    return 0;
}
