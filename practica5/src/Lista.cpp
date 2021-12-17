#include <iostream>
#include <list>
#include <cstring>
using namespace std;

template <class T>
class Lista{
    private:
        list<T> l;
        typename list<T>::iterator it;
    public:
        void comienzoLista(){ it = l.begin();} 
        void avanzarLista(){ ++it;} 
        void retrocederLista(){ --it;} 
        int tamLista(){ return l.size();}
        list<T> obtenerLista(){ return l;}
        T obtenerElementoActual(){ return *it;}
        T obtenerElementoPosicion(unsigned int pos){
            typename list<T>::iterator it_aux = l.begin();
            for (unsigned int i = 0; i < pos; i++)
                ++it_aux;

            return *it_aux;
        }

        Lista<T> insertarElementoLista(T elem, unsigned int pos){
            typename list<T>::iterator it_aux = l.begin();
            for (unsigned int i = 0; i < pos; i++)
                ++it_aux;

            l.insert(it_aux, elem);
            return *this;       
        }

        Lista<T>& operator=(const Lista<T>& other) {
            this->l = other.l;
            this->it = other.it;
            return *this;
        }

        Lista<T> eliminarElementoPosicion(unsigned int pos){
            typename list<T>::iterator it_aux = l.begin();
            for (unsigned int i = 0; i < pos; i++)
                ++it_aux;

            l.erase(it_aux);
            return *this;       
        }

        Lista<T> eliminarListaAPartirPosicion(unsigned int pos){
            typename list<T>::iterator it_aux = l.begin();
            for (unsigned int i = 0; i < pos; i++)
                ++it_aux;

            while (it_aux != l.end())
                it_aux = l.erase(it_aux);
                
            return *this;       
        }

        Lista<T> concatenarListas(Lista<T> L2){
            list<T> l2 = L2.obtenerLista();
            for (typename list<T>::iterator it2 = l2.begin(); it2 != l2.end(); ++it2)
                l.insert(l.end(), *it2);
                
            return *this;       
        }

        Lista<T> sumar(T n){  
            for (typename list<T>::iterator it_aux = l.begin(); it_aux != l.end(); ++it_aux)
                *it_aux += n;
                
            return *this;        
        }

        Lista<T> restar(T n){  
            for (typename list<T>::iterator it_aux = l.begin(); it_aux != l.end(); ++it_aux)
                *it_aux -= n;
                
            return *this;        
        }

        Lista<T> multiplicar(T n){ 
            Lista<T> auxList; 
            for (typename list<T>::iterator it_aux = this->l.begin(); it_aux != this->l.end(); ++it_aux){
                int num = *it_aux * n;

                auxList.l.push_back(num);
            }

                
            return auxList;        
        }

        Lista<T> dividir(T n){  
            for (typename list<T>::iterator it_aux = l.begin(); it_aux != l.end(); ++it_aux)
                *it_aux /= n;
                
            return *this;        
        }

        string imprimirLista(){
            string resultado = "[";
            for (typename list<T>::iterator it_aux = l.begin(); it_aux != l.end(); ++it_aux){
                if(typeid(*it_aux) == typeid(char))
                    resultado +=  *it_aux;
                else
                    resultado +=  to_string(*it_aux);
                if(it_aux != --(l.end()))
                    resultado += ",";
            }
            
            resultado += "]";

            return resultado;
        }
};