#include <iostream>
#include <string>
using namespace std;
struct Estadisticas {
    int vida;
    int ataque;
    int defensa;
};
// Función para mostrar estadísticas
void mostrarEstadisticas(const Estadisticas& jugador, const Estadisticas& enemigo, int nivel) {
    cout << "\nJugador - Vida: " << jugador.vida << ", Ataque: " << jugador.ataque 
         << ", Defensa: " << jugador.defensa << ", Nivel: " << nivel << endl;
    cout << "Enemigo - Vida: " << enemigo.vida << ", Ataque: " << enemigo.ataque 
         << ", Defensa: " << enemigo.defensa << "\n" << endl;
}
// Función para calcular el daño
int calcularDano(int ataque, int defensa) {
    int dano = ataque - defensa;
    return (dano > 0) ? dano : 1;
}
// Función para subir de nivel
void nivelUp(Estadisticas& jugador, int& nivel) {
    nivel++;
    jugador.vida += 20;
    jugador.ataque += 5;
    jugador.defensa += 2;
    cout << "¡Subiste al nivel " << nivel << "! Tus estadísticas han mejorado.\n" << endl;
}
// Fnción turno del jugador
bool turnoJugador(Estadisticas& jugador, Estadisticas& enemigo) {
    int opcion;
    cout << "Es tu turno. ¿Qué deseas hacer?" << endl;
    cout << "1. Atacar (responder una pregunta)" << endl;
    cout << "2. Huir (pierdes 10 de vida)" << endl;
    cout << "Opción: ";
    cin >> opcion;
    if (opcion == 1) {
        // Definir preguntas y respuestas
        string preguntas[] = {
            "¿Quién escribió 'Cien años de soledad'?",
            "¿Cuál es el planeta más grande del sistema solar?",
            "¿En qué año llegó el hombre a la Luna?",
            "¿En qué año terminó la Segunda Guerra Mundial?",
            "¿Qué significa ONU?",
            "¿Cuál es la especie a la que pertenece el hombre?"
        };
        string respuestas[] = {
            "Gabriel Garcia Marquez", "Jupiter", "1969", "1945", 
            "Organizacion de las Naciones Unidas", "Homosapiens"
        };
        // Mostrar opciones de preguntas
        cout << "\nSelecciona una pregunta:" << endl;
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << ". " << preguntas[i] << endl;
        }
        cout << "Opción: ";
        int seleccion;
        cin >> seleccion;
        if (seleccion < 1 || seleccion > 6) {
            cout << "Opción inválida. Pierdes tu turno.\n" << endl;
            return true;
        }
        // Hacer la pregunta
        cin.ignore();  // Limpiar buffer
        string respuestaUsuario;
        cout << preguntas[seleccion - 1] << endl;
        cout << "Tu respuesta: ";
        getline(cin, respuestaUsuario);

        // Verificar respuesta
        if (respuestaUsuario == respuestas[seleccion - 1]) {
            int dano = calcularDano(jugador.ataque, enemigo.defensa);
            enemigo.vida -= dano;
            cout << "¡Respuesta correcta! Infligiste " << dano << " de daño. Vida del enemigo: " << enemigo.vida << "\n" << endl;
        } else {
            cout << "Respuesta incorrecta. Pierdes 10 puntos de vida.\n" << endl;
            jugador.vida -= 10;
        }
    } else if (opcion == 2) {
        jugador.vida -= 10;
        cout << "Huiste, pero perdiste 10 puntos de vida. Tu vida actual: " << jugador.vida << "\n" << endl;
        return false; // Finaliza el turno
    } else {
        cout << "Opción inválida. Pierdes tu turno.\n" << endl;
    }
    return enemigo.vida > 0;
}
// Función turno del enemigo
void turnoEnemigo(Estadisticas& jugador, const Estadisticas& enemigo) {
    int dano = calcularDano(enemigo.ataque, jugador.defensa);
    jugador.vida -= dano;
    cout << "El enemigo te atacó e infligió " << dano << " de daño. Tu vida actual: " << jugador.vida << "\n" << endl;
}
int main() {
    Estadisticas jugador = {100, 25, 20};
    Estadisticas enemigo = {85, 20, 15};
    int nivel = 1;
    string nombre;
    cout << "¡Bienvenido a La Senda del Héroe!" << endl;
    cout << "Eres un héroe que explora un calabozo lleno de enemigos." << endl;
    cout << "Debes alcanzar el nivel 5 derrotando enemigos y tomando decisiones estratégicas." << endl;
    cout << "Introduce el nombre de tu héroe: ";
    cin >> nombre;
    while (nivel < 5) {
        cout<<"Un nuevo enemigo aparece..."<<endl;
        mostrarEstadisticas(jugador, enemigo, nivel);

        // Batalla
        while (enemigo.vida > 0 && jugador.vida > 0) {
            if (!turnoJugador(jugador, enemigo)) break;
            if (enemigo.vida > 0) turnoEnemigo(jugador, enemigo);
        }

        if (jugador.vida <= 0) {
            cout << "Has caído en batalla. Tu aventura termina aquí. ¡Valiente intento, " << nombre << "!\n" << endl;
            return 0;
        }
        if (enemigo.vida <= 0) {
            cout << "¡Derrotaste al enemigo! Subes de nivel.\n" << endl;
            nivelUp(jugador, nivel);
            enemigo = {85 + nivel * 10, 20 + nivel * 5, 15 + nivel * 3}; // Mejorar enemigo
        }
    }
    cout << "¡Felicidades, " << nombre << "! Has alcanzado el nivel 5 y completado La Senda del Héroe." << endl;
    cout << "Con valor y estrategia, venciste a todos los enemigos del calabozo y te convertiste en una leyenda." << endl;
    cout << "¡Gracias por jugar!" << endl;
    return 0;
}
