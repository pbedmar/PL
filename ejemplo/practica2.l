%option noyywrap

%{
    #include <iostream>
    #include <fstream>
    #include <map>
    #include <string>
    
    using namespace std;

    int num_pet, aciertos_totales, errores_totales;
    ifstream fichero;
    string ip_activa = "";

    struct datos{
        int peticiones = 0;
        int errores = 0;
        int aciertos = 0;
    };

    map<string,datos> data;

    void escribir_datos();
%}


PIP3D1 1[0-9][0-9]
PIP3D2 2[0-4][0-9] 
PIP3D25 25[0-5]

PIP2D [1-9][0-9]
PIP1D [0-9]

EXITO 2[0-9][0-9]
ERROR [4-5][0-9][0-9]
HEADER "HTTP/1."[0-1]"\" "

RANGOIP {PIP3D1}|{PIP3D2}|{PIP3D25}|{PIP2D}|{PIP1D}

IP {RANGOIP}"."{RANGOIP}"."{RANGOIP}"."{RANGOIP}" - -"


%%


{IP} {
    ip_activa= YYText(); 
    ip_activa = ip_activa.substr(0,ip_activa.size()-4);
    if(data.find(ip_activa) == data.end()){
        datos d;
        data.insert({ip_activa,d});
        data[ip_activa].peticiones++;
    }else{
        data[ip_activa].peticiones++;
    }  
    num_pet++;  
}   
{HEADER}{EXITO} {
    if(data.find(ip_activa) != data.end()) 
        data[ip_activa].aciertos++;

}
{HEADER}{ERROR} {
    if(data.find(ip_activa) != data.end())
        data[ip_activa].errores++;
}
. {}

%%


    int main (int argc, char *argv[]){
        if(argc == 2){
            fichero.open(argv[1]);
            if(!fichero.is_open()){
                cout << "error de la lectura" << endl;
                exit(1);
            }
        } else exit(1);

        num_pet = aciertos_totales = errores_totales = 0;

        yyFlexLexer flujo (&fichero,0);
        flujo.yylex();
        escribir_datos();

        return 0;
    }

    void escribir_datos(){
        map<string,datos>::const_iterator cit = data.cbegin();

        for(cit; cit != data.cend(); ++cit){
            cout << "La IP " << cit->first << " ha realizado:\n";
            cout << "\t" << cit->second.peticiones << " peticiones\n";
            cout << "\t" <<  ((float) cit->second.aciertos / cit->second.peticiones)*100 << "% han sido exitosas\n";
            cout << "\t" <<  ((float)cit->second.errores / cit->second.peticiones)*100 << "% han sido erroneas\n";
            aciertos_totales += cit->second.aciertos;
            errores_totales += cit->second.errores;
        }
        cout << "Me han llegado " << num_pet << " peticiones de " << data.size() << " IPs\n";
        cout << "\tTasa de aciertos " << ((float)aciertos_totales/num_pet)*100 << "%\n";
        cout << "\tTasa de errores " << ((float)errores_totales/num_pet)*100 << "%\n";
    }
