#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string numeroPlaca;
    string color;
    string marca;
    double velocimetro;

public:
    Vehiculo(string placa, string col, string mar, double vel)
        : numeroPlaca(placa), color(col), marca(mar), velocimetro(vel){}

    void mostrarDatos() const {
        cout << "Placa: " << numeroPlaca << "\n"
             << "Color: " << color << "\n"
             << "Marca: " << marca << "\n"
             << "Velocidad: " << velocimetro << " km/h\n";
    }

    void cambiarVelocidad(double nuevaVelocidad) {
        velocimetro = nuevaVelocidad;
    }
};

class Automovil : public Vehiculo {
private:
    int cantidadPuertas;
    int cantidadPasajeros;

public:
    Automovil(string placa, string col, string mar, double vel, int puertas, int pasajeros)
        : Vehiculo(placa, col, mar, vel), cantidadPuertas(puertas), cantidadPasajeros(pasajeros) {}

    void mostrarAutomovil() const {
        mostrarDatos();
        cout << "Puertas: " << cantidadPuertas << "\n"
             << "Pasajeros: " << cantidadPasajeros << "\n";
    }

    void subirPasajeros(int cantidad) {
        cantidadPasajeros += cantidad;
    }

    void bajarPasajeros(int cantidad) {
        if (cantidadPasajeros >= cantidad) {
            cantidadPasajeros -= cantidad;
        } else {
            cantidadPasajeros = 0;
        }
    }
};

class Camion : public Vehiculo {
private:
    double carga;

public:
    Camion(string placa, string col, string mar, double vel, double cargaInicial)
        : Vehiculo(placa, col, mar, vel), carga(cargaInicial) {}

    void mostrarCamion() const {
        mostrarDatos();
        cout << "Carga: " << carga << " kg\n";
    }

    void cambiarCarga(double nuevaCarga) {
        carga = nuevaCarga;
    }
};

int main() {
    Automovil auto1("ABC-123", "Rojo", "Toyota", 60.0, 4, 2);
    Camion camion1("XYZ-890", "Azul", "Volvo", 40.0, 1500.5);

    cout << "--- DATOS INICIALES DEL AUTOMOVIL ---\n";
    auto1.mostrarAutomovil();

    cout << "\n--- DATOS INICIALES DEL CAMION ---\n";
    camion1.mostrarCamion();

    auto1.cambiarVelocidad(80.5);
    auto1.subirPasajeros(2);
    auto1.bajarPasajeros(1);

    camion1.cambiarVelocidad(50.0);
    camion1.cambiarCarga(2000.0);

    cout << "\n--- DATOS MODIFICADOS DEL AUTOMOVIL ---\n";
    auto1.mostrarAutomovil();

    cout << "\n--- DATOS MODIFICADOS DEL CAMION ---\n";
    camion1.mostrarCamion();

    return 0;
}