#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    int day,month,year;
}birthDate;

typedef struct {
    char firstName[30];
    char lastName[30];
    birthDate DOB;
    char address[100];
    char email[100];
    char phoneNum[20];
}phonebook;


phonebook *construct(char* firstName,char* lastName,birthDate DOB,char* address,char* email,char* phoneNum);
void newLine();
int validateString(char *s);
int validateDate(int day,int month,int year);
int validateEmail(char *email);
int validatePhoneNum(char *phoneNum);
int check_Duplicate(char *firstName, char *lastName);
void load_contacts(char* fname);
int numOfMatch(char *key,int field);
int numOfMatchDOB(int day,int month,int year);
int *search(char *key,int field);
int *searchDOB(int day,int month,int year);
int *multiSearch();
void add_contact();
void delete_contact();
void modContact();
int nameComparator(const void* p,const void *q);
int yearComparator(const void* p,const void *q);
void sortDOB();
void sortLname();
void printAll();
void save(char *fname);
void quit();


#endif // DEFINITIONS_H_INCLUDED
