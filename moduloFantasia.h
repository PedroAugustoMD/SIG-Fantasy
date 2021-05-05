typedef struct fantasia Fantasia;

struct fantasia {
   char idFantasia[6];
   char nomeFantasia[51];
   float valor;
   char status;
   int quantidadeAlugueis;
   char statusCadastro;
};

void telaErroArquivo(void);

void moduloFantasia(void);
char menuFantasia(void);


Fantasia* telaCadastrarFantasia(int);
void cadastrarFantasia(void);
void gravarFantasia(Fantasia*);

void pesquisarFantasia(void);
char* telaPesquisarFantasia(void);
Fantasia* buscarFantasia(char*);
void exibirFantasia(Fantasia*);

void atualizarFantasia(void);
char* telaAtualizarFantasia(void);
void regravarFantasia(Fantasia*);

void excluirFantasia(void);
char* telaExcluirFantasia(void);

Fantasia* buscarFantasiaCadastro(char*);