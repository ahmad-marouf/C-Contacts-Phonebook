#include "definitions.h"

extern phonebook *contact[100];
extern int count;

int nameComparator(const void* p,const void *q)
{
    phonebook *pp = *(phonebook**)p, *pq=*(phonebook**)q;
    if (stricmp(pp->lastName,pq->lastName)!=0)
    return stricmp(pp->lastName,pq->lastName);
    else return stricmp(pp->firstName,pq->firstName);
}

int yearComparator(const void* p,const void *q)
{
    phonebook *pp = *(phonebook**)p, *pq=*(phonebook**)q;
    if (pp->DOB.year!=pq->DOB.year)
        return (pp->DOB.year-pq->DOB.year);
    else if (pp->DOB.month!=pq->DOB.month)
        return (pp->DOB.month-pq->DOB.month);
    else
        return (pp->DOB.day-pq->DOB.day);
}

void sortDOB()
{
    printf("Contacts sorted by Date of Birth: \n");
    qsort(contact, count, sizeof(phonebook*),yearComparator);
}

void sortLname()
{
    printf("Contacts sorted by Last Name: \n");
    qsort(contact, count, sizeof(phonebook*),nameComparator);
}

void printAll()
{
    int i;
    for (i=0;i<count;i++)
    {
        newLine();
        printf("First Name: %-30s\n",contact[i]->firstName);
        printf("Last Name: %-30s\n",contact[i]->lastName);
        printf("Date of Birth: %02d-%02d-%d\n",contact[i]->DOB.day,contact[i]->DOB.month,contact[i]->DOB.year);
        printf("Address: %-30s\n",contact[i]->address);
        printf("Email: %-30s\n",contact[i]->email);
        printf("Phone Number: %-30s\n",contact[i]->phoneNum);
        newLine();
    }
    return;
}
