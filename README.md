# Assignment II - Algoritmos de Planificación de CPU

Este proyecto implementa cuatro algoritmos fundamentales de planificación de CPU en C++, diseñado para ejecutarse con Docker usando la imagen `so-tools`.

## Algoritmos Implementados

1. **FCFS (First Come, First Served)** - `fifo.cpp`
2. **SJF (Shortest Job First)** - `sjf.cpp` 
3. **PSJF (Preemptive Shortest Job First)** - `psjf.cpp`
4. **RR (Round Robin)** - `rr.cpp`

## Estructura del Proyecto

```
Algoritmos Planificacion/
├── fifo.cpp          # Algoritmo FCFS
├── sjf.cpp           # Algoritmo SJF no expropiativo
├── psjf.cpp          # Algoritmo SJF expropiativo
├── rr.cpp            # Algoritmo Round Robin
├── procesos.txt      # Archivo de entrada original
└── inputE01.txt      # Archivo de entrada de ejemplo
```

## Formato de Archivos de Entrada

Los archivos de entrada deben seguir este formato:

```
Proceso   AT   BT   Queue   Priority
A         0    6    1       1
B         0    10   2       3
C         0    3    3       5
```

Donde:
- **Proceso**: Nombre del proceso
- **AT**: Arrival Time (tiempo de llegada)
- **BT**: Burst Time (tiempo de ejecución)
- **Queue**: Número de cola
- **Priority**: Prioridad del proceso

## Compilación y Ejecución

### Usando Docker (Recomendado)

```bash
# Ejecutar contenedor con so-tools
docker run -it --rm -v ${PWD}:/workspace so-tools

# Dentro del contenedor, navegar al directorio
cd /workspace/Algoritmos\ Planificacion/

# Compilar todos los algoritmos
g++ -o fifo fifo.cpp
g++ -o sjf sjf.cpp
g++ -o psjf psjf.cpp
g++ -o rr rr.cpp
```

### Compilación Local

```bash
cd "Algoritmos Planificacion"

# Compilar cada algoritmo
g++ -o fifo.exe fifo.cpp
g++ -o sjf.exe sjf.cpp
g++ -o psjf.exe psjf.cpp
g++ -o rr.exe rr.cpp
```

## Ejecución de los Algoritmos

### FCFS (First Come, First Served)
```bash
./fifo
# o en Windows: fifo.exe
```

### SJF (Shortest Job First)
```bash
./sjf
# o en Windows: sjf.exe
```

### PSJF (Preemptive Shortest Job First)
```bash
./psjf
# o en Windows: psjf.exe
```

### Round Robin
```bash
./rr
# o en Windows: rr.exe
# Se solicitará ingresar el quantum
```

### Usando diferentes archivos de entrada

Para usar un archivo específico, simplemente cámbialo por `procesos.txt`:

```bash
# Ejemplo con inputE02.txt
copy inputE02.txt procesos.txt
./rr
# Ingresa quantum (ej: 2)

# Ejemplo con inputE03.txt  
copy inputE03.txt procesos.txt
./fifo

# Restaurar archivo original
copy procesos_backup.txt procesos.txt
```

O crea una versión modificada que lea directamente el archivo deseado.

## Ejemplo de Uso

```bash
# Compilar Round Robin
g++ -o rr rr.cpp

# Ejecutar con archivo de entrada
./rr
# Entrada: Quantum = 3

# Salida esperada:
=== Algoritmo Round Robin (Quantum = 3) ===

Proceso   AT    BT    CT    TAT   WT    RT   
----------------------------------------------------------
A         0     6     9     9     3     0    
B         0     10    20    20    10    3    
C         0     3     6     6     3     6    
D         0     19    39    39    20    12   
E         0     8     17    17    9     15   

--- Métricas Promedio ---
Turnaround Time promedio: 18.20
Waiting Time promedio: 9.00
Response Time promedio: 7.20
```

## Archivos de Entrada Incluidos

- **procesos.txt**: Archivo de entrada original con 3 procesos
- **inputE01.txt**: Archivo de ejemplo con 5 procesos (A, B, C, D, E) - todos llegan en tiempo 0
- **inputE02.txt**: Archivo con 4 procesos (P1, P2, P3, P4) - llegadas escalonadas
- **inputE03.txt**: Archivo con 5 procesos (X, Y, Z, W, V) - diferentes tiempos de llegada
- **inputE04.txt**: Archivo con 6 procesos (Alpha, Beta, Gamma, Delta, Epsilon, Zeta) - caso complejo
- **inputE05.txt**: Archivo con 5 procesos (Job1-Job5) - llegadas cada 2 unidades de tiempo

### Detalles de cada archivo:

**inputE01.txt** - Todos los procesos llegan simultáneamente:
```
A: BT=6, AT=0    B: BT=10, AT=0    C: BT=3, AT=0    D: BT=19, AT=0    E: BT=8, AT=0
```

**inputE02.txt** - Llegadas consecutivas:
```
P1: BT=5, AT=0    P2: BT=3, AT=1    P3: BT=8, AT=2    P4: BT=6, AT=3
```

**inputE03.txt** - Llegadas distribuidas:
```
X: BT=4, AT=0    Y: BT=1, AT=2    Z: BT=2, AT=4    W: BT=7, AT=5    V: BT=3, AT=6
```

**inputE04.txt** - Caso con 6 procesos:
```
Alpha: BT=9, AT=0    Beta: BT=4, AT=1    Gamma: BT=2, AT=3    
Delta: BT=6, AT=4    Epsilon: BT=5, AT=7    Zeta: BT=3, AT=8
```

**inputE05.txt** - Llegadas regulares cada 2 unidades:
```
Job1: BT=7, AT=0    Job2: BT=3, AT=2    Job3: BT=5, AT=4    
Job4: BT=2, AT=6    Job5: BT=4, AT=8
```

## Métricas Calculadas

Todos los algoritmos calculan y muestran:

- **AT**: Arrival Time (tiempo de llegada)
- **BT**: Burst Time (tiempo de ejecución)
- **CT**: Completion Time (tiempo de finalización)
- **TAT**: Turnaround Time (tiempo total)
- **WT**: Waiting Time (tiempo de espera)
- **RT**: Response Time (tiempo de respuesta)

## Notas Técnicas

- Los algoritmos manejan procesos que llegan en diferentes momentos
- PSJF implementa expropiation (preemption)
- Round Robin permite configurar el quantum de tiempo
- Todos los archivos incluyen manejo de errores para archivos no encontrados