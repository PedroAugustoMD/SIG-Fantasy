#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloRelatorio.h"
#include "moduloCliente.h"
#include "moduloFantasia.h"
#include "validacoes.h"
#include "moduloAlugueis.h"

void moduloRelatorio(void) {
	char opcao;
  do {
		opcao = menuRelatorios();
		switch(opcao) {
			case '1': 	historicoAlugueis();
						break;
			case '2': 	clientesCadastrados();
						break;
			case '3': 	fantasiasCadastradas();
						break;
			case '4': 	alugueisPorCPF();
						break;
      case '5': 	alugueisPorID();
						break;      
		} 		
	} while (opcao != '0');

}

void historicoAlugueis(void) {

    telaHistoricoAlugueis();
}

void clientesCadastrados(void) {

    telaClientesCadastrados();
}

void fantasiasCadastradas(void) {

    telaFantasiasCadastradas();
}

void alugueisPorCPF(void) {

    char* cpf;

	  cpf = telaPesquisarCliente();
    relatAlugueisPorCPF(cpf);
    free(cpf);
}

void alugueisPorID(void) {

    char* id;

	  id = telaPesquisarFantasia();
    relatAlugueisPorID(id);
    free(id);
}

void fantasiasDisponiveis(void) {

    telaFantasiasDisponiveis();
}

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
	printf("///           2. Clientes cadastrados                                     ///\n");
	printf("///           3. Fantasias cadastradas                                    ///\n");
	printf("///           4. Aluguéis por CPF                                         ///\n");
  printf("///           5. Aluguéis por ID                                          ///\n");
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


void telaHistoricoAlugueis(void) {
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
	printf("///           = = = = = = = = Histórico de Aluguéis = = = = = = = =      ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           Histórico de empréstimos:                                   ///\n");
  listaHistoricoAlugueis(); 
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


void listaHistoricoAlugueis(void) {
    FILE* fp;
    Aluguel* alg;
    alg = (Aluguel*) malloc(sizeof(Aluguel));
    fp = fopen("alugueis.dat", "rb");
    while (fread(alg, sizeof(Aluguel), 1, fp)) {
      printf("///           Data: %s                                 ///\n", alg->data);
      printf("///           CPF: %s                                            ///\n", alg->cpfCliente);
      printf("///           ID da Fantasia: %s                                         ///\n", alg->idFantasia);
      printf("///           Valor: %.2f                                               ///\n", alg->valorPago);
      if (alg->status == 'N'){
        printf("///           Pagamento pendente                                            ///\n ------------------------------------------------------------------\n");
      }  
      else{
        printf("///           Pago                                                      ///\n ------------------------------------------------------------------\n");
      }
    }
    fclose(fp);
    free(alg);
}

void listaClientesCadastrados(void) {
    FILE* fp;
    Cliente* clt;
    clt = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    while (fread(clt, sizeof(Cliente), 1, fp)) {
      if(clt->status == 'C'){
        printf("///           CPF: %s                                           ///\n", clt->cpfCliente);
        printf("///           Nome: %s                                          ///\n", clt->nomeCliente);
        printf("///           Email: %s                                         ///\n", clt->email);
        printf("///           Telefone: %s                                      ///\n", clt->fone);
        printf("///           Qtd. de Aluguéis: %i                                     ///\n", clt->quantidadeAlugueis);
        printf("------------------------------------------------------------------\n");
      }     
    }
    fclose(fp);
    free(clt);
}

void telaClientesCadastrados(void) {
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
	printf("///           = = = = = = = = Clientes Cadastrados = = = = = = = =        ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           Lista de clientes:                                          ///\n");
  listaClientesCadastrados();
 	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void listaFantasiasCadastradas(void) {
    FILE* fp;
    Fantasia* fant;
    fant = (Fantasia*) malloc(sizeof(Fantasia));
    fp = fopen("fantasias.dat", "rb");
    while (fread(fant, sizeof(Fantasia), 1, fp)) {
      if(fant->statusCadastro == 'C'){
        printf("///           ID: %s                                                      ///\n", fant->idFantasia);
        printf("///           Nome: %s                                                ///\n", fant->nomeFantasia);
        printf("///           Valor: %.2f                                                ///\n", fant->valor);
        printf("///           Qtd. de Aluguéis: %i                                         ///\n", fant->quantidadeAlugueis);
        if (fant->status == 'D'){
          printf("///           Disponível                                                  ///\n ------------------------------------------------------------------\n");
        }  
        else{
          printf("///           Alugada                                                     ///\n ------------------------------------------------------------------\n");
        }
      }     
    }
    fclose(fp);
    free(fant);
}

void telaFantasiasCadastradas(void) {
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
	printf("///           = = = = = = = = Fantasias Cadastradas = = = = = = = =        ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           Lista de Fantasias:                                         ///\n");
  listaFantasiasCadastradas();
 
  
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void relatAlugueisPorCPF(char* cpf) {
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
	printf("///           = = = = = = = = CPF: %s = = = = = = = =          ///\n",cpf);
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           Histórico de empréstimos:                                   ///\n");
  listaAlugueisPorCPF(cpf);
  printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void listaAlugueisPorCPF(char* cpf) {
    FILE* fp;
    Aluguel* alg;
    alg = (Aluguel*) malloc(sizeof(Aluguel));
    fp = fopen("alugueis.dat", "rb");
    while (fread(alg, sizeof(Aluguel), 1, fp)) {
      if(strcmp(alg->cpfCliente, cpf) == 0){
        printf("///           Data: %s                                 ///\n", alg->data);
        printf("///           ID da Fantasia: %s                                         ///\n", alg->idFantasia);
        printf("///           Valor: %.2f                                               ///\n", alg->valorPago);
        if (alg->status == 'N'){
          printf("///           Pagamento pendente                                            ///\n ------------------------------------------------------------------\n");
        }  
        else{
          printf("///           Pago                                                      ///\n ------------------------------------------------------------------\n");
        }
      }
    }
    fclose(fp);
    free(alg);
}

void relatAlugueisPorID(char* id) {
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
	printf("///           = = = = = = = = ID: %s = = = = = = = =                    ///\n",id);
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           Histórico de empréstimos:                                   ///\n");
  listaAlugueisPorID(id);
  printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void listaAlugueisPorID(char* id) {
    FILE* fp;
    Aluguel* alg;
    alg = (Aluguel*) malloc(sizeof(Aluguel));
    fp = fopen("alugueis.dat", "rb");
    while (fread(alg, sizeof(Aluguel), 1, fp)) {
      if(strcmp(alg->idFantasia, id) == 0){
        printf("///           Data: %s                                 ///\n", alg->data);
        printf("///           CPF: %s                                            ///\n", alg->cpfCliente);
        printf("///           Valor: %.2f                                               ///\n", alg->valorPago);
        if (alg->status == 'N'){
          printf("///           Pagamento pendente                                            ///\n ------------------------------------------------------------------\n");
        }  
        else{
          printf("///           Pago                                                      ///\n ------------------------------------------------------------------\n");
        }
      }
    }
    fclose(fp);
    free(alg);
}

void telaFantasiasDisponiveis(void) {
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
	printf("///           = = = = = = = = Fantasias Disponíveis = = = = = = = =       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = = = =       ///\n");
	printf("///                                                                       ///\n");
	printf("///           Lista de Fantasias:                                         ///\n");
  listaFantasiasDisponiveis();
 
  
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void listaFantasiasDisponiveis(void) {
    FILE* fp;
    Fantasia* fant;
    fant = (Fantasia*) malloc(sizeof(Fantasia));
    fp = fopen("fantasias.dat", "rb");
    while (fread(fant, sizeof(Fantasia), 1, fp)) {
      if(fant->status == 'D' && fant->statusCadastro == 'C'){
        printf("///           ID: %s                                                      ///\n", fant->idFantasia);
        printf("///           Nome: %s                                                ///\n", fant->nomeFantasia);
        printf("///           Valor: %.2f                                                ///\n", fant->valor);
        printf("///           Qtd. de Aluguéis: %i                                         ///\n", fant->quantidadeAlugueis);
        if (fant->status == 'D'){
          printf("///           Disponível                                                  ///\n ------------------------------------------------------------------\n");
        }  
        else{
          printf("///           Alugada                                                     ///\n ------------------------------------------------------------------\n");
        }
      }     
    }
    fclose(fp);
    free(fant);
}