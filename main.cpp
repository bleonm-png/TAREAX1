//BERTHA JASSEL LEÓN MELCHOR//

#include <iostream>
#include <fstream>

using namespace std;

// ===============================
// STRUCT
// ===============================
struct Producto {
    int codigo;
    char nombre[40];
    char categoria[30];
    int stock;
    float precio;
    bool activo;
};

// ===============================
// FUNCIONES
// ===============================
void menu();
void registrarProducto();
void listarProductos();

// ===============================
// MAIN
// ===============================
int main() {
    menu();
    return 0;
}

// ===============================
// MENÚ
// ===============================
void menu() {
    int opcion;
    do {
        cout << "\n==============================";
        cout << "\n SISTEMA DE VENTAS E INVENTARIO";
        cout << "\n==============================";

        cout << "\n1. Registrar producto";
        cout << "\n2. Listar productos";
        cout << "\n3. Salir";
        cout << "\n\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                registrarProducto();
                break;
            case 2:
                listarProductos();
                break;
            case 3:
                cout << "\nPrograma finalizado.\n";
                break;
            default:
                cout << "\nOpcion invalida.\n";
        }
    } while(opcion != 3);
}

// ===============================
// REGISTRAR PRODUCTO
// ===============================
void registrarProducto() {
    Producto producto;
    ofstream archivo("productos.dat", ios::binary | ios::app);

    if(!archivo) {
        cout << "\nError al abrir el archivo.\n";
        return;
    }

    cout << "\n========== REGISTRO ==========";
    cout << "\nCodigo: ";
    cin >> producto.codigo;
    cin.ignore();

    cout << "Nombre: ";
    cin.getline(producto.nombre, 40);
    cout << "Categoria: ";
    cin.getline(producto.categoria, 30);
    cout << "Stock: ";
    cin >> producto.stock;
    cout << "Precio: ";
    cin >> producto.precio;
    producto.activo = true;

    // Escritura binaria
    archivo.write((char*)&producto, sizeof(producto));
    archivo.close();
    cout << "\nProducto registrado correctamente.\n";
}

// ===============================
// LISTAR PRODUCTOS
// ===============================
void listarProductos() {
    Producto p;
    ifstream archivo("productos.dat", ios::binary);
    if(!archivo) {
        cout << "\nNo existe informacion almacenada.\n";
        return;
    }

    cout << "\n========== LISTADO ==========\n";
    while(archivo.read((char*)&p, sizeof(p))) {
        cout << "\n-------------------------";
        cout << "\nCodigo: " << p.codigo;
        cout << "\nNombre: " << p.nombre;
        cout << "\nCategoria: " << p.categoria;
        cout << "\nStock: " << p.stock;
        cout << "\nPrecio: " << p.precio;
        cout << "\nActivo: " << (p.activo ? "Si" : "No");
;
    }
    archivo.close();
}