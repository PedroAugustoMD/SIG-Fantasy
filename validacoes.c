
#include <string.h>
#include <ctype.h>

// Validação do CPF - Adaptado de Flavius Gorgônio
int validaCPF(char cpf[]) {
  int soma;
  int d1;
  int d2;
  for(int i = 0; i<11;i++){
    if ((cpf[i] - '0') < 0 || (cpf[i] - '0') > 9){
    return 0;
    }
  }
  soma = 0;
  for(int i = 0; i<9;i++){
  soma += ((cpf[i] - '0') * (10 - i));
  }
  d1 = 11 - (soma % 11);
  if (d1 == 10 || d1 == 11){
    d1 = 0;
  }
  if (d1 != (cpf[9] - '0')){
    return 0;
  }
  soma = 0;
  for(int i = 0; i<10;i++){
    soma += (cpf[i]-'0') * (11 - i);
  }
  d2 = 11 - (soma%11);
  if (d2 == 10 || d2 == 11){
    d2 = 0;
  }
  if (d2 != (cpf[10] - '0')){
    return 0;
  }
  return 1;
}

// Validar EMAIL
int validaEmail(char email[]) {
  int tam = strlen(email);
  int arrobas;
  int pontos;
  int posicaoArroba;
  int posicaoPonto;
  for(int i = 0; i < tam; i++){
    if (email[i] == '@'){
      arrobas+=1;
      posicaoArroba = i;
      if (email[i+1] == '.'){
        return 0;
      }
    }
  }
  if(arrobas != 1){
    return 0;
  }
  for (int i = 0; i < tam; i++){
    if(email[i] == '.'){
      pontos += 1;
      posicaoPonto = i;
      if (email[i+1] == '.'){
        return 0;
      }
    }
  
  }
  if (pontos == 0 || posicaoPonto <= posicaoArroba){
    return 0;
  }

  return 1;

}

// Validar NOME
int validarNome(char nome[]){
int tam = strlen(nome);
for(int i=0; i< tam; i++){
  if(!isalpha(nome[i])){
    if(!isblank(nome[i])){
    return 0;
    }
  }
  }

  return 1;
}
