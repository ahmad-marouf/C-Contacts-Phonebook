#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

extern phonebook *contact[100];
extern int count;

int main()
{
    char fname[100];
    char lookup[30];
    int location,cmd,select;
    printf("*******************************\n***Welcome To Your PhoneBook***\n*******************************\n");
    while (1) {
            cmd=0;
            select=0;
            newLine();
            printf(" |(1)Load         |\n");
            printf(" |(2)Search       |\n");
            printf(" |(3)Add          |\n");
            printf(" |(4)Delete       |\n");
            printf(" |(5)Modify       |\n");
            printf(" |(6)Print Sorted |\n");
            printf(" |(7)Save         |\n");
            printf(" |(8)Exit         |\n");
            newLine();
            printf("\tChoose a Command:\t");
            fflush(stdin);
            scanf(" %d",&cmd);
            newLine();
            fflush(stdin);
            newLine();
        switch (cmd)
        {
        case 1:
                printf("Enter Name of File to Load:\n");
                scanf(" %s",fname);
                newLine();
                load_contacts(fname);
                break;

        case 2:
                printf("1.Search Using Last Name\n2.Search Using Multiple Fields\n");
                scanf(" %d",&select);
                int num=0,i;
                int *match;
                if (select==1)
                {
                printf("Enter Last Name of contact\n");
                fflush(stdin);
                scanf(" %s",lookup);
                newLine();
                num=numOfMatch(lookup,2);
                if (num==0) {printf("No matches found\a\n"); newLine(); break;}
                match=malloc(num*4);
                match=search(lookup,2);
                printf("Number of Matches = %d\n",num);
                newLine();
                for (i=0;i<num;i++)
                {
                    printf("Match %d: \n",i+1);
                    printf("First Name: %s\n",contact[*(match+i)]->firstName);
                    printf("Last Name: %s\n",contact[*(match+i)]->lastName);
                    printf("Date of Birth: %02d-%02d-%d\n",contact[*(match+i)]->DOB.day,contact[*(match+i)]->DOB.month,contact[*(match+i)]->DOB.year);
                    printf("Address: %s\n",contact[*(match+i)]->address);
                    printf("Email: %s\n",contact[*(match+i)]->email);
                    printf("Phone Number: %s\n",contact[*(match+i)]->phoneNum);
                    newLine();
                }
                free(match);
                }
                else if (select==2)
                {
                match=malloc(num*4);
                match=multiSearch(&num);
                if (*match==-1)
                {
                    printf("\nContact Not found \n");
                    break;
                }
                newLine();
                for (i=0;i<num;i++)
                {
                    printf("Match %d: \n",i+1);
                    printf("First Name: %s\n",contact[match[i]]->firstName);
                    printf("Last Name: %s\n",contact[match[i]]->lastName);
                    printf("Date of Birth: %02d-%02d-%d\n",contact[match[i]]->DOB.day,contact[match[i]]->DOB.month,contact[match[i]]->DOB.year);
                    printf("Address: %s\n",contact[match[i]]->address);
                    printf("Email: %s\n",contact[match[i]]->email);
                    printf("Phone Number: %s\n",contact[match[i]]->phoneNum);
                    newLine();
                }
                free(match);
                }
                else printf("\nInvalid command\n");
                break;

        case 3:
                add_contact();
                break;

        case 4:
                delete_contact();
                break;

        case 5:
                modContact();
                break;

        case 6:
                if (count==0) {printf("\nNo contacts saved\n"); break;}
                printf("Print the contacts sorted by:\n1.Last Name\n2.Date of Birth\n");
                int select;
                fflush(stdin);
                scanf(" %d",&select);
                if (select==1)
                {
                    sortLname();
                    printAll();
                    break;
                }
                else if (select==2)
                {
                    sortDOB();
                    printAll();
                    break;
                }
                else
                    printf("\nPlease Enter a Valid Option\a\n");
                break;
        case 7:
                printf("Enter Name of File to Save in:\n");
                scanf(" %s",fname);
                save(fname);
                break;
        case 8:
                quit();
                break;
        default:
                printf("Please Enter a Valid Command\a\n");
                newLine();
            break;
    }
        }
    return 0;
}
