typedef struct cliente Cliente;

struct fantasia {
   char idFantasia[12];
   char nomeFantasia[51];
   float valor;
   char status;
   int quantidadeAlugueis;
   char statusCadastro;
};



void moduloFantasia(void);
char menuFantasia(void);


Fantasia* telaCadastrarFantasia(void);
void cadastrarFantasia(void);
void gravarFantasia(Cliente*);

void pesquisarFantasia(void);
char* telaPesquisarFantasia(void);
Fantasia* buscarFantasia(char*);
void exibirFantasia(Cliente*);

void telaAtualizarFantasia(void);


void telaExcluirFantasia(void);