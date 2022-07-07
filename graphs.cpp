#include <iostream>
using namespace std;

typedef int tVertice;

#define NOVISITADO 0
#define VISITADO 1


class tGrafo {

    // constructor que inicializa el grafo para n vertices
    tGrafo(int n);
    
    // retorna el número de vértices en el grafo
    int nVertex();

    // retorna el número de arcos en el grafo
    int nEdges();

    // Devuelve el primer vecino de un vértice v dado (asume que los vecinos de un vértice
    // están ordenados por número de vértice)
    tVertice first(tVertice v);

    // Devuelve el menor vecino de v, cuya numeración es mayor a w.
    // Si no existe dicho vecino, retorna el número de vértices del grafo
    tVertice next(tVertice v, tVertice w);

    // agrega un nuevo arco al grafo entre vértices v1 y v2 (no se pueden
    // agregar nuevos vértices)
    void setEdge(tVertice v1, tVertice v2, int peso);

    // borra un arco existente entre vértices v1 y v2
    void deleteEdge(tVertice v1, tVertice v2);

    // dados dos vértices, indica si existe un arco entre ellos
    int isEdge(tVertice v1, tVertice v2);

    // devuelve el peso de un arco del grafo (0 si no existe)
    int weight(tVertice v1, tVertice v2);

    // obtiene la marca asignada a un vértice dado (ciertos algoritmos
    // necesitan marcar los vértices)
    int getMark (tVertice v);

    // marca un vértice con un valor dado
    void setMark(tVertice v, int marca);

    void recorrerGrafo(tGrafo& G) {
        tVertice v;
        for(v = 0; v < G.nVertex(); v++) 
            G.setMark(v, NOVISITADO);
        
        for(v = 0; v < G.nVertex(); v++)
            if (G.getMark(v) == NOVISITADO)
                visitar(G, v);  // operación a realizar, marca el vértice 
    }

    void DFS(tGrafo& G, tVertice v) {
        tVertice w;
        visitar(G, v);
        G.setMark(v, VISITADO);

        for (w = G.first(v); w < G.nVertex(); w = G.next(v, w))
            if (G.getMark(w) == NOVISITADO)
                DFS(G, w);
    }




}