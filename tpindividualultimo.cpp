#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <tuple>
#include <list>
#include <queue>


bool esTemplado(std::vector<std::vector<long long>> l, std::tuple<long long,long long> orig, std::tuple<long long,long long> dest, long long sumaparc,long long paso){
    bool result;
    std::tuple<long long,long long> nuevoOrigDer=std::tuple(std::get<0>(orig) ,std::get<1>(orig)+1);
    std::tuple<long long,long long> nuevoOrigAbaj=std::tuple(std::get<0>(orig)+1,std::get<1>(orig));
    if((l.size()+l[0].size())%2==0){
        result=false;
    } else if (std::get<0>(orig)==std::get<0>(dest) && std::get<1>(orig)==std::get<1>(dest)){
        result=sumaparc+l[std::get<0>(dest)][std::get<1>(dest)]==0;
    } else if(std::abs(sumaparc)>static_cast<long long>(l[0].size()+l.size()-1-paso)){
        result=false;
    } else {result=(std::get<0>(orig)==static_cast<long long>(l.size()-1) ? esTemplado(l,nuevoOrigDer,dest,sumaparc+l[std::get<0>(orig)][std::get<1>(orig)],paso+1) : (std::get<1>(orig)==static_cast<long long>(l[0].size()-1)? esTemplado(l,nuevoOrigAbaj,dest,sumaparc+l[std::get<0>(orig)][std::get<1>(orig)],paso+1) : esTemplado(l,nuevoOrigDer,dest,sumaparc+l[std::get<0>(orig)][std::get<1>(orig)],paso+1) || esTemplado(l,nuevoOrigAbaj,dest,sumaparc+l[std::get<0>(orig)][std::get<1>(orig)],paso+1)));
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

        std::vector<std::vector<long long>> matriz(n, std::vector<long long>(m));
        for (long long i = 0; i < n; ++i)
            for (long long j = 0; j < m; ++j)
            std::cin >> matriz[i][j];

        bool result = esTemplado(matriz,std::tuple(0,0),std::tuple(n-1,m-1),0,0);
        std::cout << (result ? "YES" : "NO") << std::endl;
    }

    return 0;
}
