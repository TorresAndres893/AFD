#include <stdio.h>   // Incluye funciones de entrada/salida estándar
#include <string.h>  // Incluye funciones para manipulación de cadenas

#define MAX 100  // Define el tamaño máximo para cadenas y arreglos

// Define la estructura para las transiciones del autómata
typedef struct {
    char s[10], c, t[10];  // s: estado de inicio, c: símbolo, t: estado final
} Trans;

int main(int argc, char *argv[]){
    
    FILE *archivo;
    
    archivo = fopen("conf.txt","r");
    printf(s);
    	  
    // Variables para almacenar los componentes del autómata
    char line[MAX];
    char estados[MAX], alfabeto[MAX], estado_inicio[10], estado_final[MAX];
    
    // Lee y procesa la línea de estados
    fgets(line,MAX,archivo); sscanf(line,"estados=%s",estados);
    // Lee y procesa la línea del alfabeto
    fgets(line,MAX,archivo); sscanf(line,"alfabeto=%s",alfabeto);
    // Lee y procesa la línea del estado inicial
    fgets(line,MAX,archivo); sscanf(line,"estado_inicio=%s",estado_inicio);
    // Lee y procesa la línea de estados de aceptación
    fgets(line,MAX,archivo); sscanf(line,"estado_final=%s",estado_final);

    // Arreglo para almacenar las transiciones
    Trans delta[100]; int n=0;  // n: contador de transiciones
    
    // Lee todas las transiciones del archivo
    while(fgets(line,MAX,archivo)){
        // Parsea cada línea en estado origen, símbolo y estado destino
        sscanf(line,"%[^,],%c,%s",delta[n].s,&delta[n].c,delta[n].t);
        n++;  // Incrementa el contador de transiciones
    }
    fclose(archivo);  // Cierra el archivo del autómata

    // Abre el archivo de palabras para probar
    FILE *cadena;
    cadena = fopen("cadena.txt","r");
    // Procesa cada palabra del archivo
    while(fgets(line,MAX,cadena)){
        // Elimina el salto de línea al final de la cadena
        line[strcspn(line,"\n")] = 0;
        char *w=line;  // Puntero a la palabra actual
        
        // Maneja el caso especial de la cadena vacía 
        if(strcmp(w,"")==0) w="";
        
        char q[10];  // Estado actual del autómata
        strcpy(q,estado_inicio);  // Inicializa con el estado inicial
        
        // Imprime la palabra que se está procesando
        printf("%s -> ", (*line)?line:"ε");
        
        // Procesa cada símbolo de la palabra
        for(int i=0; w[i]; i++){
            // Busca una transición válida para el estado actual y símbolo actual
            for(int j=0;j<n;j++)
                if(strcmp(q,delta[j].s)==0 && w[i]==delta[j].c){
                    strcpy(q,delta[j].t);  // Actualiza el estado actual
                    break;  // Sale del bucle una vez encontrada la transición
                }
        }
        
        // Verifica si el estado final es de aceptación
        if(strstr(estado_final,q))
            printf("ACEPTADA\n");  // La palabra es aceptada
        else
            printf("RECHAZADA\n");  // La palabra es rechazada
    }
    fclose(cadena);  // Cierra el archivo de palabras
    return 0;  // Termina el programa exitosamente
}
