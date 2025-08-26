# AFD

notas

for i in range(len(w)): recorre cada carácter de la cadena w.

En cada iteración:

simbolo_actual toma la letra en la posición i.

Se busca una transición que parta del estado actual q y coincida con simbolo_actual.

Si se encuentra, se cambia el estado q al nuevo estado destino.

El bucle interno (for j in range(len(delta))) se rompe (break) en cuanto encuentra una transición válida.

if q in estado_final:: se evalúa si el estado en el que terminó el autómata está dentro de los estados de aceptación. En C se usaba strstr.
