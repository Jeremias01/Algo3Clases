#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <tuple>
#include <list>
#include <queue>

std::vector<std::vector<long long>> matriz;

bool esTemplado(std::tuple<long long,long long> orig, std::tuple<long long,long long> dest, long long sumaparc,long long paso){
    bool result;
    std::tuple<long long,long long> nuevoOrigDer=std::tuple(std::get<0>(orig) ,std::get<1>(orig)+1);
    std::tuple<long long,long long> nuevoOrigAbaj=std::tuple(std::get<0>(orig)+1,std::get<1>(orig));
    if((matriz.size()+matriz[0].size())%2==0){
        result=false;
    } else if (std::get<0>(orig)==std::get<0>(dest) && std::get<1>(orig)==std::get<1>(dest)){
        result=sumaparc+matriz[std::get<0>(dest)][std::get<1>(dest)]==0;
    } else if(std::abs(sumaparc)>static_cast<long long>(matriz[0].size()+matriz.size()-1-paso)){
        result=false;
    } else {result=(std::get<0>(orig)==static_cast<long long>(matriz.size()-1) ? esTemplado(nuevoOrigDer,dest,sumaparc+matriz[std::get<0>(orig)][std::get<1>(orig)],paso+1) : (std::get<1>(orig)==static_cast<long long>(matriz[0].size()-1)? esTemplado(nuevoOrigAbaj,dest,sumaparc+matriz[std::get<0>(orig)][std::get<1>(orig)],paso+1) : esTemplado(nuevoOrigDer,dest,sumaparc+matriz[std::get<0>(orig)][std::get<1>(orig)],paso+1) || esTemplado(nuevoOrigAbaj,dest,sumaparc+matriz[std::get<0>(orig)][std::get<1>(orig)],paso+1)));
    }
    return result;      
}


int main() {
    long long matrices;
    std::cin >> matrices;

    while (matrices>0) {
        long long n, m;
        std::cin >> n >> m;
        matrices--;

        matriz = std::vector<std::vector<long long>>(n, std::vector<long long>(m));
        for (long long i = 0; i < n; ++i)
            for (long long j = 0; j < m; ++j)
            std::cin >> matriz[i][j];

        bool result = esTemplado(std::tuple(0,0),std::tuple(n-1,m-1),0,0);
        std::cout << (result ? "YES" : "NO") << std::endl;
    }

    return 0;
}
