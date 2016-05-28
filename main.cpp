//==============================================================================
// Name        : main.cpp
// Author      : Cairo Martins e Leonardo Thimoteo
// Version     : 1.0
// Description : Program to develop the finite volumes method
// Status      : Needs verification
//==============================================================================


//==============================================================================
//                              C++ Includes 
//==============================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


//==============================================================================
//                              other Includes 
//==============================================================================


//==============================================================================
//                               Own includes 
//==============================================================================
#include <Volumes.h>

//==============================================================================
//                                typedefs
//==============================================================================
//    typedef std :: vector <Real>                Ap, Ae, Aw, Sp;

//==============================================================================
//                                prototypes
//==============================================================================
Real CalculaDistFaces (Volumes&);
void print (Real x[], const int &, const std::string&); 
void CompletaDiagPrinc (Volumes&, Real x[], const int&);
void CompletaDiagLeste (Volumes&, Real x[], const int&);
void CompletaDiagOeste (Volumes&, Real x[], const int&);
void CompletaVetorSolucao (Volumes&, Real x[], const int&);
std::string RetornaNome (std :: string&);

//==============================================================================
//                              main function
//==============================================================================

int main(int argc, char** argv) {
    
//------------------------------------------------------------------------------
//                 Leitura do arquivo de configuracao Volumes.txt
//------------------------------------------------------------------------------
           
    std :: ifstream input("Volumes.txt"); //PRECISA EXISTIR
        
   
    if (!input){
        std :: cerr << "Arquivo inexistente" << std :: endl;
        exit (EXIT_FAILURE);
    }
//------------------------------------------------------------------------------
//                    Assimilando dados do arquivo externo
//------------------------------------------------------------------------------
    Volumes v1;
    input >> v1;      //importanto arquivos de dados
    input.close();    //fechando arquivo de dados
    
//------------------------------------------------------------------------------
//                             Calculando distâncias
//------------------------------------------------------------------------------    
    
    Real DistVolumes,  //distância entre volumes adjacentes
         DistCentros;  //distância entre os centros de volumes adjacentes
    
    DistVolumes = CalculaDistFaces (v1);
    DistCentros = DistVolumes;         
//volumes homogêneos fazem com quea as duas distâncias em questão sejam iguais
 
 
//------------------------------------------------------------------------------
//                             Declarando vetores
//------------------------------------------------------------------------------
    Real *Ap, *Ae, *Aw, *Sp;  //declaração de ponteiros
     
    Ap = new Real [v1.NVOL()]; //DIAGONAL PRINCIPAL, CONTENDO DE REAIS
    Ae = new Real [v1.NVOL()]; //DIAGONAL LESTE,     CONTENDO DE REAIS
    Aw = new Real [v1.NVOL()]; //DIAGONAL OESTE,     CONTENDO DE REAIS
    Sp = new Real [v1.NVOL()]; //VETOR DE SOLUÇÃO,   CONTENDO DE REAIS
    
//------------------------------------------------------------------------------
//                            Completando vetores
//------------------------------------------------------------------------------
    
//______________ 1. completando vetores diagonal principal______________________   
    
    std:: cout << "Imprimindo vetor da diagonal principal" << std :: endl;    
    CompletaDiagPrinc (v1, Ap, v1.NVOL());
    std :: string NOMEVETOR("Ap"); //define variável do tipo string, 
    //que auxiliará na impressão do vetor, contendo o seu nome
    print (Ap, v1.NVOL(), RetornaNome (NOMEVETOR));
    
        
//_________________2. completando vetores diagonal oeste________________________
    
   std:: cout << "\n\nImprimindo vetor da diagonal oeste" << std :: endl;    
   CompletaDiagOeste (v1, Aw, v1.NVOL());
   NOMEVETOR.erase(1,2);
   NOMEVETOR="Aw";
   print (Aw, v1.NVOL(), RetornaNome (NOMEVETOR));


//_______________3. completando vetores diagonal leste__________________________
   
   std:: cout << "\n\nImprimindo vetor da diagonal leste" << std :: endl;         
   CompletaDiagLeste (v1, Ae, v1.NVOL());
   NOMEVETOR.erase(1,2);
   NOMEVETOR="Ae";
   print (Ae, v1.NVOL(), RetornaNome (NOMEVETOR));


//___________________4. completando vetores resultados__________________________   
   
   std:: cout << "\n\nImprimindo vetor de resultados" << std :: endl;         
   CompletaVetorSolucao (v1, Sp, v1.NVOL());
   NOMEVETOR.erase(1,2);
   NOMEVETOR="Sp";
   print (Sp, v1.NVOL(), RetornaNome (NOMEVETOR));
    

//------------------------------------------------------------------------------
//                   Deletando memória alocada pelos vetores
//------------------------------------------------------------------------------
    delete [] Ap;
    delete [] Ae;
    delete [] Aw;
    delete [] Sp;
    
    
}


//==============================================================================
//                           funções auxiliares
//==============================================================================

//------------------------------------------------------------------------------
//                1. Calculando distância entre volumes adjacentes
//------------------------------------------------------------------------------
Real CalculaDistFaces (Volumes& _vol)
{
    return _vol.COMPRIMENTO()/_vol.NVOL();
}

//------------------------------------------------------------------------------
//                2. Completando vetor da diagonal principal
//------------------------------------------------------------------------------
void CompletaDiagPrinc (Volumes& _vol, Real x[], const int& _a)
{
    for (int i=0; i<_a; i++)
    {
        if (i==0 || i== _a-1)  x[i]=3;
        else x[i]=2;
    }
}    

//------------------------------------------------------------------------------
//                3. Completando vetor da diagonal Oeste
//------------------------------------------------------------------------------
void CompletaDiagOeste (Volumes& _vol, Real x[], const int& _a)
{

    for (int i=0; i<_a; i++)
    {
        if (i==0) x[i]=0;
        else x[i]=-1;
    }
}

//------------------------------------------------------------------------------
//                4. Completando vetores da diagonal leste
//------------------------------------------------------------------------------
void CompletaDiagLeste (Volumes& _vol, Real x[], const int& _a)
{

    for (int i=0; i<_a; i++)
    {
        if (i==_a-1) x[i]=0;
        else x[i]=-1;
    }
}

//------------------------------------------------------------------------------
//                     5. Completando vetor solução
//------------------------------------------------------------------------------
void CompletaVetorSolucao(Volumes& _vol, Real x[], const int& _a)
{
    for (int i=0; i<_a; i++)
    {
        if(i==0) x[i]=2*_vol.IMGESQUERDA();
        else if (i==_a-1) x[i]=2*_vol.IMGDIREITA();
        else x[i]=0;
    }
}

//------------------------------------------------------------------------------
//                     6. Função para impressão de vetores
//------------------------------------------------------------------------------
    void print (Real x[], int const & _a, const std:: string & _nome) 
    {
       for (int i=0; i<_a; i++)
       {
           std::cout << _nome << "[" <<i << "]="  << x[i] << std::endl;
       }
    }
    
    
//------------------------------------------------------------------------------
//                       7. Obtendo nome dos vetores
//------------------------------------------------------------------------------    
  std:: string RetornaNome (std :: string& _nome)
  {
       return _nome;
  }