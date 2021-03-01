///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///             Projeto Sistema de Aluguéis de Roupas e Fantasias           ///
///            Developed by  @PedroAugustoMD and @leonardodantas4           ///
///                             Jan, 2021                                   ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void) {
    char opcao;
    do {
      opcao = menuPrincipal();
		  switch(opcao) {
			  case '1': 	moduloCliente();
						break;
			  case '2': 	moduloFantasia();
						break;
			  case '3': 	moduloAlugueis();
						break;
			  case '4': 	moduloRelatorio();
						break;
			  case '5': 	moduloInformacoes();
						break;
		} 		
	} while (opcao != '0');
	return 0; 

}
