#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloInformacoes.h"
#include "validacoes.h"

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