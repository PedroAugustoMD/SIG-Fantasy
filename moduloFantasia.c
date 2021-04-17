#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloFantasia.h"
#include "validacoes.h"
#include "moduloCliente.h"

typedef struct fantasia Fantasia;

void moduloFantasia(void) {
	char opcao;
  do {
		opcao = menuFantasia();
		switch(opcao) {
			case '1': 	cadastrarFantasia();
						break;
			case '2': 	pesquisarFantasia();
						break;
			case '3': 	telaAtualizarFantasia();
						break;
			case '4': 	telaExcluirFantasia();
						break;
		} 		
	} while (opcao != '0');

}

void cadastrarFantasia(void) {
  Fantasia *fant;
  fant = telaCadastrarFantasia();
  gravarFantasia(fant);
  free(fant);
}

void pesquisarFantasia(void) {
  Fantasia *fant;
  char* id;
	id = telaPesquisarFantasia();
  fant = buscarFantasia(id);
  exibirFantasia(fant);
  free(fant); 
  free(id);
}




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

Fantasia* telaCadastrarFantasia(void) {
  Fantasia *fant;
  limpaTela();
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
  fant = (Fantasia*) malloc(sizeof(Fantasia));
	printf("///           ID (Apenas números!): ");
  scanf("%[^\n]", fant->idFantasia);
  getchar();
while (validaID(fant->idFantasia) == 0){
      printf("///           ID inválido!: ");
        scanf("%[^\n]", fant->idFantasia);
	    getchar();
   }
	printf("///           Nome da fantasia: ");
  scanf("%[^\n]", fant->nomeFantasia);
  getchar();
    while (validarNome(fant->nomeFantasia) == 0){
      printf("///           Nome inválido!: ");
        scanf("%[^\n]", fant->nomeFantasia);
	    getchar();
   }
	printf("///           Valor do aluguel: ");
  scanf("%f", &fant->valor);
  getchar();
  while (validaVALOR(fant->valor) == 0){
      printf("///           Valor inválido!: ");
        scanf("%f", &fant->valor);
	    getchar();
   }
   fant->status = 'D';
   fant->quantidadeAlugueis = 0;
   fant->statusCadastro = 'C';
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return fant;
}

void gravarFantasia(Fantasia* fant) {
  FILE* fp;

  fp = fopen("fantasias.dat", "ab");
  if (fp == NULL) {
    telaErroArquivo();
  }
  fwrite(fant, sizeof(Fantasia), 1, fp);
  fclose(fp);
}


char* telaPesquisarFantasia(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
  limpaTela();
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
  delay(1);
  return id;
}

Fantasia* buscarFantasia(char* id) {
  FILE* fp;
  Fantasia* fant;

  fant = (Fantasia*) malloc(sizeof(Fantasia));
  fp = fopen("fantasias.dat", "rb");
  if (fp == NULL) {
    telaErroArquivo();
  }
  while(!feof(fp)) {
    fread(fant, sizeof(Fantasia), 1, fp);
    if (strcmp(fant->idFantasia, id) == 0  && (fant->statusCadastro == 'C')) {
      fclose(fp);
      return fant;
    }
  }
  fclose(fp);
  return NULL;
}

void exibirFantasia(Fantasia* fant) {

  if (fant == NULL) {
    printf("\n= = = Fantasia Inexistente = = =\n");
  } else {
    printf("\n= = = Fantasia Cadastrada = = =\n");
    printf("ID: %s\n", fant->idFantasia);
    printf("Nome da fantasia: %s\n", fant->nomeFantasia);
    printf("Valor: %.2f\n", fant->valor);
    printf("Quantidade de aluguéis: %i\n", fant->quantidadeAlugueis);
  }
  if(fant->status == 'D'){
    printf("Disponível\n");
  }
  else{
    printf("Alugada\n");
  }
  printf("\t\t\tTecle ENTER para continuar!\n\n");
  getchar();
}


char* telaAtualizarFantasia(void) {
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

char* telaExcluirFantasia(void) {
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

