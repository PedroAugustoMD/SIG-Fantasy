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
    
    
    //menuSobre();
    //opcao = menuPrincipal();
    //opcao = menuCliente();
    //opcao = menuFantasia();
    //opcao = menuAlugueis();
    //opcao = menuRelatorios();
    //telaCadastrarCliente();
    //telaPesquisarCliente();
    //telaAtualizarCliente();
    //telaExcluirCliente();   
    //telaCadastrarFantasia();
    //telaPesquisarFantasia();
    //telaAtualizarFantasia();
    //telaExcluirFantasia();
    //telaAlugarFantasia();
    //telaDevolverFantasia();
    //telaListarFantasia();
    //telaHistoricoFantasia();
    //telaVerificarDatas();
    //telaClienteFiel();
    //telaFantasiaMaisAlugada(); 

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

void menuSobre(void) {
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///             Projeto Sistema de Aluguéis de Roupas e Fantasias           ///\n");
    printf("///            Developed by  @PedroAugustoMD and @leonardodantas4           ///\n");
    printf("///                             Jan, 2021                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Aluguel de Fantasias = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///  Projeto desenvolvido para a disciplina DCT1106 - Programação, com o    ///\n");
    printf("///  objetivo de alugar fantasias para os usuários. Esse projeto contém as  ///\n");
    printf("///  funcionalidades principais de uma loja de fantasias que serão          ///\n");
    printf("///  escolhidas pelos usuários do programa. Essas funcionalidades são:      ///\n");
    printf("///  cadastro, consulta, alteração, exclusão, aluguel, devolução, listas    ///\n");
    printf("///  de fantasias disponíveis, histórico de aluguéis, relatório, cliente    ///\n");
    printf("///  mais fiel e fantasia mais alugada.                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///  Bem vindos a SIG-Fantasy, o melhor local para alugar fantasias e       ///\n");
    printf("///  roupas do Brasil, aqui você poderá alugar os seus looks pelo melhor    ///\n");
    printf("///  preço do mercado. Está indo para uma festa fantasia e ainda não sabe o ///\n");
    printf("///  que vestir? Veja as fantasias disponíveis e se divirta como nunca!     ///\n");
    printf("///                                                                         ///\n");
    printf("///  Atenção: em caso de atrasos, a SIG-Fantasy cobra R$2,00 a cada dia     ///\n");
    printf("///  pendente!                                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
	  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	  getchar();
}


void moduloInformacoes(void) {
	menuSobre();
}
