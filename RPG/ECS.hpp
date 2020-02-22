//
//  ECS.hpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/19.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <map>
#include <array>
#include <memory>
#include <bitset>
#include <vector>


class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
constexpr std::size_t maxComponets = 32;
using ComponentArray = std::array<Component*, maxComponets>;
using ComponentBitset = std::bitset<maxComponets>;

class Entity
{
private:
    static std::map<const char*, ComponentID> componentTypeMap;

    ComponentArray componentArray;
    ComponentBitset componentBitset;
    std::vector<std::unique_ptr<Component>> componentPtrVector;
    
    const char* name;
    
public:
    
    template <typename T>
    ComponentID getComponentTypeID()
    {
        return componentTypeMap[typeid(T).name()];
    }
    
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... args)
    {
        T* c = new T(std::forward<TArgs>(args)...);
        // Automate memory management by wrapping in a unique pointer and storing it
        std::unique_ptr<T> uPtr { c };
        c->entity = this;
        componentPtrVector.emplace_back(std::move(uPtr));
        
        ComponentID typeID = getComponentTypeID<T>();
        componentArray[typeID] = c;
        componentBitset[typeID] = true;
        
        return *c;
    }
    
    template <typename T>
    bool hasComponent()
    {
        return componentBitset[getComponentTypeID<T>()];
    }
    
    template <typename T>
    T& getComponent()
    {
        auto ptr = componentArray[getComponentTypeID<T>()];
        return *static_cast<T*>(ptr);
    }
};

class Component
{
public:
    Entity* entity;

};

