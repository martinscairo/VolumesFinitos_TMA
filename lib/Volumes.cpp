#include <Volumes.h>
#include <iostream>

//------------------------------------------------------------------------------
//                           Funções Friend
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//                             Operator <<
//------------------------------------------------------------------------------
 std :: ostream& operator << (std :: ostream& _os, const Volumes& _vol)
 {
    _os << "Comprimento: "         << _vol.comprimento 
        << "  número de volumes: " << _vol.nVol
        << "  Imagem Esquerda: "   << _vol.imagemEsquerda 
        <<"   imagem direita: "    << _vol.imagemDireita
        << "Xface: "               << _vol.xFace;
    
    return _os;
    
 }
 
//------------------------------------------------------------------------------
//                            Operator >> 
//------------------------------------------------------------------------------
 std :: istream& operator >> (std :: istream& _os, Volumes& _vol)
 {
     _os >> _vol.comprimento >> 
            _vol.nVol >> _vol.imagemDireita >> _vol.imagemEsquerda >> 
            _vol.xFace;
     
     return _os;
 }
 
 
//==============================================================================
//                        Sobrecarga de Operadores
//==============================================================================
 
//------------------------------------------------------------------------------
//                             Operator = 
//------------------------------------------------------------------------------
 const Volumes&  Volumes :: operator= (const Volumes& _orig)
 {
     if (this != &_orig)
     {
         comprimento    = _orig.comprimento;
         imagemEsquerda = _orig.imagemEsquerda;
         imagemDireita  = _orig.imagemDireita;
         nVol           = _orig.nVol;
         xFace          = _orig.xFace;
     }
     
     return *this;
 }