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
	
	return 0;
}