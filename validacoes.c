#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Validar CPF - Referência: Flavius Gorgônio
int validaCPF(char cpf[]) {
  int soma;
  int d1;
  int d2;
  int tam = strlen(cpf);
  if (tam != 11) {
    return 0;
  }
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
      if (!(email[i+1] >= 'a' && email[i+1] <= 'z')){
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

// Validar NOME - Adaptado de Flavius Gorgônio
int validarNome(char nome[]){
int tam = strlen(nome);
char acentos[] ="ÁÉÍÓÚÂÊÔÇÀÃÕáéíóúâêôçàãõ";
int tamAcentos = strlen(acentos);
int cont = 0;
if (tam == 0) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (nome[i] >= 'A' && nome[i] <= 'Z') {
      continue;
    } else if (nome[i] >= 'a' && nome[i] <= 'z') {
      continue;
    } else if (nome[i] == ' ') {
      continue;
    } else {
      if (nome[i] >= '0' && nome[i] <= '9'){
        return 0;
      }else{
      for(int l = 0; l < tamAcentos;l++){
        if(nome[i] == acentos[l]){
          cont += 1;
          break;
        }else{
          cont +=0;
        }
      }
      if (cont == 0){
        return 0;
      }else if(cont >= 1){
        continue;
      }
    }
  }
  }
  return 1;
}

// Validar TELEFONE

int validaTelefone(char telefone[]){
int tam = strlen(telefone);
if (tam != 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (telefone[i] >= '0' && telefone[i] <= '9') {
      continue;
    } else {
        return 0;
      
  }
}
return 1;
}

//VALIDAR ID
int validaID(char id[]){
int tam = strlen(id);
if (tam > 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (id[i] >= '0' && id[i] <= '9') {
      continue;
    } else {
        return 0;
      
  }
}
return 1;
}