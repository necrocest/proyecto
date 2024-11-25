#include <iostream>
using namespace std;
// Estructura para las estadísticas de un personaje
struct Estadisticas{
    int vida;
    int ataque;
    int defensa;
}
// Función para mostrar estadísticas
void mostrarEstadisticas(const Estadisticas& jugador, const Estadisticas& enemigo, int nivel){
    cout << "Jugador - Vida: " << jugador.vida << ", Ataque: " << jugador.ataque << ", Defensa: " << jugador.defensa <<", Nivel: "<< nivel <<endl;
    cout << "Enemigo - Vida: " << enemigo.vida << ", Ataque: " << enemigo.ataque << ", Defensa: " << enemigo.defensa <<endl;
}
// Función para calcular el daño
int calcularDanio(int ataque, int defensa){
    int dano = ataque - defensa;
    return (dano > 0) ? dano : 1;// operaor ternario evalualr true o false
}
// Función para subir de nivel
void nivelUp(Estadisticas& jugador, int& nivel){
    nivel++;
    jugador.vida += 20;
    jugador.ataque += 5;
    jugador.defensa += 2;
    cout << "¡Subiste al nivel! " << nivel << "¡Tus estadisticas han mejorado.!"<<endl;
}
