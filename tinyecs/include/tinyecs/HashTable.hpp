#pragma once

#include <cstring>
#include "entity.hpp"

#define MAX_NAME 256
#define TABLE_SIZE 10


struct person {
    char name[MAX_NAME];
    int age;
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

bool HashTableInsert(person* p)
{
    if(p == NULL) return false;
    int index = hash(p->name);
    if(HashTable[index] != NULL)
    {
        return false; 
    }
    HashTable[index] = p;
    return true;
}

 person *HashTable_lookup(char* name)
 {
    int index = hash(name);
    if(HashTable[index] != nullptr &&
    strncmp(HashTable[index]->name, name, TABLE_SIZE) == 0)
    {
        return HashTable[index];
    }
    else
    {
        return NULL;
    }
 }

void PrintTable(){

    printf("\nStart\n");
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(HashTable[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i,\t%s, \t%i\n", i, HashTable[i]->name, HashTable[i]->age);
        }
    }
    printf("End\n");
}