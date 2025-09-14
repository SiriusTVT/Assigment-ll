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
├── procesos.txt      # Archivo de entrada principal (datos actualizados)
├── inputE01.txt      # Ejemplo 1 - Datos actualizados (mismo que procesos.txt)
├── inputE02.txt      # Ejemplo 2 - Llegadas escalonadas (4 procesos)
├── inputE03.txt      # Ejemplo 3 - Llegadas distribuidas (5 procesos)
├── inputE04.txt      # Ejemplo 4 - Caso complejo (6 procesos)
└── inputE05.txt      # Ejemplo 5 - Llegadas regulares (5 procesos)
```

## Formato de Archivos de Entrada

Los archivos de entrada deben seguir este formato:

```
Proceso   AT   BT   Queue   Priority
A         0    6    1       5
B         0    9    1       4
C         0    10   2       3
D         0    15   2       3
E         0    8    3       2
```

Donde:
- **Proceso**: Nombre del proceso
- **AT**: Arrival Time (tiempo de llegada)
- **BT**: Burst Time (tiempo de ejecución)
- **Queue**: Número de cola
- **Priority**: Prioridad del proceso (5 > 1, siendo 5 la mayor prioridad)

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

### Demostración completa con inputE01.txt

El siguiente ejemplo muestra cómo ejecutar todos los algoritmos con el conjunto de datos principal:

**Datos de entrada (inputE01.txt):**
```
Proceso   AT   BT   Queue   Priority
A         0    6    1       5
B         0    9    1       4
C         0    10   2       3
D         0    15   2       3
E         0    8    3       2
```

### Paso 1: Compilar todos los algoritmos
```bash
g++ -o fifo.exe fifo.cpp
g++ -o sjf.exe sjf.cpp
g++ -o psjf.exe psjf.cpp
g++ -o rr.exe rr.cpp
```

### Paso 2: Ejecutar cada algoritmo

#### FCFS (First Come, First Served)
```bash
fifo.exe
```
**Salida esperada:**
```
Proceso   AT    BT    CT    TAT   WT    RT    
A         0     6     6     6     0     0     
B         0     9     15    15    6     6     
C         0     10    25    25    15    15    
D         0     15    40    40    25    25    
E         0     8     48    48    40    40    
```

#### SJF (Shortest Job First)
```bash
sjf.exe
```
**Salida esperada:**
```
Proceso   AT    BT    CT    TAT   WT    RT    
A         0     6     6     6     0     0     
E         0     8     14    14    6     6     
B         0     9     23    23    14    14    
C         0     10    33    33    23    23    
D         0     15    48    48    33    33    
```

#### PSJF (Preemptive Shortest Job First)
```bash
psjf.exe
```
**Salida esperada:**
```
Proceso   AT    BT    CT    TAT   WT    RT    
A         0     6     6     6     0     0     
E         0     8     14    14    6     6     
B         0     9     23    23    14    14    
C         0     10    33    33    23    23    
D         0     15    48    48    33    33    
```

#### Round Robin (Quantum = 3)
```bash
echo "3" | rr.exe
```
**Salida esperada:**
```
=== Algoritmo Round Robin (Quantum = 3) ===

Proceso   AT    BT    CT    TAT   WT    RT    
----------------------------------------------------------
A         0     6     18    18    12    0     
B         0     9     36    36    27    3     
C         0     10    43    43    33    6     
D         0     15    48    48    33    9     
E         0     8     35    35    27    12    

--- Métricas Promedio ---
Turnaround Time promedio: 36.00
Waiting Time promedio: 26.40
Response Time promedio: 6.00
```

### Comparación de Resultados

| Algoritmo | TAT Promedio | WT Promedio | RT Promedio |
|-----------|--------------|-------------|-------------|
| FCFS      | 22.80        | 17.20       | 17.20       |
| SJF       | 24.80        | 15.20       | 15.20       |
| PSJF      | 24.80        | 15.20       | 15.20       |
| RR (q=3)  | 36.00        | 26.40       | 6.00        |

**Análisis:**
- **SJF/PSJF** tienen el mejor tiempo de espera promedio
- **Round Robin** tiene el mejor tiempo de respuesta promedio
- **FCFS** es el más simple pero no el más eficiente

## Archivos de Entrada Incluidos

- **procesos.txt**: Archivo de entrada principal (actualmente con datos del ejemplo 1)
- **inputE01.txt**: Ejemplo principal con 5 procesos - datos actualizados
- **inputE02.txt**: Archivo con 4 procesos (P1, P2, P3, P4) - llegadas escalonadas
- **inputE03.txt**: Archivo con 5 procesos (X, Y, Z, W, V) - diferentes tiempos de llegada
- **inputE04.txt**: Archivo con 6 procesos (Alpha, Beta, Gamma, Delta, Epsilon, Zeta) - caso complejo
- **inputE05.txt**: Archivo con 5 procesos (Job1-Job5) - llegadas cada 2 unidades de tiempo

### Detalles de cada archivo:

**procesos.txt / inputE01.txt** - Ejemplo principal (datos actuales):
```
A: AT=0, BT=6, Queue=1, Priority=5
B: AT=0, BT=9, Queue=1, Priority=4
C: AT=0, BT=10, Queue=2, Priority=3
D: AT=0, BT=15, Queue=2, Priority=3
E: AT=0, BT=8, Queue=3, Priority=2
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

## Características Avanzadas del Proyecto

### Algoritmo Round Robin Mejorado
- **Quantum configurable** por el usuario en tiempo de ejecución
- **Manejo correcto de preempción** con cola circular
- **Cálculo preciso del Response Time** (tiempo hasta primera ejecución)
- **Manejo de procesos** que llegan en diferentes momentos durante la ejecución
- **Métricas estadísticas** con promedios calculados automáticamente

### Métricas Completas Calculadas
Todos los algoritmos calculan y muestran las siguientes métricas estándar:

- **AT (Arrival Time)**: Tiempo de llegada del proceso
- **BT (Burst Time)**: Tiempo de ejecución requerido
- **CT (Completion Time)**: Tiempo en que termina la ejecución
- **TAT (Turnaround Time)**: Tiempo total en el sistema (CT - AT)
- **WT (Waiting Time)**: Tiempo de espera (TAT - BT)
- **RT (Response Time)**: Tiempo hasta primera ejecución (Start Time - AT)

### Manejo Robusto de Errores
- Verificación de existencia de archivos de entrada
- Validación de quantum en Round Robin
- Manejo de archivos vacíos o con formato incorrecto
- Mensajes de error descriptivos

### Comparación de Algoritmos
El proyecto permite comparar fácilmente el rendimiento de los cuatro algoritmos principales:

1. **FCFS**: Simple pero puede causar convoy effect
2. **SJF**: Minimiza tiempo de espera promedio pero puede causar starvation
3. **PSJF**: Versión preemptiva de SJF, óptima para tiempo de espera
4. **Round Robin**: Mejor tiempo de respuesta, justo para todos los procesos

### Casos de Prueba Diversos
- **Procesos simultáneos**: Todos llegan en AT=0
- **Llegadas escalonadas**: Procesos llegan en momentos diferentes
- **Diferentes tamaños de Burst Time**: Desde procesos cortos hasta largos
- **Múltiples colas y prioridades**: Para extensiones futuras

### Formato de Archivos Estandardizado
Todos los archivos de entrada siguen el mismo formato consistente:
```
Proceso   AT   BT   Queue   Priority
<nombre>  <at> <bt> <queue> <priority>
```

Esto facilita:
- **Intercambio rápido** entre diferentes conjuntos de datos
- **Creación fácil** de nuevos casos de prueba
- **Compatibilidad** con herramientas de análisis externas

## Conclusiones y Análisis

### Rendimiento de Algoritmos con Ejemplo Principal

Basado en los resultados del ejemplo principal (inputE01.txt):

| Métrica | FCFS | SJF/PSJF | RR (q=3) | Mejor |
|---------|------|----------|----------|-------|
| **Turnaround Time Promedio** | 22.80 | 24.80 | 36.00 | SJF/PSJF |
| **Waiting Time Promedio** | 17.20 | 15.20 | 26.40 | SJF/PSJF |
| **Response Time Promedio** | 17.20 | 15.20 | 6.00 | **Round Robin** |

### Recomendaciones de Uso

- **Para sistemas batch**: SJF o PSJF (minimiza tiempo total)
- **Para sistemas interactivos**: Round Robin (mejor respuesta)
- **Para sistemas simples**: FCFS (implementación sencilla)
- **Para sistemas de tiempo real**: PSJF con consideraciones de deadline

### Extensiones Futuras Posibles

1. **Algoritmos de prioridad** utilizando el campo Priority
2. **Multiple-level feedback queues** utilizando el campo Queue
3. **Algoritmos de tiempo real** (Earliest Deadline First)
4. **Interfaz gráfica** para visualización de cronogramas
5. **Generador automático** de casos de prueba
6. **Análisis estadístico** avanzado con gráficos

## Estructura Final del Proyecto

```
Algoritmos Planificacion/
├── fifo.cpp          # FCFS Algorithm
├── sjf.cpp           # SJF Algorithm  
├── psjf.cpp          # PSJF Algorithm
├── rr.cpp            # Round Robin Algorithm
├── procesos.txt      # Main input file (Example 1)
├── inputE01.txt      # Example 1 - Updated data
├── inputE02.txt      # Example 2 - Staggered arrivals
├── inputE03.txt      # Example 3 - Distributed arrivals
├── inputE04.txt      # Example 4 - Complex case (6 processes)
└── inputE05.txt      # Example 5 - Regular intervals
```

**Total**: 4 algoritmos implementados + 6 conjuntos de datos de prueba