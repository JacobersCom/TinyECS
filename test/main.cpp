#include <tinyecs/entity.hpp>
#include <iostream>
#include <tinyecs/HashTable.hpp>
int main() {
	
	InitHashTable();
	PrintTable();

	person jane = {"jane" , 100};
	person jack ={"Jack" , 50};
	person genn = {"genn" ,43};

	HashTableInsert(&jane);
	HashTableInsert(&jack);
	HashTableInsert(&genn);
	
	PrintTable();
	
	person *tmp = HashTable_lookup("genn");
	if(tmp == NULL)
	{
		printf("Not Found\n");
	}
	else
	{
		printf("Found Genn\n");
	}
	tmp = HashTable_lookup("Matt");
	if(tmp == NULL)
	{
		printf("Not Found\n");
	}
	else
	{
		printf("Found matt\n");
	}
	
	return 0;
}