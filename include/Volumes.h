//==============================================================================
// Name        : Volumes.h
// Author      : Cairo Martins e Leonardo Thimoteo
// Version     : 1.0
// Description : Classe que define elementos de volumes
// Status      : Needs verification
//==============================================================================

#ifndef VOLUMES_H
#define VOLUMES_H

//==============================================================================
//                              C++ Includes
//==============================================================================
#include <iostream>

//==============================================================================
//                              typedefs
//==============================================================================
typedef double                     Real;

//==============================================================================
//                                 class
//==============================================================================

class Volumes {
    
//------------------------------------------------------------------------------
//                           Friend functions
//------------------------------------------------------------------------------
    //! Sobrecarga do operador << para impressão
    friend std :: ostream& operator << (std :: ostream&, const Volumes&);
    
    //! Sobrecarga do operador >> para obtenção de valores
    friend std :: istream& operator >> (std :: istream&, Volumes&);
    
    
    
    
public:

//------------------------------------------------------------------------------
//                           constructors e destructor
//------------------------------------------------------------------------------  
    
    //! Construtora default.
    Volumes() :                     comprimento (0), 
                                    nVol(0), 
                                    imagemEsquerda (0), 
                                    imagemDireita(0) {};
   
                                    
   //! Construtora de cópia
   Volumes(const Volumes& _orig):   comprimento (_orig.comprimento),
                                    nVol (_orig.nVol), 
                                    imagemEsquerda (_orig.imagemEsquerda), 
                                    imagemDireita(_orig.imagemDireita) {};
                                    
   //! Construtora específica a partir do fornecimento de todos parâmetros                                  
   Volumes (const Real& _comp, const int& _nvol, const Real& _imgesq, 
            const Real& _imgdir) : comprimento (_comp), 
                                    nVol (_nvol), 
                                    imagemEsquerda (_imgesq), 
                                    imagemDireita (_imgdir) {};
    

    //! Destrutora               
    virtual ~Volumes() {};
 
//------------------------------------------------------------------------------
//                          sobrecarga de operadores
//------------------------------------------------------------------------------  
    //! Sobrecarga do operador =..
/*!
  \param _orig Variável tipo GeoMap1D a ser copiada.
*/    
const Volumes& operator= (const Volumes& _orig);

//------------------------------------------------------------------------------
//                            funções inline  
//------------------------------------------------------------------------------    

//! Função que retorna o comprimento do intervalo de domínio.
    inline  const Real  COMPRIMENTO() const {return comprimento;};
 
//! Função que retorna o número de volumes no intervalo.
    inline  const int   NVOL() const {return nVol;};
    
//! Função que retorna o valor da imagem esquerda do volume periférico inicial.
    inline  const Real  IMGESQUERDA() const {return imagemEsquerda;};
    
//! Função que retorna o valor da imagem do volume periférico final.
    inline  const Real  IMGDIREITA() const {return imagemDireita;};
    
    
    
    
private:
    
    Real  comprimento,       //!Comprimento do intervalo de domínio 
          imagemEsquerda,    //!Imagem do volume periférico à esquerda 
          imagemDireita;     //!Imagem do volume periférico à direita 
    
    int   nVol;              //!Número de volumes discretizados do domínio
            

};

#endif /* VOLUMES_H */

