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
        salud = rand() % 51 + 50;   // 50 - 100
        ataque = rand() % 21 + 10;  // 10 - 30
        defensa = rand() % 21 + 5;  // 5 - 25
    }

    void perderVida(int danio) {
        int perderVida = danio - defensa;
        if (perderVida < 0)
        perderVida = 0;
        salud -= perderVida;
        if (salud < 0) salud = 0;
        std::cout << nombre << " recibió " << danioReal << " de daño. Salud restante: " << salud << std::endl;
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

    std::cout << "=== Estadísticas previas al combate ===" << std::endl;
    jugador.mostrarEstadisticas();
    npc.mostrarEstadisticas();

    std::cout << "\n=== Combate ===" << std::endl;

    // Turno del jugador
    std::cout << jugador.getNombre() << " ataca a " << npc.getNombre() << std::endl;
    npc.recibirDanio(jugador.getAtaque());

    // Turno del NPC
    std::cout << npc.getNombre() << " ataca a " << jugador.getNombre() << std::endl;
    jugador.recibirDanio(npc.getAtaque());

    std::cout << "\n=== Estadísticas después del combate ===" << std::endl;
    jugador.mostrarEstadisticas();
    npc.mostrarEstadisticas();

    return 0;
}
