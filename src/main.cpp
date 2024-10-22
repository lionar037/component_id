/////////////////////////////////////////////////////////////////////////////////
//
//
//              main.cpp
//
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <component.hpp>



int main() {
    std::vector<COMPONENT::PositionComponent> positionComponents;
    std::vector<COMPONENT::VelocityComponent> velocityComponents;

    // Inicializar la semilla para números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Crear 10 PositionComponent
    for (int a = 0; a < 10; ++a) {
        positionComponents.emplace_back(ENTITY_ID_ENEMY); // Cambiar rand(255) a rand() % 256
    }

    // Crear 10 VelocityComponent
    for (int a = 0; a < 10; ++a) {
        velocityComponents.emplace_back(ENTITY_ID_ARMS); // Cambiar rand(255) a rand() % 256
    }

    // Mostrar los IDs de PositionComponent
    std::cout << "PositionComponent IDs:" << std::endl;
    for (const auto& enemy : positionComponents) {
                std::cout 
                    << " Entity ID: " << enemy.entityID 
                    << " Instance ID: " << enemy.ComponentID           
                    << std::endl;
    }

    // Mostrar los IDs de VelocityComponent
    std::cout << "\nVelocityComponent IDs:" << std::endl;
    for (const auto& arm : velocityComponents) {
        std::cout 
                    << " Entity ID: " << arm.entityID 
                    << " Instance ID: " << arm.ComponentID           
                    << std::endl;
    }

    return 0;
}
