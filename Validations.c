#include "definitions.h"

extern phonebook *contact[100];
extern int count;

int validateString(char *s)
{
    int valid=0,len,i;
    len=strlen(s);
    for (i=0;i<len;i++){
        valid=isalpha(*(s+i));
        if (valid==0) return 0;
    }
    return 1;
}

int validateDate(int day,int month,int year)
{
    if (month==4||month==6||month==9||month==11)
    {
        if (year<1900||year>2019||day>30||day<1) return 0;
    else return 1;
    }
    else if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if (year<1900||year>2019||day>31||day<1) return 0;
    else return 1;
    }
    else if (month==2)
    {
        if (year<1900||year>2019||day>29||day<1) return 0;
    else return 1;
    }
    else return 0;
}

int validateEmail(char *email)
{
    int i,j=0;
    int len=strlen(email);
    char cpy[len+1];
    strcpy(cpy,email);
    for (i=0;i<len;i++)
    if (cpy[i]=='@') j++;
    if (j!=1) return 0;
    if (cpy[len-4]!='.'||cpy[len-3]!='c'||cpy[len-2]!='o'||cpy[len-1]!='m') return 0;
    char *username = strtok(cpy,"@");
    if (strstr(username,".com")!=NULL) return 0;
    char *domain = strtok(NULL,".");
    if (strcmp(domain,"com")==0) return 0;
    char *check = strtok(NULL,".");
    while (strcmp(check,"com")!=0)
        check = strtok(NULL,".");
    return 1;
}

int validatePhoneNum(char *phoneNum)
{
    int valid=0,len,i;
    if (phoneNum[0]!='3'||phoneNum[1]!='0')
    {
        if (phoneNum[0]!='0'||phoneNum[1]!='1')
        return 0;
    }
    len=strlen(phoneNum);
    if (len>11) return 0;
    for (i=0;i<len;i++)
    {
        valid=isdigit(phoneNum[i]);
        if (valid==0) return 0;
    }
    return 1;
}


int check_Duplicate(char *firstName, char *lastName)
{
    int i;
    for (i=0;i<count;i++)
        if (strcasecmp(firstName,contact[i]->firstName)==0&&strcasecmp(lastName,contact[i]->lastName)==0)
            return 1;
    return 0;
}
