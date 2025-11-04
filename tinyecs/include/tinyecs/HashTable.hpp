#pragma once

#include <cstring>
#include "entity.hpp"

#define MAX_NAME 256
#define TABLE_SIZE 10

//Could make this better with a double linked list

struct person {
    char name[MAX_NAME];
    int age;

    struct person *next;
};

// for testing
person* HashTable[TABLE_SIZE];

//init an empty table
void InitHashTable(){
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        HashTable[i] = NULL;

    }
}



unsigned int hash(char* name)
{
    int lenght = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < lenght; i++)
    {
        hash_value += name[i];
        hash_value =(hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

// adds person to the front of the list
bool HashTableInsert(person* p)
{ 
    if(p == NULL) return false;
    //index = p
    int index = hash(p->name);
    //next person = index
    p->next = HashTable[index];
    //put p infront of next person
    HashTable[index] = p;
    return true;
}

person* HashTable_delete(char* name)
{
    int index = hash(name);
    person *tmp = HashTable[index];
    person *prev = NULL;
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        //saving the starting pointer
        prev = tmp;
        //move current pointer to next person
        tmp = tmp->next;
    }
    if(tmp == NULL) return NULL;
    if(prev == NULL){
        //delete head
        HashTable[index] = tmp->next;
    }
    else
    {
        prev->next = tmp->next;
    } 

    //
    return tmp;
}

person *HashTable_lookup(char* name)
{
    int index = hash(name);
    person *tmp = HashTable[index];
   
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        tmp = tmp->next;
    }
    return NULL;
}

void PrintTable()
{

    printf("\nStart\n");
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(HashTable[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t", i);
            person *tmp = HashTable[i];
            while(tmp != NULL){

                printf("%s -", HashTable[i->name]);
                tmp = tmp->next;
            }

        }
    }
    printf("End\n");
}