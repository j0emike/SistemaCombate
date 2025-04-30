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
        int danioReal = danio - defensa;
        if (danioReal < 0)
            danioReal = 0;
        salud -= danioReal;
        if (salud < 0)
            salud = 0;
        std::cout << nombre << " perdio " << danioReal << " de salud. Salud restante: " << salud << std::endl;

    }

    void mostrarEstadisticas() {
        std::cout << "Nombre: " << nombre
                  << " | Salud: " << salud
                  << " | Ataque: " << ataque
                  << " | Defensa: " << defensa << std::endl;
    }

    int getAtaque(){ 
        return ataque;
    }
    int getSalud(){
        return salud;
    }
    std::string getNombre(){
        return nombre;
    }

private:
    std::string nombre;
    int salud;
    int ataque;
    int defensa;
};

void turno(Personaje& atacante, Personaje& defensor) {
    std::cout << atacante.getNombre() << " ataca a " << defensor.getNombre() << std::endl;
    defensor.perderVida(atacante.getAtaque());
}

int main() {
    srand(time(0));

    // Crear personajes
    Personaje jugador("Jugador");
    Personaje npc("NPC");

    std::cout << "=== Estadisticas previas al combate ===" << std::endl;
    jugador.mostrarEstadisticas();
    npc.mostrarEstadisticas();

    std::cout << "\n=== Combate ===" << std::endl;
    while (jugador.getSalud() > 0 && npc.getSalud() > 0) {
        while (jugador.getSalud() > 0 && npc.getSalud() > 0) {

            turno(jugador, npc);
            if (npc.getSalud() <= 0) break;

            turno(npc, jugador);
            if (jugador.getSalud() <= 0) break;

            std::cout << "\n=== Estadísticas después del turno ===" << std::endl;
            jugador.mostrarEstadisticas();
            npc.mostrarEstadisticas();
            system("pause");
            system("cls");
        }
    }
    
    std::cout << "\n=== Fin del combate ===" << std::endl;
    if (jugador.getSalud() > 0)
        std::cout << "¡" << jugador.getNombre() << " ha ganado!" << std::endl;
    else if (npc.getSalud() > 0)
        std::cout << "¡" << npc.getNombre() << " ha ganado!" << std::endl;
    return 0;
}