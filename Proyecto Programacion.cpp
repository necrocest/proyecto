#include <iostream>
#include <string>
using namespace std;
// Estructura para las estadísticas de un personaje
struct Estadisticas{
    int vida;
    int ataque;
    int defensa;
};
// Función para mostrar estadísticas
void mostrarEstadisticas(const Estadisticas jugador, const Estadisticas enemigo, int nivel){
    cout << "Jugador - Vida: " << jugador.vida << ", Ataque: " << jugador.ataque << ", Defensa: " << jugador.defensa <<", Nivel: "<< nivel <<endl;
    cout << "Enemigo - Vida: " << enemigo.vida << ", Ataque: " << enemigo.ataque << ", Defensa: " << enemigo.defensa <<endl;
}
// Función para calcular el daño
int calcularDanio(int ataque, int defensa){
    int dano = ataque - defensa;
    return (dano > 0) ? dano : 1;// operaor ternario evalualr true o false
}
// Función para subir de nivel
void nivelUp(Estadisticas jugador, int nivel){
    nivel++;
    jugador.vida += 20;
    jugador.ataque += 5;
    jugador.defensa += 2;
    cout << "¡Subiste al nivel! " << nivel << "¡Tus estadisticas han mejorado.!"<<endl;
}
int main(){ 
    Estadisticas jugador == {100, 25, 20};
    Estadisticas enemigo == { 75, 20, 15};
    int nivel = 1; 
    string nombre;
    cout<<"El jugador encarna a un heroe que recorre un calabozo enfrentandose"<<endl;
	cout<<"a una serie de enemigos y tomando decisiones estrategicas para sobrevivir,"<<endl;
	cout<<"dentro de este mundo las preguntas juegan un papel fundamental buscando determinar"<<endl;
	cout<<"el valor o la decadencia del heroe. Durante el juego el jugador tendra que"<<endl;
	cout<<"decidir si luchar o huir, y ganara puntos o perdera vida dependiendo de"<<endl; 
	cout<<"sus decisiones y de los resultados de los enfrentamientos"<<endl;
    cout<<"ingrese el nombre de su heroe"<<endl;
    cin>>nombre;
	cout <<"Bienvenido a La Senda del Hroe"<<endl;
    cout <<"Tu objetivo es alcanzar el nivel 5 derrotando enemigos."<<endl;
    while(nivel<5){

    }
}
