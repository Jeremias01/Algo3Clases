#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <tuple>
#include <list>
#include <queue>

struct Grafo{
    std::vector<std::list<int>> adyacencias = {};
    Grafo(std::set<int> vertices, std::set<std::tuple<int,int>> aristas){
    for (int v : vertices) {
        adyacencias.push_back({});
    }
    for (std::tuple<int,int> a:aristas){
        adyacencias[std::get<0>(a)].push_front(std::get<1>(a));
        adyacencias[std::get<1>(a)].push_front(std::get<0>(a));
    }   }

    std::list<int> Vecinos(int v){
        return adyacencias[v];
    }
};

bool pertenece(std::list<int> l,int e){
    bool result=false;
    for (int i:l){
        if (i==e){
            result=true;
        }   }
    return result;
    };

std::list<int> bfs(Grafo gr, int orig, int dest){
    std::list<int> visit={};
    std::queue<int> q;
    while (not q.empty()){
        int v=q.front();
        for (int i:gr.Vecinos(v)){
            if (not pertenece(visit,i)){
                q.push(i);
            }
        }
    }
    return visit;
};



int main() {
    return 0;
}
