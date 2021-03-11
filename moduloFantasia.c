#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloFantasia.h"
#include "validacoes.h"


char menuFantasia(void) {
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
	printf("///           = = = = = = = = = Menu Fantasia = = = = = = = = =           ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar uma nova fantasia                              ///\n");
	printf("///           2. Pesquisar uma fantasia                                   ///\n");
	printf("///           3. Atualizar o cadastro de uma fantasia                     ///\n");
	printf("///           4. Excluir uma fantasia do sistema                          ///\n");
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

void telaCadastrarFantasia(void) {
    char id[12];
	  char nome[52];
	  float valor;
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
	printf("///           = = = = = = = = Cadastrar Fantasia = = = = = = = =          ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           ID (Apenas números!): ");
  scanf("%[^\n]", id);
  getchar();
  do {
	    printf("///           ID (Apenas números!): ");
        scanf("%[^\n]", id);
	    getchar();
    } while (!validaID(id));
	printf("///           Nome da fantasia: ");
  scanf("%[^\n]", nome);
  getchar();
    do {
	    printf("///           Nome da fantasia: ");
        scanf("%[^\n]", nome);
	    getchar();
    } while (!validarNome(nome));
	printf("///           Valor do aluguel: ");
  scanf("%f", &valor);
  getchar();
    do {
	    printf("///           Valor do aluguel: ");
        scanf("%f", &valor);
	    getchar();
    } while (!validaValor(valor));
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void telaPesquisarFantasia(void) {
    char id[12];
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
	printf("///           = = = = = = = = Pesquisar Fantasia = = = = = = = =          ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           ID: ");
  scanf("%[0-9]", id);
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void telaAtualizarFantasia(void) {
    char id[12];
    char item[6];
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
	printf("///           = = = = = = = = Atualizar Fantasia = = = = = = = =          ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           Digite o ID da fantasia: ");
  scanf("%[0-9]", id);
  getchar();
	printf("///           Digite o item a ser atualizado: ");
  scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", item);
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void telaExcluirFantasia(void) {
    char id[12];
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
	printf("///           = = = = = = = = Excluir Fantasia = = = = = = = =            ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           ID: ");
  scanf("%[0-9]", id);
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void moduloFantasia(void) {
	char opcao;
  do {
		opcao = menuFantasia();
		switch(opcao) {
			case '1': 	telaCadastrarFantasia();
						break;
			case '2': 	telaPesquisarFantasia();
						break;
			case '3': 	telaAtualizarFantasia();
						break;
			case '4': 	telaExcluirFantasia();
						break;
		} 		
	} while (opcao != '0');

}