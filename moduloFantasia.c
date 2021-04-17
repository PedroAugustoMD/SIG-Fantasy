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
			case '3': 	atualizarFantasia();
						break;
			case '4': 	excluirFantasia();
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

void atualizarFantasia(void) {
	Fantasia* fant;
	char* id;
  
	id = telaAtualizarFantasia();
	fant = buscarFantasia(id);
	if (fant == NULL) {
    	printf("\n\nFantasia não encontrada!\n\n");
  	} else {
		  fant = telaCadastrarFantasia();
		  strcpy(fant->idFantasia, id);
		  regravarFantasia(fant);
	}
	free(fant);
  free(id);
}

void excluirFantasia(void) {
	Fantasia* fant;
	char *id;
  char confirmacao[2];
	id = telaExcluirFantasia();
	fant = (Fantasia*) malloc(sizeof(Fantasia));
	fant = buscarFantasia(id);
	if (fant == NULL) {
    	printf("\n\nFantasia não encontrada!\n\n");
  	} else {
      printf("Digite 's' para continuar a exclusão ou 'n' para interromper: ");
      scanf("%[^\n]", confirmacao);
      getchar();
      while (validaConfirmacao(confirmacao) == 0){
      printf("///           Ação inválida!: ");
        scanf("%[^\n]", confirmacao);
	    getchar();
    }
    if (confirmacao[0] == 'S' || confirmacao[0] == 's'){
		  fant->statusCadastro = 'X';
		  regravarFantasia(fant);
      free(fant);
		  
    }
    else if(confirmacao[0] == 'N' || confirmacao[0] == 'n'){
      printf("Ação interrompida!");
    }
	}
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
    if(fant->status == 'D'){
    printf("Disponível\n");
  }
  else{
    printf("Alugada\n");
  }
  
  }
  
  printf("\t\t\tTecle ENTER para continuar!\n\n");
  getchar();
}


char* telaAtualizarFantasia(void) {
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
	printf("///           = = = = = = = = Atualizar Fantasia = = = = = = = =          ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           Digite o ID da fantasia: ");
  scanf("%[0-9]", id);
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return id;
}

void regravarFantasia(Fantasia* fant) {
	int achou;
	FILE* fp;
	Fantasia* fantLida;

	fantLida = (Fantasia*) malloc(sizeof(Fantasia));
	fp = fopen("fantasias.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivo();
	}
	achou = 0;
	while(fread(fantLida, sizeof(Fantasia), 1, fp) && !achou) {

		if (strcmp(fantLida->idFantasia, fant->idFantasia) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Fantasia), SEEK_CUR);
        	fwrite(fant, sizeof(Fantasia), 1, fp);
		}
	}
	fclose(fp);
	free(fantLida);
}


char* telaExcluirFantasia(void) {
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
  return id;
}

