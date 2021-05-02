#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloAlugueis.h"
#include "moduloCliente.h"
#include "moduloFantasia.h"
#include "validacoes.h"
#include <time.h>
typedef struct aluguel Aluguel;

void moduloAlugueis(void) {
	char opcao;
  do {
		opcao = menuAlugueis();
		switch(opcao) {
			case '1': 	alugarFantasia();
						break;
			case '2': 	devolverFantasia();
						break;
			case '3': 	telaListarFantasia();
						break;
		} 		
	} while (opcao != '0');

}

void alugarFantasia(void) {
  
  Aluguel *alg;
  Cliente *clt;
  char* cpf;
  Fantasia *fant;
  char* id;
  cpf = telaPesquisarCliente();
  clt = buscarCliente(cpf);
  id = telaPesquisarFantasia();
  fant = buscarFantasia(id);
  if (clt == NULL || fant == NULL || fant->status != 'D'){
    printf("Dados incorretos!");
    getchar();
  }
  else{
  alg = telaAlugarFantasia(clt->cpfCliente, fant->idFantasia, fant->valor);
  if (alg==NULL){
    printf("Empréstimo cancelado!");
    getchar();
  }
  gravarAluguel(alg);
  fant->status = 'A';
  clt->quantidadeAlugueis+=1;
  fant->quantidadeAlugueis+=1;
  regravarFantasia(fant);
  regravarCliente(clt);
  }
     free(cpf);
    free(clt);
    free(id);
    free(fant);
    free(alg);
}

void devolverFantasia(void) {
    Aluguel *alg;
    Fantasia *fant;
    char* cpf;
    char* id;
    cpf = telaPesquisarCliente();
    id = telaPesquisarFantasia();
    fant = buscarFantasia(id);

    alg = buscarAluguel(cpf, id);
    if (alg == NULL || alg->status!='N'){
      printf("Aluguel não encontrado!");
      getchar();
    }
    else{
      alg = telaDevolverFantasia(alg);
      alg->status = 'P';
      fant->status = 'D';
      regravarFantasia(fant);
      regravarAluguel(alg);
    }
    free(cpf);
    free(id);
    free(fant);
    free(alg);
}

char menuAlugueis(void) {
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
	printf("///           = = = = = = = = = Menu Alugueis = = = = = = = = =           ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Alugar uma fantasia                                      ///\n");
	printf("///           2. Devolver uma fantasia                                    ///\n");
	printf("///           3. Listar fantasias disponíveis                             ///\n");
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

Aluguel* telaAlugarFantasia(char* cpf, char* id, float valor) {
  char confirmacao[2];
  time_t agora;
  char datahora[100];
  agora = time(NULL);
   strftime( datahora, sizeof(datahora), "%Y.%m.%d - %H:%M:%S", localtime( &agora ) );
  Aluguel *alg;
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
	printf("///           = = = = = = = = Alugar Fantasia = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///                                                                       ///\n");
  alg = (Aluguel*) malloc(sizeof(Aluguel));
	

	printf("///           Confirma o aluguel (s/n)? ");
  scanf("%[^\n]", confirmacao);
  getchar();
    while (validaConfirmacao(confirmacao) == 0){
      printf("///           Ação inválida!: ");
        scanf("%[^\n]", confirmacao);
	    getchar();
   }
   if(strcmp (confirmacao, "S") == 0 || strcmp (confirmacao, "s") == 0){
      strcpy(alg->cpfCliente, cpf);
	    strcpy(alg->idFantasia, id);
      alg->valorPago = valor;
      strcpy(alg->data, datahora);
      alg->status='N';
   }
   else{
     free(alg);
     return NULL;
   }
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return alg;
}

void gravarAluguel(Aluguel* alg) {
  FILE* fp;

  fp = fopen("alugueis.dat", "ab");
  if (fp == NULL) {
    telaErroArquivo();
  }
  fwrite(alg, sizeof(Aluguel), 1, fp);
  fclose(fp);
}

Aluguel* telaDevolverFantasia(Aluguel* alg) { 
  int dias;
  float multa;
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
	printf("///           = = = = = = = = Devolver Fantasia = = = = = = = =           ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");
	printf("///     CPF: %s\n", alg->cpfCliente);
  printf("///     ID: %s\n", alg->idFantasia);
  printf("///     Data: %s\n", alg->data);
  dias = difDatas(alg->data) + 1;
  printf("dias \n%i",dias);
  if(dias>=7){
    multa = (dias - 7) * 2;
    printf("multa %.2f\n",multa);
    alg->valorPago+=multa;
    printf("///     Valor com multa: %.2f\n", alg->valorPago);  
  }else{
    printf("///     Valor: %.2f\n", alg->valorPago);
  }
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return alg;
}

void telaListarFantasia(void) {
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
	printf("///           = = = = = = = = Listar Fantasia = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Fantasias disponíveis:                                      ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

int difDatas( char datahora1[] )
{
    time_t t1;
    time_t t2;
    double dias;
    struct tm tm; 
    int ano, mes; 
    char datahora2[] = "2021.05.12 - 13:10:20";
    ///time_t agora;
    ///agora = time(NULL);
    ///strftime( datahora2, sizeof(datahora2), "%Y.%m.%d - %H:%M:%S", localtime( &agora ) );

    sscanf( datahora1, "%d.%d.%d - %d:%d:%d", &ano, &mes, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec );

    tm.tm_year = ano - 1900;
    tm.tm_mon = mes - 1;

    t1 = mktime( &tm );

    sscanf( datahora2, "%d.%d.%d - %d:%d:%d", &ano, &mes, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec );

    tm.tm_year = ano - 1900;
    tm.tm_mon = mes - 1;

    t2 = mktime( &tm );
    dias = difftime(t2,t1)/86400;

    return dias;
}

Aluguel* buscarAluguel(char* cpf, char* id) {
  FILE* fp;
  Aluguel* alg;

  alg = (Aluguel*) malloc(sizeof(Aluguel));
  fp = fopen("alugueis.dat", "rb");
  if (fp == NULL) {
    telaErroArquivo();
  }
  while(!feof(fp)) {
    fread(alg, sizeof(Aluguel), 1, fp);
    if ((strcmp(alg->cpfCliente, cpf) == 0)  && (strcmp(alg->idFantasia, id) == 0) && (alg->status != 'P')) {
      fclose(fp);
      return alg;
    }
  }
  fclose(fp);
  return NULL;
}

void regravarAluguel(Aluguel* alg) {
	int achou;
	FILE* fp;
	Aluguel* algLido;

  algLido = (Aluguel*) malloc(sizeof(Aluguel));
	fp = fopen("alugueis.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivo();
	}
	achou = 0;
	while(fread(algLido, sizeof(Aluguel), 1, fp) && !achou) {

		if ((strcmp(algLido->cpfCliente, alg->cpfCliente) == 0) && (strcmp(algLido->idFantasia, alg->idFantasia) == 0 && (strcmp(algLido->data, alg->data) == 0) )) {
			achou = 1;
			fseek(fp, -1*sizeof(Aluguel), SEEK_CUR);
        	fwrite(alg, sizeof(Aluguel), 1, fp);
		}
	}
	fclose(fp);
	free(algLido);
}