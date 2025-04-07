#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <tuple>
#include <list>
#include <queue>


bool esTemplado(std::vector<std::vector<int>> l, std::tuple<int,int> orig, std::tuple<int,int> dest, int sumaparc,int paso){
    bool result;
    if(not(l.size()%2==0)){
        result=false;
    }
    std::tuple<int,int> nuevoOrigDer=std::tuple(std::get<0>(orig)+1,std::get<1>(orig));
    std::tuple<int,int> nuevoOrigIzq=std::tuple(std::get<0>(orig),std::get<1>(orig));
    if (std::get<0>(orig)==std::get<0>(dest) && std::get<1>(orig)==std::get<0>(dest)){
        result=sumaparc==0;
    } else if(abs(sumaparc)>l[0].size()+l.size()-paso){
        result=false;
    } else {result=esTemplado(l,nuevoOrigDer,dest,sumaparc+l[std::get<0>(orig)][std::get<1>(orig)],paso+1) || esTemplado(l,nuevoOrigIzq,dest,sumaparc+l[std::get<0>(orig)][std::get<1>(orig)],paso+1);
    }
    return result;    
}


int main() {
    int t;  // Número de casos de prueba
    std::cin >> t;
    while (t--) {
        int n, m;  // Dimensiones de la grilla (n x m)
        std::cin >> n >> m;

        // Crear una matriz de n x m
        std::vector<std::vector<int>> grid(n, std::vector<int>(m));

        // Leer las filas de la grilla
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> grid[i][j];
            }
        }
        
        // Aquí podrías agregar la lógica para procesar la grilla
    }
    if (esTemplado(grid,grid[0][0],grid[grid.size()][grid[0].size()]))
    std::cout << "La suma es: " << resultado << std::endl;

    return 0;
}
