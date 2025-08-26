### AFD

## Objetivo

Diseñar e implementar un **Autómata Finito Determinista (AFD)** en dos lenguajes de programación: **C** y **Python**.

El programa recibe dos archivos de entrada:

* `conf.txt`: contiene la configuración del AFD (estados, alfabeto, estado inicial, estado(s) de aceptación y transiciones).
* `cadena.txt`: contiene una o más cadenas a evaluar con el autómata.

El sistema debe evaluar si cada cadena es **aceptada** o **rechazada** por el AFD configurado.

---

### Explicación general del AFD

Un **Autómata Finito Determinista (AFD)** es una máquina teórica utilizada para reconocer lenguajes formales. Está compuesto por:

* Un conjunto de **estados**.
* Un **alfabeto** de símbolos de entrada.
* Un **estado inicial**.
* Un conjunto de **estados de aceptación**.
* Un conjunto de **transiciones**, que determinan cómo se mueve de un estado a otro en función del símbolo de entrada.

El AFD comienza en el estado inicial y procesa una cadena de entrada símbolo por símbolo. En cada paso, sigue una **única transición** válida. Al final de la cadena, si el estado alcanzado es uno de aceptación, la cadena es **aceptada**; en caso contrario, es **rechazada**.

---

### Diferencias entre la implementación en C y Python

| Aspecto                 | C                                                                    | Python                                                              |
| ----------------------- | -------------------------------------------------------------------- | ------------------------------------------------------------------- |
| Lectura de archivos     | Se usa `fopen`, `fgets`, y `sscanf` para leer líneas y extraer datos | Se usa `open`, `readline()`, `split()` para dividir texto           |
| Estructura de datos     | Se utiliza un `struct` para representar transiciones                 | Se define una clase `Trans` con `__init__()` método especial que actúa como el constructor de una clase                        |
| Manipulación de cadenas | Manual (uso de `strcpy`, `strcmp`, `strstr`, etc.)                   | Sencilla (operadores `in`, slicing, `==`)                           |
| Tipado                  | Estricto: es necesario declarar tipos (`char`, `int`, etc.)          | Dinámico: el tipo se infiere automáticamente                        |
| Bucles                  | Se usan `for` con índices y `while` para recorrer datos              | Se usan `for` con rangos o iteración directa sobre listas y strings |
| Control de errores      | Debe hacerse manualmente (e.g., verificar punteros nulos)            | Más flexible; errores son lanzados como excepciones automáticamente |

---

### Notas

#### En C:

```c
for(int i = 0; w[i]; i++) {
    for(int j = 0; j < n; j++) {
        if(strcmp(q, delta[j].s) == 0 && w[i] == delta[j].c) {
            strcpy(q, delta[j].t);
            break;
        }
    }
}
```

* El bucle externo recorre **cada símbolo** de la cadena.
* El bucle interno busca una **transición válida** entre todas las posibles.
* `break` se usa para salir una vez encontrada la transición correcta.

#### En Python:

```python
for i in range(len(w)):
    simbolo_actual = w[i]
    for j in range(len(delta)):
        trans = delta[j]
        if q == trans.s and simbolo_actual == trans.c:
            q = trans.t
            break
```

* Lógica equivalente al código en C.
* `range(len(...))` se usa para recorrer posiciones.
* Se accede a objetos directamente (`trans.s`, `trans.c`, `trans.t`).
* Uso de `break` también es idéntico.

### Ejemplo de salida

```
└─$ python3 AFD.py
101 -> ACEPTADA
1110 -> ACEPTADA
000 -> RECHAZADA
ε -> RECHAZADA
10 -> ACEPTADA

```

---

¿Te gustaría que este `README` lo formatee como archivo `.md` para que puedas subirlo a GitHub con estilo?
