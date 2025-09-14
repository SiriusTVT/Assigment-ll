#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <queue>
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

// Algoritmo Round Robin con quantum configurable
void calcularRR(vector<Proceso> &p, int quantum) {
    int tiempo = 0;
    int procesosCompletados = 0;
    int n = p.size();
    queue<int> colaListos; // Cola de procesos listos para ejecutar
    vector<bool> enCola(n, false); // Para evitar duplicados en la cola

    // Inicializar tiempos restantes
    for (auto &x : p) {
        x.remainingBT = x.BT;
    }

    // Agregar procesos que llegan en tiempo 0
    for (int i = 0; i < n; i++) {
        if (p[i].AT == 0) {
            colaListos.push(i);
            enCola[i] = true;
        }
    }

    while (procesosCompletados < n) {
        // Si no hay procesos en la cola, avanzar el tiempo hasta el próximo proceso
        if (colaListos.empty()) {
            // Buscar el próximo proceso que llegue
            int siguienteAT = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!p[i].completado && p[i].AT > tiempo) {
                    siguienteAT = min(siguienteAT, p[i].AT);
                }
            }
            if (siguienteAT != INT_MAX) {
                tiempo = siguienteAT;
                // Agregar procesos que llegan en este tiempo
                for (int i = 0; i < n; i++) {
                    if (p[i].AT == tiempo && !enCola[i] && !p[i].completado) {
                        colaListos.push(i);
                        enCola[i] = true;
                    }
                }
            }
            continue;
        }

        // Obtener el siguiente proceso de la cola
        int idx = colaListos.front();
        colaListos.pop();
        enCola[idx] = false;

        // Si es la primera vez que se ejecuta este proceso
        if (p[idx].startTime == -1) {
            p[idx].startTime = tiempo;
            p[idx].RT = tiempo - p[idx].AT;
        }

        // Calcular tiempo de ejecución (quantum o tiempo restante, el menor)
        int tiempoEjecucion = min(quantum, p[idx].remainingBT);
        p[idx].remainingBT -= tiempoEjecucion;
        tiempo += tiempoEjecucion;

        // Agregar procesos que llegaron durante la ejecución
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= tiempo && !enCola[i] && !p[i].completado && i != idx) {
                colaListos.push(i);
                enCola[i] = true;
            }
        }

        // Si el proceso terminó
        if (p[idx].remainingBT == 0) {
            p[idx].completado = true;
            p[idx].CT = tiempo;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            procesosCompletados++;
        } else {
            // Si no terminó, volver a la cola
            colaListos.push(idx);
            enCola[idx] = true;
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
    cout << string(58, '-') << "\n";
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

// Calcula y muestra métricas promedio
void mostrarPromedios(vector<Proceso> &p) {
    double sumTAT = 0, sumWT = 0, sumRT = 0;
    for (auto &x : p) {
        sumTAT += x.TAT;
        sumWT += x.WT;
        sumRT += x.RT;
    }
    int n = p.size();
    cout << "\n--- Métricas Promedio ---\n";
    cout << "Turnaround Time promedio: " << fixed << setprecision(2) << sumTAT / n << "\n";
    cout << "Waiting Time promedio: " << fixed << setprecision(2) << sumWT / n << "\n";
    cout << "Response Time promedio: " << fixed << setprecision(2) << sumRT / n << "\n";
}

int main() {
    ifstream archivo("procesos.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo procesos.txt\n";
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

    archivo.close();

    if (procesos.empty()) {
        cerr << "No se encontraron procesos en el archivo.\n";
        return 1;
    }

    int quantum;
    cout << "Ingrese el quantum para Round Robin: ";
    cin >> quantum;

    if (quantum <= 0) {
        cerr << "El quantum debe ser mayor que 0.\n";
        return 1;
    }

    cout << "\n=== Algoritmo Round Robin (Quantum = " << quantum << ") ===\n\n";
    
    calcularRR(procesos, quantum);
    imprimirTabla(procesos);
    mostrarPromedios(procesos);

    return 0;
}