#include "definitions.h"

phonebook *contact[100];
int count = 0;

void newLine()
{
    printf("\n");
}

phonebook *construct(char* firstName,char* lastName,birthDate DOB,char* address,char* email,char* phoneNum)
{
    phonebook *c = malloc(sizeof(phonebook));
    strcpy(c->firstName,firstName);
    strcpy(c->lastName,lastName);
    c->DOB=DOB;
    strcpy(c->address,address);
    strcpy(c->email,email);
    strcpy(c->phoneNum,phoneNum);
    return c;
}

void load_contacts(char* fname)
{
    phonebook con;
    strcat(fname,".txt");
    int valid,duplicate=0;
    FILE *f;
    f = fopen(fname,"r");
    if(f==NULL)
        {
            printf("\nError! File doesn't exist\n");
            return;
        }
    while(!feof(f))
    {
        fscanf(f,"%[^,],",con.lastName);
            valid=validateString(con.lastName);
            if (valid==0)
            {
                printf("\nError loading file, not all contacts were loaded, please make sure the contacts in the file are in the format:\nFirst Name,Last Name,DD-MM-YYYY,Address,Example@domain.com,########### \n");
                newLine();
                return;
            }
        fscanf(f,"%[^,],",con.firstName);
            valid=validateString(con.firstName);
            if (valid==0)
            {
                printf("\nError loading file, not all contacts were loaded, please make sure the contacts in the file are in the format:\nFirst Name,Last Name,DD-MM-YYYY,Address,Example@domain.com,########### \n");
                newLine();
                return;
            }
        fscanf(f,"%d-%d-%d,",&con.DOB.day,&con.DOB.month,&con.DOB.year);
            valid=validateDate(con.DOB.day,con.DOB.month,con.DOB.year);
            if (valid==0)
            {
                printf("\nError loading file, not all contacts were loaded, please make sure the contacts in the file are in the format:\nFirst Name,Last Name,DD-MM-YYYY,Address,Example@domain.com,########### \n");
                newLine();
                return;
            }
        fscanf(f,"%[^,],",con.address);
        fscanf(f,"%[^,],",con.email);
            valid=validateEmail(con.email);
            if (valid==0)
            {
                printf("\nError loading file, not all contacts were loaded, please make sure the contacts in the file are in the format:\nFirst Name,Last Name,DD-MM-YYYY,Address,Example@domain.com,########### \n");
                newLine();
                return;
            }
        fscanf(f,"%s\n",con.phoneNum);
            valid=validatePhoneNum(con.phoneNum);
            if (valid==0)
            {
                printf("\nError loading file, not all contacts were loaded, please make sure the contacts in the file are in the format:\nFirst Name,Last Name,DD-MM-YYYY,Address,Example@domain.com,########### \n");
                newLine();
                return;
            }
            duplicate = check_Duplicate(con.firstName,con.lastName);
            if (duplicate==1) {printf("%s %s already saved in phonebook, Modify contact to change their information\n",con.firstName,con.lastName); continue;}
            else {
                    contact[count] = construct(con.firstName,con.lastName,con.DOB,con.address,con.email,con.phoneNum);
                    count++;
                 }

    }
    printf("File Loaded Successfully! \n");
    fclose(f);
}

void save(char *fname)
{
        strcat(fname,".txt");
        FILE * fptr;
        fptr = fopen(fname,"w");
        if (fptr==NULL) {printf("Couldn't Create File"); return;}
        int i;
        for (i=0;i<count;i++)
        {
            fprintf(fptr,"%s,%s,%02d-%02d-%d,%s,%s,%s\n",contact[i]->lastName,contact[i]->firstName,contact[i]->DOB.day,contact[i]->DOB.month,contact[i]->DOB.year,contact[i]->address,contact[i]->email,contact[i]->phoneNum);
        }
        printf("File Saved Successfully to '%s'\n",fname);
        newLine();
        fclose(fptr);
        return;
}

void quit()
{
    printf("If you exit without saving, all changes will be lost. Continue?\n1.YES\n2.NO\n");
    int confirm;
    fflush(stdin);
    scanf(" %d",&confirm);
    newLine();
    if (confirm==1)
    {
        int i;
        for (i=0;i<count;i++)
            free(contact[i]);
        exit(0);
    }
    else return;
}
