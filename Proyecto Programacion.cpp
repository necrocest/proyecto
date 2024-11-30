#include <iostream>
#include <string>
using namespace std;
struct Estadisticas{
    int vida;
    int ataque;
    int defensa;
};
// Función para mostrar estadísticas
void mostrarEstadisticas(const Estadisticas& jugador, const Estadisticas& enemigo, int nivel) {
    cout<<"Jugador - Vida: "<<jugador.vida<<"Ataque: "<<jugador.ataque 
         <<"Defensa: "<<jugador.defensa<<"Nivel: "<<nivel << endl;
    cout<<"Enemigo - Vida: "<<enemigo.vida<<"Ataque: "<<enemigo.ataque 
         <<"Defensa: "<<enemigo.defensa<<endl;
}
// Función para calcular el daño
int calcularDano(int ataque, int defensa){
    int dano = ataque - defensa;
    return (dano > 0) ? dano : 1;
}
// Función para subir de nivel
void nivelUp(Estadisticas& jugador, int& nivel){
    nivel++;
    jugador.vida += 20;
    jugador.ataque += 5;
    jugador.defensa += 2;
    cout<<"¡Subiste al nivel "<<nivel<<"! Tus estadísticas han mejorado."<<endl;
}
// Función turno del jugador
bool turnoJugador(Estadisticas& jugador, Estadisticas& enemigo) {
    int opcion;
    cout<<"Es tu turno. ¿Qué deseas hacer?"<<endl;
    cout<<"1. Atacar (responder una pregunta)"<<endl;
    cout<<"2. Huir (pierdes 10 de vida)"<<endl;
    cout<<"Opción: "<<endl;
    cin>>opcion;
    if (opcion == 1) {
        // Definir preguntas y respuestas
        string pregunta1 = "¿Quién escribió 'Cien años de soledad'?";
        string respuesta1 = "Gabriel Garcia Marquez";
        string pregunta2 = "¿Cuál es el planeta más grande del sistema solar?";
        string respuesta2 = "Jupiter";
        string pregunta3 = "¿En qué año llegó el hombre a la Luna?";
        string respuesta3 = "1969";
        string pregunta4 = "¿En qué año termino la segunda Guerra Mundial?";
        string respuesta4 = "1945";
        string pregunta5 = "¿Que significa ONU?";
        string respuesta5 = "Organizacion Las Naciones unidas";
        string pregunta6 = "¿cual es la especie a la que pertenece el hombre?";
        string respuesta6 = "Homosapiens";
        // Mostrar opciones de preguntas
        cout<<"Selecciona una pregunta:" << endl;
        cout<<"1. "<<pregunta1<<endl;
        cout<<"2. "<<pregunta2<<endl;
        cout<<"3. "<<pregunta3<<endl;
        cout<<"4. "<<pregunta4<<endl;
        cout<<"5. "<<pregunta5<<endl;
        cout<<"6. "<<pregunta6<<endl;
        cout<<"Opción: "<<endl;
        int seleccion;
        cin>>seleccion;
        // Determinar la pregunta seleccionada
        string preguntaSeleccionada, respuestaCorrecta;
        if (seleccion == 1) {
            preguntaSeleccionada = pregunta1;
            respuestaCorrecta = respuesta1;
        } else if (seleccion == 2) {
            preguntaSeleccionada = pregunta2;
            respuestaCorrecta = respuesta2;
        } else if (seleccion == 3) {
            preguntaSeleccionada = pregunta3;
            respuestaCorrecta = respuesta3;
        } else if (seleccion == 4) {
            preguntaSeleccionada = pregunta4;
            respuestaCorrecta = respuesta4;
             } else if (seleccion == 5) {
            preguntaSeleccionada = pregunta5;
            respuestaCorrecta = respuesta5;
             } else if (seleccion == 6) {
            preguntaSeleccionada = pregunta6;
            respuestaCorrecta = respuesta6;
        } else {
            cout<<"Opción inválida. Pierdes tu turno."<<endl;
            return true;
        }
        // Hacer la pregunta
        cout<<"\n"<<preguntaSeleccionada<<endl;
        string respuestaUsuario;
        // Verificar respuesta
        if(respuestaUsuario == respuestaCorrecta){
            int dano = calcularDano(jugador.ataque, enemigo.defensa);
            enemigo.vida -= dano;
            cout<<"¡Respuesta correcta! Infligiste "<<dano<<" de daño. Vida del enemigo: "<<enemigo.vida<<endl;
        } else {
            cout<<"Respuesta incorrecta. Pierdes 10 puntos de vida."<<endl;
            jugador.vida -= 10;
        }
    }else if(opcion == 2){
        jugador.vida -= 10;
        cout<<"Huiste, pero perdiste 10 puntos de vida. Tu vida actual: "<<jugador.vida<<endl;
        return false; // Finaliza el turno
    }else{
        cout<<"Opción inválida. Pierdes tu turno."<<endl;
    }
    return enemigo.vida > 0;
}
// Función turno del enemigo
void turnoEnemigo(Estadisticas& jugador, const Estadisticas& enemigo) {
    int dano = calcularDano(enemigo.ataque, jugador.defensa);
    jugador.vida -= dano;
    cout<< "El enemigo te atacó e infligió " <<dano<<" de daño. Tu vida actual: "<<jugador.vida<<endl;
}
int main() {
    Estadisticas jugador = {100, 25, 20};
    Estadisticas enemigo = {85, 20, 15};
    int nivel = 1;
    string nombre;
    cout<< "¡Bienvenido a La Senda del Héroe!" << endl;
    cout<< "Eres un héroe que explora un calabozo lleno de enemigos."<<endl;
    cout<< "Debes alcanzar el nivel 5 derrotando enemigos y tomando decisiones estratégicas."<<endl;
    cout<< "Introduce el nombre de tu heroe: "<<endl;
    cin>> nombre;
    while (nivel < 5) {
        cout << "Un nuevo enemigo aparece..." << endl;
        mostrarEstadisticas(jugador, enemigo, nivel);
        // Batalla
        while (enemigo.vida > 0 && jugador.vida > 0) {
            if (!turnoJugador(jugador, enemigo)) break;
            if (enemigo.vida > 0) turnoEnemigo(jugador, enemigo);
        }
        if (jugador.vida <= 0) {
            cout << "Has caído en batalla. Tu aventura termina aquí. ¡Valiente intento, " << nombre<< endl;
            return 0;
        }
        if (enemigo.vida <= 0) {
            cout << "¡Derrotaste al enemigo! Subes de nivel."<<endl;
            nivelUp(jugador, nivel);
        }
    }
    cout<< "¡Felicidades, " << nombre << "! Has alcanzado el nivel 5 y completado La Senda del Héroe."<<endl;
    cout<< "Con valor y estrategia, venciste a todos los enemigos del calabozo y te convertiste en una leyenda."<<endl;
    cout<< "¡Gracias por jugar!" << endl;
    return 0;
}
}
