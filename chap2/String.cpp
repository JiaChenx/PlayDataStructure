#include<malloc.h>  
#include<stdio.h>  
using namespace std;  
#define TRUE 1  
#define FALSE 0  
#define ERROR -1  
#define MAXSIZE 10  
#define NULL 0  
typedef int Status;  
//every string size is Len+1 ,last unite is "\0".
typedef struct
{  
    char *ch;  
    int length;  
}String;  
//assign a string t 
Status StrAssign(String &t,char *chars)
{  
    int len = 0;  
    char *tmp = chars;  
    while(*tmp != '\0')
    {  
        len++;  
        tmp++;  
    }  
    if(len == 0)
    {  
        //blank string 
        t.ch=(char*)malloc(sizeof(char));  
        *(t.ch) = '\0'; 
        t.length = 0;  
    }  
    else{  
        t.ch = (char*)malloc((len + 1)*sizeof(char)); 
        *(t.ch+len) = '\0';t.length = len;  
        char *tmp = t.ch;  
        while((*chars) != '\0')
        {  
            *tmp++ = *chars++;              
        }  
    }  
    return TRUE;  
  
}  
  
//length
int StrLength(String &s)
{  
    return s.length;  
}  
  
//compare
int StrCompare(String s,String t)
{  
    if(s.length != t.length)  
        return FALSE;  
    while(*s.ch != '\0')
    {  
        if(*s.ch == *t.ch)
        {  
            s.ch++;
            t.ch++;  
            continue;  
        }  
        else  
            return *s.ch - *t.ch;  
    }  
    return 0;  
}  
  
//clear
Status ClearString(String s)
{  
    if(s.ch)  
        free(s.ch);  
        s.ch = NULL;  
    return TRUE;  
}  
  
//connect
Status Connect(String &t,String s1,String s2)
{  
    t.ch = (char*)malloc((s1.length + s2.length + 1)*sizeof(char));  
    t.length = s1.length + s2.length;  
    *(t.ch+t.length) = '\0';  
    char *tmp = t.ch;  
    while(*s1.ch != '\0'){  
        *tmp = *s1.ch;  
        tmp++;  
        s1.ch++;  
    }  
    while(*s2.ch != '\0'){  
        *tmp = *s2.ch;  
        tmp++;  
        s2.ch++;  
    }  
    return TRUE;  
}  
  
//cut out 
String SubString(String s,int pos,int len)
{  
    if(pos<0||pos > len)  
        return s;  
    if(len + pos > s.length)  
        return s;  
    String SubString;  
    SubString.ch = (char*)malloc((len + 1)*sizeof(char));  
    char *tmp = SubString.ch;  
    for(int i = 0; i<len; i++){  
        *(tmp + i) = *(s.ch + pos + i);  
    }  
    *(tmp + len) = '\0';  
    SubString.length = len;  
    return SubString;  
}  
  
//print
void print(String s)
{  
    printf("string length is %d\n",s.length);  
    while(*(s.ch) != '\0')
    {  
        printf("%c ",*(s.ch));  
        s.ch++;  
    }  
      
}  
  
  
int main()
{  
    char *test="i am a boy, my name is xjc!";  
    String s;  
    StrAssign(s,test);  
    print(s);  
    printf("\n");  
    String t;  
    t.ch="i am b boy, my name is xjc!";  
    t.length=27;  
    printf("test compare%d",StrCompare(s,t));  
    printf("\n");  
    printf("test connect\n");  
    String con;  
    Connect(con,s,t);  
    print(con);  
    printf("\n");  
    printf("test cut out string\n");  
    String sub=SubString(s,0,10);  
    print(sub);  
  
} 
