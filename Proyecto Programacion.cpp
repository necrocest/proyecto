#include <iostream>
using namespace std;
// Estructura para las estadísticas de un personaje
struct Estadisticas {
    int vida;
    int ataque;
    int defensa;
}
// Prototipos de funciones
void mostrarEstadisticas(const Estadisticas& jugador, const Estadisticas& enemigo, int nivel);
int calcularDanio(int ataque, int defensa);
bool turnoJugador(Estadisticas& enemigo, Estadisticas& jugador);
bool turnoEnemigo(Estadisticas& jugador, Estadisticas& enemigo);
void nivelUp(Estadisticas& jugador, int& nivel);

int main() {
    // Inicialización de datos
    Estadisticas jugador = {100, 15, 5};  // Vida, ataque, defensa
    Estadisticas enemigo = {80, 10, 3};
    int nivel = 1;
