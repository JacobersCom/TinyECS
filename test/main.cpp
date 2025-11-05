#include <tinyecs/entity.hpp>
#include <iostream>
#include <tinyecs/HashTable.hpp>
struct transform
{
	float pos{1.0};
	float rotate{1.0};
};
struct player
{
	int health = 1;
};
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
	HashTable_delete("genn");
	
	PrintTable();
	printf("player Component ID: %i\n", GetID<player>());
	printf("transform component: %i\n", GetID<transform>());
	return 0;
}