// Referência: Flavius Gorgônio

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