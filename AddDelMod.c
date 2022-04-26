#include "definitions.h"

extern phonebook *contact[100];
extern int count;

void add_contact()
{
    phonebook con;
    int valid,duplicate=0;
    fflush(stdin);
    printf("Enter First Name: ");
    scanf(" %s",con.firstName);
    valid=validateString(con.firstName);
    while (valid==0)
    {
        printf("Wrong format (use letters only): ");
        scanf(" %s",con.firstName);
        valid=validateString(con.firstName);
    }
    printf("Enter Last Name: ");
    scanf(" %s",con.lastName);
    valid=validateString(con.lastName);
    while (valid==0)
    {
        printf("Wrong format (use letters only): ");
        fflush(stdin);
        scanf(" %s",con.lastName);
        valid=validateString(con.lastName);
    }
    printf("Enter Date of birth (DD-MM-YYYY): ");
    scanf("%d-%d-%d",&con.DOB.day,&con.DOB.month,&con.DOB.year);
    valid=validateDate(con.DOB.day,con.DOB.month,con.DOB.year);
    while (valid==0)
    {
        printf("Wrong format (use DD-MM-YYYY): ");
        fflush(stdin);
        scanf("%d-%d-%d",&con.DOB.day,&con.DOB.month,&con.DOB.year);
        valid=validateDate(con.DOB.day,con.DOB.month,con.DOB.year);
    }
    printf("Enter Address: ");
    fflush(stdin);
    scanf(" %[^\n]",con.address);
    printf("Enter email: ");
    fflush(stdin);
    scanf(" %s",con.email);
    valid=validateEmail(con.email);
    while (valid==0)
    {
        printf("Wrong format (use example@domain.com): ");
        fflush(stdin);
        scanf(" %s",con.email);
        valid=validateEmail(con.email);
    }
    printf("Enter Phone Number: ");
    fflush(stdin);
    scanf(" %s",con.phoneNum);
    valid=validatePhoneNum(con.phoneNum);
    while (valid==0)
    {
        printf("Wrong format (must start with 01 or 30 and maximum 11 digits): ");
        fflush(stdin);
        scanf(" %s",con.phoneNum);
        valid=validatePhoneNum(con.phoneNum);
    }
    newLine();
    duplicate = check_Duplicate(con.firstName,con.lastName);
    if (duplicate==1) {printf("%s %s is already saved in the phonebook, Modify contact to change their information\n",con.firstName,con.lastName); return;}
    else {
            contact[count] = construct(con.firstName,con.lastName,con.DOB,con.address,con.email,con.phoneNum);
            count++;
         }
}

void delete_contact()
{
    char firstName[15];
    char lastName[15];
    printf("Delete contact: \n");
    newLine();
    printf("Enter the first name: ");
    fflush(stdin);
    scanf(" %s",firstName);
    printf("Enter the Last name: ");
    fflush(stdin);
    scanf(" %s",lastName);
    int location,i,flag=1;
    for (i=0;i<count;i++)
    {
        if (strcasecmp(firstName,contact[i]->firstName)==0&&strcasecmp(lastName,contact[i]->lastName)==0)
        {
            flag=0;
            location=i;
            break;
        }
    }
    if (flag!=0) {printf("\nContact not found\n"); newLine(); return;}
    newLine();
    printf("First Name: %s\n",contact[location]->firstName);
    printf("Last Name: %s\n",contact[location]->lastName);
    printf("Date of Birth: %02d-%02d-%d\n",contact[location]->DOB.day,contact[location]->DOB.month,contact[location]->DOB.year);
    printf("Address: %s\n",contact[location]->address);
    printf("Email: %s\n",contact[location]->email);
    printf("Phone Number: %s\n",contact[location]->phoneNum);
    newLine();
    int confirm;
    printf("Delete this contact?\n1.YES\n2.NO\n");
    scanf(" %d",&confirm);
    newLine();
    if (confirm==1)
        {
         for(i=0;i<count-location-1;i++)
                contact[location+i]=contact[location+i+1];
         count--;
        }
       return;
}

void modContact()
{
    char scanFirst[15];
    char scanLast[15];
    int num,location,i,flag=1,valid=0;
    newLine();
    printf("Enter the Last name: ");
    scanf(" %s",scanLast);
    num=numOfMatch(scanLast,2);
    if (num==0) {printf("No matches found\n"); newLine(); return;}
    int* match=malloc(num*4);
    match=search(scanLast,2);
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
    printf("Select match you want to modify by typing their first name \n");
    printf("Enter the first name: ");
    fflush(stdin);
    scanf(" %s",scanFirst);
    newLine();
    for (i=0;i<num;i++)
    {
        flag=strcasecmp(scanFirst,contact[match[i]]->firstName);
        if (flag==0) location=match[i];
    }
    printf("Enter new data for selected contact \n");
    printf("First Name: ");
    fflush(stdin);
    scanf(" %s",contact[location]->firstName);
        valid=validateString(contact[location]->firstName);
        while (valid==0)
        {
            printf("Wrong format (use letters only): ");
            fflush(stdin);
            scanf(" %s",contact[location]->firstName);
            valid=validateString(contact[location]->firstName);
        }
    printf("Last Name: ");
    fflush(stdin);
    scanf(" %s",contact[location]->lastName);
        valid=validateString(contact[location]->lastName);
        while (valid==0)
        {
            printf("Wrong format (use letters only): ");
            fflush(stdin);
            scanf(" %s",contact[location]->lastName);
            valid=validateString(contact[location]->lastName);
        }
    printf("Date of Birth (DD-MM-YYYY): ");
    fflush(stdin);
    scanf(" %d-%d-%d",&contact[location]->DOB.day,&contact[location]->DOB.month,&contact[location]->DOB.year);
        valid=validateDate(contact[location]->DOB.day,contact[location]->DOB.month,contact[location]->DOB.year);
        while (valid==0)
        {
            printf("Wrong format (use DD-MM-YYYY): ");
            fflush(stdin);
            scanf(" %d-%d-%d",&contact[location]->DOB.day,&contact[location]->DOB.month,&contact[location]->DOB.year);
            valid=validateDate(contact[location]->DOB.day,contact[location]->DOB.month,contact[location]->DOB.year);
        }
    printf("Address: ");
    fflush(stdin);
    scanf(" %[^\n]",contact[location]->address);
    printf("Email: ");
    fflush(stdin);
    scanf(" %s",contact[location]->email);
        valid=validateEmail(contact[location]->email);
        while (valid==0)
        {
            printf("Wrong format (please use example@domain.com): ");
            fflush(stdin);
            scanf(" %s",contact[location]->email);
            valid=validateEmail(contact[location]->email);
        }
    printf("Phone Number: ");
    fflush(stdin);
    scanf(" %s",contact[location]->phoneNum);
        valid=validatePhoneNum(contact[location]->phoneNum);
        while (valid==0)
        {
            printf("Wrong format (must start with 01 or 30 and maximum 11 digits): ");
            fflush(stdin);
            scanf(" %s",contact[location]->phoneNum);
            valid=validatePhoneNum(contact[location]->phoneNum);
        }
    newLine();
    printf("New contact data successfully entered \n");
    newLine();
    free(match);
    return;
}
