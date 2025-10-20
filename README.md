# Proyecto_Programación
Lo que realiza este proyecto es un ordenamiento y filtrado de datos a través de algoritmos y estructuras.
Con ello realizamos un buscador que se enfoca en modificar una base de datos desordenada para mantener un seguimiento acordado a lo necesitado.

## SICT0301: Evalúa los componentes

Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

En el programa que usamos de Registros_clima, usamos el algoritmo de Insertion Sort para ordenar los factores de nuestro CSV.
Dichos factores eran: Fecha, TempMax, Tempmin, Humedad, Tipo de Clima.

### Complejidad temporal:
En su peor caso ,los datos estarían completamente desordenados, usando complejidad O(n²).
En el mejor caso, cuando los datos ya están ordenados, la complejidad es O(n).

### Swapfila
La función swapfila asegura que todas las columnas asociadas a un registro se muevan juntas, garantizando la integridad de los datos.
Aunque cada intercambio mueve varias columnas, la complejidad asintótica del algoritmo no se ve afectada.

### Función de agregación y eliminación 
Función de agregación para manejar valores dentro de los vectores en un csv. 
Función de eliminación para eliminar valores dentro de los vectores. Organizar un archivo csv
mediante los datos y acciones dentro del stack.
## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

La elección de dicho algoritmo de ordenamiento fue por lo siguiente:

#### Número de registros pequeño:
Manejamos un archivo de datos de tamaño reducido, por lo que la eficiencia que podríamos tener para el peor caso en este algoritmo, es muy díficil que exista. Por lo que no
representa un problema de rendimiento.

#### Simplicidad de implementación:
Insertion sort nos permite un control simpley directo con los intercambios de valores. En este caso se usó el intercambio para las filas. Así mantenemos la coherencia
de los datos ordenados con las demás columnas.

### Selecciona y usa una estructura lineal adecuada al problema

Se usó el stack para la simplicidad y eficiencia que maneja para agregar y eliminar objetos. Incluso de puede implementar en un futuro el uso de algoritmos para manejar búsquedas en cuanto al desarrollo y formato de la estructura lineal.

## SICT0303B: Implementa acciones Científicas.
### Implementa Mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa. 
El programa tiene la opción de agregar o eliminar registros de clima mediante el uso de estructuras lineales. Mediante el uso del menú dinámico manejamos las opciones. 
### Implementamos mecanismos de lectura de archivos correctos y útiles dentro de un programa.
Los registros están almacenados en el archivo registro_clima.csv de donde se leen al iniciar el programa

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. 
Los registros agregados se guardan al final del archivo registros_clima.csv, con la función agrega, la cual agrega nuevo registro. No deben ser recapturados cada vez que se corre el programa.

## Alternativas:
En el caso que usáramos archivos de datos significativamente grandes, sería recomendar implementar otro tipo de ordenamiento. 
Como MergeSort, debido a su complejidad.

El algoritmo seleccionado cumple con los requisitos del programa y es eficiente para el tamaño de los archivos CSV manejados.

La elección está justificada por la necesidad de mantener filas completas sincronizadas, la facilidad de implementación y la adecuación al número de registros.

### Extras

Se utilizó la librería de vector para realizar diferentes acciones. La primera es el uso de stod. Que es convertir un string a double. Posteriormente se utilizó el push_back.
Dicha función cumple con el acometido de agregar elementos a un vector al final del mismo.
