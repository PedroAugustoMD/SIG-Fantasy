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

char menuPrincipal(void);

void moduloInformacoes(void);
void menuSobre(void);

void moduloCliente(void);
char menuCliente(void);
void telaCadastrarCliente(void);
void telaPesquisarCliente(void);
void telaAtualizarCliente(void);
void telaExcluirCliente(void);

void moduloFantasia(void);
char menuFantasia(void);
void telaCadastrarFantasia(void);
void telaPesquisarFantasia(void);
void telaAtualizarFantasia(void);
void telaExcluirFantasia(void);

void moduloAlugueis(void);
char menuAlugueis(void);
void telaAlugarFantasia(void);
void telaDevolverFantasia(void);
void telaListarFantasia(void);

void moduloRelatorio(void);
char menuRelatorios(void);
void telaHistoricoFantasia(void);
void telaVerificarDatas(void);
void telaClienteFiel(void);
void telaFantasiaMaisAlugada(void);


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

char menuPrincipal(void) {
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
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = = = Menu Principal  = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Módulo do cliente                                        ///\n");
	printf("///           2. Módulo de fantasia                                       ///\n");
	printf("///           3. Módulo de aluguéis                                       ///\n");
	printf("///           4. Módulo de relatório                                      ///\n");
	printf("///           5. Informações sobre o sistema                              ///\n");
	printf("///           0. Encerra o programa                                       ///\n");
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


