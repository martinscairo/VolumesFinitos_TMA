#include <Volumes.h>
#include <iostream>

//------------------------------------------------------------------------------
//                             operator <<
//------------------------------------------------------------------------------
 std :: ostream& operator << (std :: ostream& _os, const Volumes& _vol)
 {
    _os << "compri: "         << _vol.comprimento << 
            "  nVol: " << _vol.nVol << 
            "  imagemesquerda: " << _vol.imagemEsquerda 
            <<"   imagem direito:" <<_vol.imagemDireita;
    
    return _os;
    
 }
 
//------------------------------------------------------------------------------
//                            operator >> 
//------------------------------------------------------------------------------
 std :: istream& operator >> (std :: istream& _os, Volumes& _vol)
 {
     _os >> _vol.comprimento >> 
            _vol.nVol >> _vol.imagemDireita >> _vol.imagemEsquerda;
     return _os;
 }
 
 
//==============================================================================
//                        sobrecarga de operadores
//==============================================================================
 
//------------------------------------------------------------------------------
//                             operator = 
//------------------------------------------------------------------------------
 const Volumes&  Volumes :: operator= (const Volumes& _orig)
 {
     if (this != &_orig)
     {
         comprimento    = _orig.comprimento;
         imagemEsquerda = _orig.imagemEsquerda;
         imagemDireita  = _orig.imagemDireita;
         nVol           = _orig.nVol;
     }
     
     return *this;
 }