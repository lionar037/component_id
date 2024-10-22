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
        positionComponents.emplace_back(rand() % 256); // Cambiar rand(255) a rand() % 256
    }

    // Crear 10 VelocityComponent
    for (int a = 0; a < 10; ++a) {
        velocityComponents.emplace_back(rand() % 256); // Cambiar rand(255) a rand() % 256
    }

    // Mostrar los IDs de PositionComponent
    std::cout << "PositionComponent IDs:" << std::endl;
    for (const auto& pc : positionComponents) {
        std::cout << "Class ID: " << PositionComponent::classID 
                  << ", Instance ID: " << pc.ComponentID 
                  << ", Entity ID: " << pc.entityID << std::endl;
    }

    // Mostrar los IDs de VelocityComponent
    std::cout << "VelocityComponent IDs:" << std::endl;
    for (const auto& vc : velocityComponents) {
        std::cout << "Class ID: " << VelocityComponent::classID 
                  << ", Instance ID: " << vc.ComponentID 
                  << ", Entity ID: " << vc.entityID << std::endl;
    }

    return 0;
}
