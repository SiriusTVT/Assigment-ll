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
    int startTime, CT, TAT, WT, RT;
    bool completado = false; // Para saber si ya fue ejecutado
};

// Algoritmo SJF (no expropiativo)
void calcularSJF(vector<Proceso> &p) {
    int tiempo = 0;
    int procesosCompletados = 0;
    int n = p.size();

    // Mientras no se ejecuten todos los procesos
    while (procesosCompletados < n) {
        // Buscar los procesos disponibles hasta el tiempo actual
        vector<int> indicesDisponibles;
        for (int i = 0; i < n; i++) {
            if (!p[i].completado && p[i].AT <= tiempo) {
                indicesDisponibles.push_back(i);
            }
        }

        if (indicesDisponibles.empty()) {
            tiempo++;
            continue;
        }

        // Elegir el proceso con menor Burst Time (BT)
        int idx = indicesDisponibles[0];
        for (int i : indicesDisponibles) {
            if (p[i].BT < p[idx].BT) {
                idx = i;
            }
        }

        // Asignar métricas al proceso elegido
        p[idx].startTime = tiempo;
        p[idx].CT = tiempo + p[idx].BT;
        p[idx].TAT = p[idx].CT - p[idx].AT;
        p[idx].WT = p[idx].TAT - p[idx].BT;
        p[idx].RT = p[idx].startTime; 
        tiempo = p[idx].CT;

        p[idx].completado = true;
        procesosCompletados++;
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

    calcularSJF(procesos);
    imprimirTabla(procesos);

    return 0;
}