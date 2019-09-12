bool TListaCalendario::Insertar(const TCalendario &c){
    bool insertado, mayor, encontrado;
    TNodoCalendario *pta, *ptl, *ptn;

    insertado = false;
    pta = NULL;
    ptl = primero;
    mayor = false;
    encontrado = false;

    while(ptl && !encontrado && !mayor){
        if(ptl->c > c){
            mayor = true;
        }
        else{
            if(ptl->c == c){
                encontrado = true;
            }
            else{
                pta = ptl;
                ptl = ptl->siguiente;
            }
        }
    }
    return insertado;
}
/*
bool TListaCalendario::Borrar(const TCalendario &c){
    bool encontrado;
    TNodoCalendario *pta, *ptl;

    pta = NULL;
    ptk = primero;
    encontrado = false;
    mayor = false;
    while(ptl && !encontrado && mayor){
        if(ptl->c == c){
            encontrado = true;
        }
        else{
            if(c < ptl->c){
                mayor = true;
            }
            else{
                pta = ptl;
                ptl = ptl->siguiente;
            }
        }
    }
    if(encontrado){
        if(pta == NULL){ //PRIMER
            primero = primero->siguiente;
            delete ptl;
        }
        else{
            if(ptl->siguiente == NULL){ //AL FINAL
                pta->siguiente = NULL;
                delete ptl;
            }
            else{ //EN MEDIO
                pta->siguiente = ptl->siguiente;
                delete ptl;
            }
        }
    }

    return encontrado;
}
*/
ostream &operator<<(ostream &os, const TListaCalendario &l){
    TNodoCalendario *ptl;
    os << "<";
    ptl = l.primero;
    while(ptl){
        os << ptl->c;
        ptl = ptl->siguiente;
        if(ptl != NULL){
            os <<  " ";
        }
    }
    os << ">";
}