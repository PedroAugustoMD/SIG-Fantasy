typedef struct aluguel Aluguel;
#include <time.h>
struct aluguel {
   char cpfCliente[12];
   char idFantasia[12];
   char data[30];
   float valorPago;
   char status;
};


void moduloAlugueis(void);
char menuAlugueis(void);

void alugarFantasia(void);
Aluguel* telaAlugarFantasia(char*, char*, float);
void gravarAluguel(Aluguel*);

void devolverFantasia(void);
Aluguel* telaDevolverFantasia(Aluguel*);
Aluguel* buscarAluguel(char*, char*);
void regravarAluguel(Aluguel*);

int difDatas( char[] );
void telaListarFantasia(void);