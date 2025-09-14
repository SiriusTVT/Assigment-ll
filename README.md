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

### Compilación Local (Windows)

```bash
cd "Algoritmos Planificacion"

# Compilar cada algoritmo individualmente
g++ -o fifo.exe fifo.cpp
g++ -o sjf.exe sjf.cpp
g++ -o psjf.exe psjf.cpp
g++ -o rr.exe rr.cpp

# O compilar todos de una vez
g++ -o fifo.exe fifo.cpp && g++ -o sjf.exe sjf.cpp && g++ -o psjf.exe psjf.cpp && g++ -o rr.exe rr.cpp
```

### Compilación Local (Linux/macOS)

```bash
cd "Algoritmos Planificacion"

# Compilar cada algoritmo individualmente
g++ -o fifo fifo.cpp
g++ -o sjf sjf.cpp
g++ -o psjf psjf.cpp
g++ -o rr rr.cpp

# O compilar todos de una vez
g++ -o fifo fifo.cpp && g++ -o sjf sjf.cpp && g++ -o psjf psjf.cpp && g++ -o rr rr.cpp
```

## Ejecución de los Algoritmos

### Proceso básico para ejecutar cualquier algoritmo:

1. **Elegir archivo de entrada** (copiar a procesos.txt)
2. **Compilar** el algoritmo deseado  
3. **Ejecutar** el programa

### FCFS (First Come, First Served)
```bash
# Compilar
g++ -o fifo.exe fifo.cpp

# Ejecutar
./fifo         # Linux/Docker
fifo.exe       # Windows
```

### SJF (Shortest Job First)
```bash
# Compilar
g++ -o sjf.exe sjf.cpp

# Ejecutar
./sjf          # Linux/Docker
sjf.exe        # Windows
```

### PSJF (Preemptive Shortest Job First)
```bash
# Compilar
g++ -o psjf.exe psjf.cpp

# Ejecutar
./psjf         # Linux/Docker
psjf.exe       # Windows
```

### Round Robin
```bash
# Compilar
g++ -o rr.exe rr.cpp

# Ejecutar (se solicitará el quantum)
./rr           # Linux/Docker
rr.exe         # Windows

# Ejecutar con quantum predefinido
echo "3" | ./rr        # Linux/Docker
echo "3" | rr.exe      # Windows
```

## Usando Diferentes Archivos de Entrada

### Método Manual (Recomendado)

Para usar cualquier archivo de entrada específico:

```bash
# 1. Copiar el archivo deseado como procesos.txt
copy inputE02.txt procesos.txt

# 2. Compilar el algoritmo (solo la primera vez o si cambió el código)
g++ -o rr.exe rr.cpp

# 3. Ejecutar
echo "2" | rr.exe
```

### Ejemplos Completos

**Ejemplo 1: Round Robin con inputE04.txt y quantum 3**
```bash
copy inputE04.txt procesos.txt
g++ -o rr.exe rr.cpp
echo "3" | rr.exe
```

**Ejemplo 2: FCFS con inputE03.txt**
```bash
copy inputE03.txt procesos.txt
g++ -o fifo.exe fifo.cpp
fifo.exe
```

**Ejemplo 3: SJF con inputE02.txt**
```bash
copy inputE02.txt procesos.txt
g++ -o sjf.exe sjf.cpp
sjf.exe
```

**Ejemplo 4: PSJF con inputE05.txt**
```bash
copy inputE05.txt procesos.txt
g++ -o psjf.exe psjf.cpp
psjf.exe
```

### Compilación por lotes (Opcional)

Para compilar todos los algoritmos de una vez:

```bash
# Windows
g++ -o fifo.exe fifo.cpp && g++ -o sjf.exe sjf.cpp && g++ -o psjf.exe psjf.cpp && g++ -o rr.exe rr.cpp

# Linux/Docker
g++ -o fifo fifo.cpp && g++ -o sjf sjf.cpp && g++ -o psjf psjf.cpp && g++ -o rr rr.cpp
```

### Notas Importantes

- **No es necesario recompilar** cada vez, solo cuando cambies el código fuente
- Los archivos ejecutables (.exe) se pueden eliminar y regenerar cuando sea necesario
- Todos los algoritmos leen automáticamente el archivo `procesos.txt`
- Para Round Robin, el quantum se solicita durante la ejecución

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