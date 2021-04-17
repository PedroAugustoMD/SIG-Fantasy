#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloCliente.h"
#include "validacoes.h"

typedef struct cliente Cliente;

void moduloCliente(void) {
  char opcao;
  do {
		opcao = menuCliente();
		switch(opcao) {
			case '1': 	cadastrarCliente();
						break;
			case '2': 	pesquisarCliente();
						break;
			case '3': 	atualizarCliente();
						break;
			case '4': 	excluirCliente();
						break;
		} 		
	} while (opcao != '0');

}

void cadastrarCliente(void) {
  Cliente *clt;
  clt = telaCadastrarCliente();
  gravarCliente(clt);
  free(clt);
}

void pesquisarCliente(void) {
  Cliente *clt;
  char* cpf;
	cpf = telaPesquisarCliente();
  clt = buscarCliente(cpf);
  exibirCliente(clt);
  free(clt); 
  free(cpf);
}

void atualizarCliente(void) {
	Cliente* clt;
	char* cpf;
  
	cpf = telaAtualizarCliente();
	clt = buscarCliente(cpf);
	if (clt == NULL) {
    	printf("\n\nCliente não encontrado!\n\n");
  	} else {
		  clt = telaCadastrarCliente();
		  strcpy(clt->cpfCliente, cpf);
		  regravarCliente(clt);
	}
	free(clt);
  free(cpf);
}

void excluirCliente(void) {
	Cliente* clt;
	char *cpf;
  char confirmacao[2];
	cpf = telaExcluirCliente();
	clt = (Cliente*) malloc(sizeof(Cliente));
	clt = buscarCliente(cpf);
	if (clt == NULL) {
    	printf("\n\nCliente não encontrado!\n\n");
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
		  clt->status = 'X';
		  regravarCliente(clt);
      free(clt);
		  
    }
    else if(confirmacao[0] == 'N' || confirmacao[0] == 'n'){
      printf("Ação interrompida!");
    }
	}
	free(cpf);
}



void telaErroArquivo(void) {
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
	printf("///           = = = = = = =  Ops! Ocorreu em erro = = = = = =             ///\n");
	printf("///           = = =  Não foi possível acessar o arquivo = = =             ///\n");
	printf("///           = = = = com informações sobre os clientes = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = =  Pedimos desculpas pelos inconvenientes = =             ///\n");
	printf("///           = = =  mas este programa será finalizado! = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	exit(1);
}

char menuCliente(void) {
  char op;
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
	printf("///           = = = = = = = = = Menu Cliente = = = = = = = = =            ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar um novo cliente                                ///\n");
	printf("///           2. Pesquisar os dados de um cliente                         ///\n");
	printf("///           3. Atualizar o cadastro de um cliente                       ///\n");
	printf("///           4. Excluir um cliente do sistema                            ///\n");
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

Cliente* telaCadastrarCliente(void) {
  Cliente *clt;
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
	printf("///           = = = = = = = = Cadastrar Cliente = = = = = = = =           ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
  clt = (Cliente*) malloc(sizeof(Cliente));
	printf("///           CPF (Apenas números!): ");
  scanf("%[^\n]", clt->cpfCliente);
  getchar();
  
   while (validaCPF(clt->cpfCliente) == 0){
      printf("///           CPF inválido!: ");
        scanf("%[^\n]", clt->cpfCliente);
	    getchar();
   }
	printf("///           Nome: ");
  scanf("%[^\n]", clt->nomeCliente);
  getchar();
  while (validarNome(clt->nomeCliente) == 0){
      printf("///           Nome inválido!: ");
        scanf("%[^\n]", clt->nomeCliente);
	    getchar();
   }
	printf("///           E-mail: ");
  scanf("%[^\n]", clt->email);
  getchar();
  while (validaEmail(clt->email) == 0){
      printf("///           Email inválido!: ");
      scanf("%[^\n]", clt->email);
	    getchar();
   }
	printf("///           Telefone (Apenas números!): ");
  scanf("%[^\n]", clt->fone);
  getchar();
  while (validaTelefone(clt->fone) == 0){
      printf("///           Telefone inválido!: ");
        scanf("%[^\n]", clt->fone);
	    getchar();
   }
   clt->status = 'C';
   clt-> quantidadeAlugueis = 0;
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return clt;
}

void gravarCliente(Cliente* clt) {
  FILE* fp;

  fp = fopen("clientes.dat", "ab");
  if (fp == NULL) {
    telaErroArquivo();
  }
  fwrite(clt, sizeof(Cliente), 1, fp);
  fclose(fp);
}

char* telaPesquisarCliente(void) {
  char* cpf;
  cpf = (char*) malloc(12*sizeof(char));
  limpaTela();
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
	printf("///           = = = = = = = = Pesquisar Cliente = = = = = = = =           ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           CPF: ");
  scanf("%[0-9]", cpf);
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  delay(1);
  return cpf;
}

Cliente* buscarCliente(char* cpf) {
  FILE* fp;
  Cliente* clt;

  clt = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
    telaErroArquivo();
  }
  while(!feof(fp)) {
    fread(clt, sizeof(Cliente), 1, fp);
    if (strcmp(clt->cpfCliente, cpf) == 0  && (clt->status == 'C')) {
      fclose(fp);
      return clt;
    }
  }
  fclose(fp);
  return NULL;
}

void exibirCliente(Cliente* clt) {

  if (clt == NULL) {
    printf("\n= = = Cliente Inexistente = = =\n");
  } else {
    printf("\n= = = Cliente Cadastrado = = =\n");
    printf("CPF: %s\n", clt->cpfCliente);
    printf("Nome do cliente: %s\n", clt->nomeCliente);
    printf("Endereço eletrônico: %s\n", clt->email);
    printf("Celular: %s\n", clt->fone);
    printf("Quantidade de aluguéis: %i\n", clt->quantidadeAlugueis);
  }
  printf("\t\t\tTecle ENTER para continuar!\n\n");
  getchar();
}

char* telaAtualizarCliente(void) {
    char* cpf;
    cpf = (char*) malloc(12*sizeof(char));
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
	printf("///           = = = = = = = = Atualizar Cliente = = = = = = = =           ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           Digite o CPF do cliente: ");
  scanf("%[0-9]", cpf);
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return cpf;
}

void regravarCliente(Cliente* clt) {
	int achou;
	FILE* fp;
	Cliente* cltLido;

	cltLido = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivo();
	}
	achou = 0;
	while(fread(cltLido, sizeof(Cliente), 1, fp) && !achou) {

		if (strcmp(cltLido->cpfCliente, clt->cpfCliente) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
        	fwrite(clt, sizeof(Cliente), 1, fp);
		}
	}
	fclose(fp);
	free(cltLido);
}

char* telaExcluirCliente(void) {
    char* cpf;
    cpf = (char*) malloc(12*sizeof(char));
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
	printf("///           = = = = = = = = Excluir Cliente = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           CPF: ");
  scanf("%[0-9]", cpf);
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return cpf;
}

