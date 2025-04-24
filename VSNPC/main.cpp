//
//  main.cpp
//  VSNPC
//
//  Created by Jose Peña on 22/04/25.
//  Para entregar el 29/04/25
//

#include <iostream>
#include <cstdlib>

class Personaje {
public:
    Personaje(std::string nombre) : nombre(nombre) {
        salud = rand() % 51 + 50;
        ataque = rand() % 21 + 10;
        defensa = rand() % 21 + 5;
    }

    void perderVida(int danio) {
        int perderVida = danio - defensa;
        salud -= perderVida;
        if (salud < 0) salud = 0;
        std::cout << nombre << " recibio " << perderVida << " de daño. Salud restante: " << salud << std::endl;
    }

    void mostrarEstadisticas(){
        std::cout << "Nombre: " << nombre << " | Salud: " << salud << " | Ataque: " << ataque << " | Defensa: " << defensa << std::endl;
    }

    int getAtaque() const { return ataque; }
    int getSalud() const { return salud; }
    std::string getNombre() const { return nombre; }

private:
    std::string nombre;
    int salud;
    int ataque;
    int defensa;
};

int main() {
    srand(time(0));

    // Crear personajes
    Personaje jugador("Jugador");
    Personaje npc("NPC");

    std::cout << "=== Estadisticas previas al combate ===" << std::endl;
    jugador.mostrarEstadisticas();
    npc.mostrarEstadisticas();

    std::cout << "\n=== Combate ===" << std::endl;
    
    while ((jugador.getSalud()>=0 || npc.getSalud()>=0)) {
        // Turno del jugador
        std::cout << jugador.getNombre() << " ataca a " << npc.getNombre() << std::endl;
        npc.perderVida(jugador.getAtaque());

        // Turno del NPC
        std::cout << npc.getNombre() << " ataca a " << jugador.getNombre() << std::endl;
        jugador.perderVida(npc.getAtaque());

        std::cout << "\n=== Estadisticas despues del combate ===" << std::endl;
        jugador.mostrarEstadisticas();
        npc.mostrarEstadisticas();
    };

    

    return 0;
}
