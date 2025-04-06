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

bool pertenece(std::list<std::tuple<int,int,int>> l,int e){
    bool result=false;
    for (std::tuple<int,int,int> i:l){
        if (std::get<2>(i)==e){
            result=true;
        }   }
    return result;
    };

std::list<std::tuple<int,int,int>> bfsMinimosCaminos(Grafo gr, int orig, int dest){
    std::list<std::tuple<int,int,int>> visit={};
    std::queue<std::tuple<int,int,int>> q;
    q.push(std::tuple(0,orig,orig));
    bool ultimoNivel=false;
    int nivel=0;
    while (not q.empty()){
        std::tuple<int,int,int> vtup=q.front();
        int v=std::get<2>(vtup);
        int nivelAct=std::get<0>(vtup)+1;
        if (not (nivel==nivelAct)){
            visit.push_front(vtup);
        }
        for (int i:gr.Vecinos(v)){
            if ((not (pertenece(visit,i))) && (not ultimoNivel)){
                q.push(std::tuple(nivelAct,v,i));
            }
        }
        if (v==dest){
            ultimoNivel=true;
            nivel = nivelAct;
        }
    }
    return visit;
};



int main() {
    return 0;
}
