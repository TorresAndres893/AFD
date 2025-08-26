# Definimos una clase simple para representar una transición
class Trans:
    def __init__(self, s, c, t):
        self.s = s  # Estado de origen
        self.c = c  # Símbolo del alfabeto
        self.t = t  # Estado de destino

# Función principal del programa
def main():
    # Abrimos el archivo de configuración del autómata
    archivo = open("conf.txt", "r")

    # Leemos y procesamos las primeras 4 líneas del archivo
    # Cada línea tiene el formato: clave=valor
    estados = archivo.readline().strip().split('=')[1]
    alfabeto = archivo.readline().strip().split('=')[1]
    estado_inicio = archivo.readline().strip().split('=')[1]
    estado_final = archivo.readline().strip().split('=')[1]

    # Creamos una lista vacía para almacenar las transiciones
    delta = []

    # Leemos las transiciones restantes en el archivo
    for line in archivo:
        line = line.strip()
        if line != "":
            # Dividimos la línea por comas: origen,símbolo,destino
            partes = line.split(',')
            origen = partes[0]
            simbolo = partes[1]
            destino = partes[2]
            # Creamos una transición y la añadimos a la lista
            delta.append(Trans(origen, simbolo, destino))

    # Cerramos el archivo de configuración
    archivo.close()

    # Abrimos el archivo con las cadenas a evaluar
    cadena = open("cadena.txt", "r")

    # Procesamos cada línea del archivo de cadenas
    for line in cadena:
        line = line.strip()  # Eliminamos el salto de línea
        if line == "":
            w = ""  # Si la línea está vacía, la cadena es vacía
        else:
            w = line  # Si no, usamos la cadena leída

        q = estado_inicio  # Inicializamos el estado actual

        # Imprimimos la cadena actual, o ε si está vacía
        if w != "":
            print(w + " -> ", end="")
        else:
            print("ε -> ", end="")

        # ============================
        # Procesamos cada símbolo (letra) de la cadena
        # ============================
        for i in range(len(w)):
            simbolo_actual = w[i]  # Tomamos la letra i de la cadena
            transicion_encontrada = False  # Bandera para saber si encontramos transición

            # Buscamos entre todas las transiciones una válida
            for j in range(len(delta)):
                trans = delta[j]  # Tomamos la transición j

                # Si el estado actual coincide con el origen
                # y el símbolo actual coincide con el símbolo de la transición
                if q == trans.s and simbolo_actual == trans.c:
                    q = trans.t  # Cambiamos al nuevo estado
                    transicion_encontrada = True
                    break  # Salimos del bucle, ya aplicamos una transición

            # Nota: Si no hay transición válida, el autómata se queda en el estado actual

        # ============================
        # Verificamos si el estado final es de aceptación
        # ============================
        if q in estado_final:
            print("ACEPTADA")
        else:
            print("RECHAZADA")

    # Cerramos el archivo de cadenas
    cadena.close()

# Llamamos a la función principal
main()
