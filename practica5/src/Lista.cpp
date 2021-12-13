#include <iostream>
#include <list>
using namespace std;

template <class T>
class Lista{
    private:
        list<T> l;
        typedef list<T>::iterator it;
    public:
        void comienzoLista(){ it = l.begin();} 
        void avanzarLista(){ ++it;} 
        void retrocederLista(){ --it;} 
        int tamLista(){ return l.size();}
        list<T> obtenerLista(){ return l;}
        T obtenerElementoActual(){ return *it;}
        T obtenerElementoPosicion(unsigned int pos){
            typedef list<T>::iterator it_aux = l.begin();
            for (unsigned int i = 0; i < pos; i++)
                ++it_aux;

            return *it_aux;
        }

        Lista<T> insertarElementoLista(T elem, unsigned int pos){
            typedef list<T>::iterator it_aux = l.begin();
            for (unsigned int i = 0; i < pos; i++)
                ++it_aux;

            l.insert(it_aux, elem)
            return *this;       
        }

        Lista<T> eliminarElementoPosicion(T elem, unsigned int pos){
            typedef list<T>::iterator it_aux = l.begin();
            for (unsigned int i = 0; i < pos; i++)
                ++it_aux;

            l.erase(it_aux, elem)
            return *this;       
        }

        Lista<T> eliminarElementosAPartirPosicion(T elem, unsigned int pos){
            typedef list<T>::iterator it_aux = l.begin();
            for (unsigned int i = 0; i < pos; i++)
                ++it_aux;

            while (it_aux != l.end())
                it_aux = l.erase(it_aux, elem)
                
            return *this;       
        }

        Lista<T> concatenar(Lista<T> L2){
            list<T> l2 = L2.obtenerLista();
            for (typedef list<T>::iterator it2 = l2.begin(); it2 != l2.end(); ++it2)
                l.insert(l.end(), *it2);
                
            return *this;       
        }

        Lista<T> sumar(T n){  
            for (typedef list<T>::iterator it_aux = l.begin(); it_aux != l.end(); ++it_aux)
                *it_aux += n;
                
            return *this;        
        }

        Lista<T> restar(T n){  
            for (typedef list<T>::iterator it_aux = l.begin(); it_aux != l.end(); ++it_aux)
                *it_aux -= n;
                
            return *this;        
        }

        Lista<T> multiplicar(T n){  
            for (typedef list<T>::iterator it_aux = l.begin(); it_aux != l.end(); ++it_aux)
                *it_aux *= n;
                
            return *this;        
        }

        Lista<T> dividir(T n){  
            for (typedef list<T>::iterator it_aux = l.begin(); it_aux != l.end(); ++it_aux)
                *it_aux /= n;
                
            return *this;        
        }





};