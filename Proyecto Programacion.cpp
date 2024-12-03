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
         << ", Defensa: " << enemigo.defensa <<endl;
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
    cout << "¡Subiste al nivel " << nivel << "! Tus estadisticas han mejorado."<< endl;
}
// Fnción turno del jugador
bool turnoJugador(Estadisticas& jugador, Estadisticas& enemigo) {
    int opcion;
    cout << "Es tu turno. ¿Que deseas hacer?" << endl;
    cout << "1. Atacar (responder una pregunta)" << endl;
    cout << "2. Huir (pierdes 10 de vida)" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    if (opcion == 1) {
        // Definir preguntas y respuestas
        string preguntas[] = {
            "¿Quirn escribio 'Cien años de soledad'?",
            "¿Cual es el planeta mas grande del sistema solar?",
            "¿En que año llegó el hombre a la Luna?",
            "¿En que año termine la Segunda Guerra Mundial?",
            "¿Que significa ONU?",
            "¿Cual es la especie a la que pertenece el hombre?"
        };
        string respuestas[] = {
            "Gabriel Garcia Marquez", "Jupiter", "1969", "1945", 
            "Organizacion de las Naciones Unidas", "Homosapiens"
        };
        // Mostrar opciones de preguntas
        cout<<"\nSelecciona una pregunta: "<<endl;
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << ". " << preguntas[i] << endl;
        }
        cout<<"Opcion: "<<endl;
        int seleccion;
        cin >> seleccion;
        if (seleccion < 1 || seleccion > 6) {
            cout<<"Opcion invalida. Pierdes tu turno."<<endl;
            return true;
        }
        // Hacer la pregunta
        cin.ignore();  // Limpiar buffer
        string respuestaUsuario;
        cout<<preguntas[seleccion - 1] << endl;
        cout<<"Tu respuesta: "<<endl;
        getline(cin, respuestaUsuario);
        // Verificar respuesta
        if (respuestaUsuario == respuestas[seleccion - 1]) {
            int dano = calcularDano(jugador.ataque, enemigo.defensa);
            enemigo.vida -= dano;
            cout<<"¡Respuesta correcta! Infligiste "<<dano<<" de daño. Vida del enemigo: "<< enemigo.vida<<endl;
        } else {
            cout<<"Respuesta incorrecta. Pierdes 10 puntos de vida.\n" << endl;
            jugador.vida -= 10;
        }
    } else if(opcion == 2) {
        jugador.vida -= 10;
        cout<<"Huiste, pero perdiste 10 puntos de vida. Tu vida actual: " << jugador.vida<<endl;
        return false; // Finaliza el turno
    } else {
        cout<<"Opcion invalida. Pierdes tu turno."<<endl;
    }
    return enemigo.vida > 0;
}
// Función turno del enemigo
void turnoEnemigo(Estadisticas& jugador, const Estadisticas& enemigo){
    int dano = calcularDano(enemigo.ataque, jugador.defensa);
    jugador.vida -= dano;
    cout << "El enemigo te ataco e infligio "<<dano<<" de dano. Tu vida actual: " <<jugador.vida<< endl;
}int main() {
    Estadisticas jugador = {65, 25, 20};
    Estadisticas enemigo;
    int nivel = 1;
    string nombre;
    cout << "¡Bienvenido a La Senda del Heroe!" << endl;
    cout << "Eres un heroe que explora un calabozo lleno de enemigos." << endl;
    cout << "Debes alcanzar el nivel 2 derrotando enemigos y tomando decisiones estrategicas." << endl;
    cout << "Introduce el nombre de tu heroe: ";
    cin >> nombre;
    while(nivel<2) {
        enemigo = {50 + (nivel - 1) * 10, 20 + (nivel - 1) * 2, 15 + (nivel - 1)};
        cout<<"Un nuevo enemigo aparece..."<< nombre<<" debes estar preparado"<<endl;
        mostrarEstadisticas(jugador, enemigo, nivel);
        // Batalla
        while (enemigo.vida > 0 && jugador.vida > 0) {
            if (!turnoJugador(jugador, enemigo)) break;
            if (enemigo.vida > 0) turnoEnemigo(jugador, enemigo);
        }
        if (jugador.vida <= 0) {
            cout << "Has caido en batalla. Tu aventura termina aqui. ¡ Valiente intento, " << nombre << "!" << endl;
            return 0;
        }
        if (enemigo.vida <= 0) {
            cout << "¡Derrotaste al enemigo! Subes de nivel." << endl;
            nivelUp(jugador, nivel);
        }
    }
    cout << "¡Felicidades, " << nombre << "!Has alcanzado el nivel 5 y completado La Senda del Heroe." << endl;
    cout << "Con valor y estrategia, venciste a todos los enemigos del calabozo y te convertiste en una leyenda." << endl;
    cout << "¡Gracias por jugar!" << endl;
    return 0;
}
                                                                                                                            
