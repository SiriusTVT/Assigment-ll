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
};

// Algoritmo FCFS
void calcularFCFS(vector<Proceso> &p) {
    sort(p.begin(), p.end(), [](Proceso &a, Proceso &b){ return a.AT < b.AT; });
    int tiempo = 0;
    for (auto &x : p) {
        if (tiempo < x.AT) tiempo = x.AT;
        x.startTime = tiempo;
        x.CT = tiempo + x.BT;
        x.TAT = x.CT - x.AT;
        x.WT = x.TAT - x.BT;
        x.RT = x.startTime;
        tiempo = x.CT;
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

    calcularFCFS(procesos);
    imprimirTabla(procesos);

    return 0;
}