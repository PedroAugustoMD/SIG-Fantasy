#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloRelatorio.h"
#include "validacoes.h"


char menuRelatorios(void) {
  char op;
  system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =             Sig Fantasy             = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                            Developed by                               ///\n");
  printf("///            @PedroAugustoMD & @leonardodantas4 - Jan, 2021             ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///           = = = = = = = = = Menu Relatório = = = = = = = = =          ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Histórico de aluguéis                                    ///\n");
	printf("///           2. Verificar datas                                          ///\n");
	printf("///           3. Cliente mais fiel                                        ///\n");
	printf("///           4. Fantasia mais alugada                                    ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada: ");
  scanf("%c", &op);
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return op;
}


void telaHistoricoFantasia(void) {
  char cpf[12] = "13942404494";
  char id[12] = "01";
    system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =             Sig Fantasy             = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                            Developed by                               ///\n");
  printf("///            @PedroAugustoMD & @leonardodantas4 - Jan, 2021             ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///           = = = = = = = = Histórico de Fantasias = = = = = = = =      ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           Histórico de empréstimos:                                   ///\n");
  for(int i = 0; i<20;i++){
	printf("/// -------------------------                                       ///\n");
  printf("/// CPF: %s                                       ///\n",cpf);
  printf("/// ID: %s                                       ///\n",id);
	printf("/// -------------------------                                       ///\n");
 
  }
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void telaVerificarDatas(void) {
  int dia;
  int mes;
  int ano;
    system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =             Sig Fantasy             = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                            Developed by                               ///\n");
  printf("///            @PedroAugustoMD & @leonardodantas4 - Jan, 2021             ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = = = Verificar Datas = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Digite o dia: ");
  scanf("%i", &dia);
  getchar();
	printf("///           Digite o mês: ");
  scanf("%i", &mes);
  getchar();
  printf("///           Digite o ano: ");
  scanf("%i", &ano);
  getchar();
 while (validaData(dia, mes, ano) == 0){
      printf("///           Data inválida!: ");
      printf("///           Digite o dia: ");
      scanf("%i", &dia);
      getchar();
	    printf("///           Digite o mês: ");
      scanf("%i", &mes);
      getchar();
      printf("///           Digite o ano: ");
      scanf("%i", &ano);
      getchar();
   }
	printf("///                                                              ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void telaClienteFiel(void) {
    system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =             Sig Fantasy             = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                            Developed by                               ///\n");
  printf("///            @PedroAugustoMD & @leonardodantas4 - Jan, 2021             ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///           = = = = = = = = Cliente Mais Fiel = = = = = = = = = =       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           O cliente mais fiel é:                                      ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void telaFantasiaMaisAlugada(void) {
    system("clear");
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =             Sig Fantasy             = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                            Developed by                               ///\n");
  printf("///            @PedroAugustoMD & @leonardodantas4 - Jan, 2021             ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///           = = = = = = = = Fantasia Mais Alugada = = = = = = = =       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           A fantasia mais alugada é:                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void moduloRelatorio(void) {
	char opcao;
  do {
		opcao = menuRelatorios();
		switch(opcao) {
			case '1': 	telaHistoricoFantasia();
						break;
			case '2': 	telaVerificarDatas();
						break;
			case '3': 	telaClienteFiel();
						break;
			case '4': 	telaFantasiaMaisAlugada();
						break;
		} 		
	} while (opcao != '0');

}