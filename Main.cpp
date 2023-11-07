#include<iostream>
#include<ctime>

class nodo{

    private: 
        int dato;
        nodo* p;

    public:
        nodo(){p = nullptr, dato = 0;}
        void setDato(int num){ dato = num; }
        void setNodo(nodo* pos){ p = pos; }
        nodo* getNodo(){ return p; }
        int getDato(){ return dato; }

};

int main(){
    int num;
    srand(static_cast<unsigned>(time(nullptr)));

    std::cout << "Generando numeros..." << std::endl;

    nodo* cabeza = nullptr;
    nodo* prev = nullptr;  

    for (size_t i = 0; i < 100; i++) {
        nodo* nuevo = new nodo;
        num = rand() % 100 + 1;
        nuevo->setDato(num);
        std::cout << "\nNumero: " << nuevo->getDato() << std::endl;
        
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        if (prev != nullptr) {
            
            prev->setNodo(nuevo);
        }
        
        prev = nuevo; 
    }
    
    nodo* actual = cabeza;
    while (actual != nullptr) {
        nodo* siguiente = actual->getNodo();
        delete actual;
        actual = siguiente;
    }
    
    return 0;
}
