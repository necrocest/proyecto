#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Estructura para las estadísticas de un personaje
struct Estadisticas {
    int vida;
    int ataque;
    int defensa;
};
// Prototipos de funciones
// Función para mostrar estadísticas
void mostrarEstadisticas(const Estadisticas& jugador, const Estadisticas& enemigo, int nivel);
void mostrarEstadisticas(const Estadisticas& jugador, const Estadisticas& enemigo, int nivel) {
    cout << "Jugador - Vida: " << jugador.vida << ", Ataque: " << jugador.ataque << ", Defensa: " << jugador.defensa << ", Nivel: " << nivel << "\n";
    cout << "Enemigo - Vida: " << enemigo.vida << ", Ataque: " << enemigo.ataque << ", Defensa: " << enemigo.defensa << "\n";
}
// Función para calcular el daño
int calcularDanio(int ataque, int defensa);
int calcularDanio(int ataque, int defensa) {
    int danio = ataque - defensa;
    return (danio > 0) ? danio : 1;  // Siempre hace al menos 1 de daño
}
// Función para subir de nivel
void nivelUp(Estadisticas& jugador, int& nivel);
void nivelUp(Estadisticas& jugador, int& nivel) {
    nivel++;
    jugador.vida += 20;
    jugador.ataque += 5;
    jugador.defensa += 2;
    cout << "¡Subiste al nivel! " << nivel << "¡Tus estadísticas han mejorado.!"<<endl;
}
