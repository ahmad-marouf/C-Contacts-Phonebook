#include "definitions.h"

extern phonebook *contact[100];
extern int count;

int numOfMatchDOB(int day,int month,int year)
{
    int i,j=0;
    for (i=0;i<count;i++)
    {
        if (day==contact[i]->DOB.day&&month==contact[i]->DOB.month&&year==contact[i]->DOB.year)
        j++;
    }
    return j;
}

int *searchDOB(int day,int month,int year)
{
    int i,k=0,num;
    int *match;
    num=numOfMatchDOB(day,month,year);
    match=malloc(num*4);
    for (i=0;i<count;i++)
    {
        if (day==contact[i]->DOB.day&&month==contact[i]->DOB.month&&year==contact[i]->DOB.year)
        {
            match[k]=i;
            k++;
        }
    }
    return match;
}


int numOfMatch(char *key,int field)
{
    int i,j=0,flag=1;
    if (field==1)
    {
    for (i=0;i<count;i++)
    {
        flag=strcasecmp(key,contact[i]->firstName);
        if (flag==0) (j)++;
    }
    }
    if (field==2)
    {
    for (i=0;i<count;i++)
    {
        flag=strcasecmp(key,contact[i]->lastName);
        if (flag==0) (j)++;
    }
    }
    if (field==4)
    {
    for (i=0;i<count;i++)
    {
        flag=strcasecmp(key,contact[i]->address);
        if (flag==0) (j)++;
    }
    }
    if (field==5)
    {
    for (i=0;i<count;i++)
    {
        flag=strcasecmp(key,contact[i]->email);
        if (flag==0) (j)++;
    }
    }
    if (field==6)
    {
    for (i=0;i<count;i++)
    {
        flag=strcasecmp(key,contact[i]->phoneNum);
        if (flag==0) (j)++;
    }
    }
    return j;
}


int *search(char *key,int field)
{
    int i,k=0,num;
    int *match;
    if (field==1)
    {
    num=numOfMatch(key,1);
    match=malloc(num*4);
    for (i=0;i<count;i++)
    {
        if (strcasecmp(key,contact[i]->firstName)==0)
        {
            match[k]=i;
            k++;
        }
    }
    }
    if (field==2)
    {
    num=numOfMatch(key,2);
    match=malloc(num*4);
    for (i=0;i<count;i++)
    {
        if (strcasecmp(key,contact[i]->lastName)==0)
        {
            match[k]=i;
            k++;
        }
    }
    }
    if (field==4)
    {
    num=numOfMatch(key,4);
    match=malloc(num*4);
    for (i=0;i<count;i++)
    {
        if (strcasecmp(key,contact[i]->address)==0)
        {
            match[k]=i;
            k++;
        }
    }
    }
    if (field==5)
    {
    num=numOfMatch(key,5);
    match=malloc(num*4);
    for (i=0;i<count;i++)
    {
        if (strcasecmp(key,contact[i]->email)==0)
        {
            match[k]=i;
            k++;
        }
    }
    }
    if (field==6)
    {
    num=numOfMatch(key,6);
    match=malloc(num*4);
    for (i=0;i<count;i++)
    {
        if (strcasecmp(key,contact[i]->phoneNum)==0)
        {
            match[k]=i;
            k++;
        }
    }
    }
    return match;
}

int *multiSearch(int *k)
{
    phonebook con;
    printf("\nEnter the data used for search,enter '-' in unused fields: \n");
    newLine();
    printf("First Name: ");
    scanf(" %s",con.firstName);
    printf("Last name: ");
    scanf(" %s",con.lastName);
    printf("Enter Date of birth (DD-MM-YYYY): ");
    scanf("%d-%d-%d",&con.DOB.day,&con.DOB.month,&con.DOB.year);
    printf("Address: ");
    fflush(stdin);
    scanf(" %[^\n]",con.address);
    printf("Email: ");
    scanf(" %s",con.email);
    printf("Phone Number: ");
    scanf(" %s",con.phoneNum);
    int i,j;
    int *abort=malloc(sizeof(int));
    *abort=-1;
    int num1=0,num2=0,num3=0,num4=0,num5=0,num6=0;
    int used1=0,used2=0,used3=0,used4=0,used5=0,used6=0;
    int *match1=0,*match2=0,*match3=0,*match4=0,*match5=0,*match6=0;
    if (strcasecmp(con.firstName,"-")!=0)
    {
        used1=1;
        num1=numOfMatch(con.firstName,1);
        if (num1==0) return abort;
        match1=malloc(num1*4);
        match1=search(con.firstName,1);
    }
    if (strcasecmp(con.lastName,"-")!=0)
    {
        used2=1;
        num2=numOfMatch(con.lastName,2);
        if (num2==0) return abort;
        match2=malloc(num2*4);
        match2=search(con.lastName,2);
    }
    if (validateDate(con.DOB.day,con.DOB.month,con.DOB.year))
    {
        used3=1;
        num3=numOfMatchDOB(con.DOB.day,con.DOB.month,con.DOB.year);
        if (num3==0) return abort;
        match3=malloc(num3*4);
        match3=searchDOB(con.DOB.day,con.DOB.month,con.DOB.year);
    }
    if (strcasecmp(con.address,"-")!=0)
    {
        used4=1;
        num4=numOfMatch(con.address,4);
        if (num4==0) return abort;
        match4=malloc(num4*4);
        match4=search(con.address,4);
    }
    if (strcasecmp(con.email,"-")!=0)
    {
        used5=1;
        num5=numOfMatch(con.email,5);
        if (num5==0) return abort;
        match5=malloc(num5*4);
        match5=search(con.email,5);
    }
    if (strcasecmp(con.phoneNum,"-")!=0)
    {
        used6=1;
        num6=numOfMatch(con.phoneNum,6);
        if (num6==0) return abort;
        match6=malloc(num6*4);
        match6=search(con.phoneNum,6);
    }
    int total=num1+num2+num3+num4+num5+num6;
    int *matchAll=malloc((total)*4);
    memcpy(matchAll,match1,num1*4);
    memcpy(matchAll+num1,match2,num2*4);
    memcpy(matchAll+num1+num2,match3,num3*4);
    memcpy(matchAll+num1+num2+num3,match4,num4*4);
    memcpy(matchAll+num1+num2+num3+num4,match5,num5*4);
    memcpy(matchAll+num1+num2+num3+num4+num5,match6,num6*4);
    if (total==1) return matchAll;
    int *location,l=0;
    for (i=0;i<total;i++)
    {
        for (j=i+1;j<total;j++)
            if (matchAll[i]==matchAll[j])
        {
            (*k)++;
        }
    }
    location=malloc((*k)*4);
    for (i=0;i<total;i++)
    {
        for (j=i+1;j<total;j++)
            if (matchAll[i]==matchAll[j])
        {
            location[l]=matchAll[i];
            l++;

        }
    }
    if (used1+used2+used3+used4+used5+used6==1&&total!=0)
    {
        *k=total;
        return matchAll;
    }
    free(matchAll);
    if (used1==1) free(match1); if (used2==1) free(match2); if (used3==1) free(match3); if (used4==1) free(match4); if (used5==1) free(match5); if (used6==1) free(match6);
    return location;
}
