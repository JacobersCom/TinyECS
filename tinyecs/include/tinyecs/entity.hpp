#pragma once
//An entity is a genral object used to create new objects with different componenets

//Returns a unquie id for components
int componentCounter = 0;
template<class T>
int GetID(){
    
    static int s_componentId = componentCounter++;
    return s_componentId;
}