#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

// Estructura que representa un proceso con sus métricas
struct Proceso {
    string proceso;   
    int AT, BT;       
    int startTime = -1, CT, TAT, WT, RT;
    int remainingBT;  // Tiempo restante de ejecución
    bool completado = false;
};

// Algoritmo PSJF (expropiativo)
void calcularPSJF(vector<Proceso> &p) {
    int tiempo = 0;
    int procesosCompletados = 0;
    int n = p.size();

    // Inicializar tiempos restantes
    for (auto &x : p) {
        x.remainingBT = x.BT;
    }

    // Mientras no se ejecuten todos los procesos
    while (procesosCompletados < n) {
        // Buscar el proceso disponible con menor BT restante
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (!p[i].completado && p[i].AT <= tiempo) {
                if (idx == -1 || p[i].remainingBT < p[idx].remainingBT) {
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            tiempo++;
            continue;
        }

        if (p[idx].startTime == -1) {
            p[idx].startTime = tiempo;
            p[idx].RT = p[idx].startTime; 
        }

        // Ejecutar 1 unidad de tiempo
        p[idx].remainingBT--;
        tiempo++;

        // Si termina su ejecución
        if (p[idx].remainingBT == 0) {
            p[idx].completado = true;
            p[idx].CT = tiempo;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            procesosCompletados++;
        }
    }
}

// Imprime la tabla con las métricas
void imprimirTabla(vector<Proceso> &p) {
    cout << left << setw(10) << "Proceso"
         << setw(6) << "AT"
         << setw(6) << "BT"
         << setw(6) << "CT"
         << setw(6) << "TAT"
         << setw(6) << "WT"
         << setw(6) << "RT" << "\n";
    for (auto &x : p) {
        cout << left << setw(10) << x.proceso
             << setw(6) << x.AT
             << setw(6) << x.BT
             << setw(6) << x.CT
             << setw(6) << x.TAT
             << setw(6) << x.WT
             << setw(6) << x.RT << "\n";
    }
}

int main() {
    ifstream archivo("procesos.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo.\n";
        return 1;
    }

    vector<Proceso> procesos;
    string proceso;
    int AT, BT, queue, priority;

    string encabezado;
    getline(archivo, encabezado);

    while (archivo >> proceso >> AT >> BT >> queue >> priority) {
        procesos.push_back({proceso, AT, BT});
    }

    calcularPSJF(procesos);
    imprimirTabla(procesos);

    return 0;
}