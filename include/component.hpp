/////////////////////////////////////////////////////////////////////////////////
//
//
//              component.hpp
//
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

namespace COMPONENT{

using EntityID_t = std::size_t;

struct Component_t
{
    explicit Component_t(EntityID_t eid) : entityID(eid) {}

    EntityID_t entityID;  // ID de la entidad
    std::size_t ComponentID; // ID del componente
};

template <typename Derived>
struct UniqueComponent_t : public Component_t
{
    explicit UniqueComponent_t(EntityID_t eid) : Component_t(eid) 
    {
        ComponentID = instanceID++; // Asigna el ID único para cada instancia
    }

    static std::size_t classID; // ID de clase único para el tipo derivado
    static std::size_t instanceID; // ID para las instancias
};

// Declaraciones de las clases
struct PositionComponent;
struct VelocityComponent;

// Definición de IDs de clase y contadores de instancias
template <> std::size_t UniqueComponent_t<PositionComponent>::classID = 0;
template <> std::size_t UniqueComponent_t<PositionComponent>::instanceID = 0;

template <> std::size_t UniqueComponent_t<VelocityComponent>::classID = 1;
template <> std::size_t UniqueComponent_t<VelocityComponent>::instanceID = 0;

struct PositionComponent : public UniqueComponent_t<PositionComponent>
{
    explicit PositionComponent(EntityID_t eid) : UniqueComponent_t(eid) {}
};

struct VelocityComponent : public UniqueComponent_t<VelocityComponent>
{
    explicit VelocityComponent(EntityID_t eid) : UniqueComponent_t(eid) {}
};



}//end Component

