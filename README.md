# Cheapest flight finder

Find the cheapest flight based on input data

## Implementación actual de dijkstra

- Lista de adyacencia
- Cola de prioridad
- Origen de datos de un archivo csv

## Breve explicación de dijkstra

El algoritmo dijkstra recibe un nodo base el cual se toma como punto de inicio para desde ese lugar a todos los nodos la ruta más corta.

La implementación actual como se mencionó anteriormente usa una cola para tener un registro de los nodos procesados, esto haciendo uso del un ciclo que valide mientras la cola esta llena.

Posteriomente se necesita contar sobre todas las conexiones para ver cual posee el camino más corte desde el punto de origin hasta el nodo actual en una segundo iteración.

Dentro de la misma iteración se aplica la condifición, si la distancia hacia el nodo destino es mayor que la que estoy evaluando actualmente, actualizo la distancia en mi arraglo de distancias.

## Tiempos de ejecución

con 50,000 rutas:

- Versión serial: 0.0007
- Versión paralela: 0.009

con más de 1,000,000 rutas:

- Versión serial: 1.70
- Versión paralela: 0.40

## Elección del algoritmo

Entre las posibles opciones de algoritmos estuvieron

- Floyd-Warshall
- Bellman–Ford
- Dijkstra

En los criterios de selección, se seleccionó dikstra debido a que es apliamente conocido y usando,
en este tipo de problemas por estar entre los más faciles de implementar con mejor rendimiento,
posee un tiempo de ejecucion O(n<sup>2</sup>)

Los demás algoritmos permiten usar pesos negativos y actualmente para este proyecto no se necesita ese requisito.
