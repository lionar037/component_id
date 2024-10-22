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

#define ENTITY_ID_ARMS 1
#define ENTITY_ID_ENEMY 0

namespace COMPONENT {

    using EntityID_t = std::size_t;

    struct Component_t {
        explicit Component_t(EntityID_t eid) : entityID(eid)//, ComponentID(++instanceID) 
        {}

        EntityID_t entityID{0};  // ID de la entidad
        std::size_t ComponentID{++instanceID}; // ID del componente

    private:
        inline static std::size_t instanceID{0}; // ID para las instancias
    };

    struct PositionComponent : public Component_t {
        PositionComponent(EntityID_t eid) : Component_t(eid) {} // Constructor que acepta EntityID

        std::size_t getComponentID() { return this->ComponentID; };
    };

    struct VelocityComponent : public Component_t {
        VelocityComponent(EntityID_t eid) : Component_t(eid) {} // Constructor que acepta EntityID

        std::size_t getComponentID() { return this->ComponentID; };
    };



}//end Component

