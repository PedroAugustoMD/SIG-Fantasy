typedef struct cliente Cliente;

struct cliente {
   char cpfCliente[12];
   char nomeCliente[51];
   char email[51];
   char fone[15];
   int quantidadeAlugueis;
   char status;
};

void telaErroArquivo(void);


void moduloCliente(void);
char menuCliente(void);

Cliente* telaCadastrarCliente(int);
void cadastrarCliente(void);
void gravarCliente(Cliente*);

void pesquisarCliente(void);
char* telaPesquisarCliente(void);
Cliente* buscarCliente(char*);
void exibirCliente(Cliente*);

void atualizarCliente(void);
char* telaAtualizarCliente(void);
void regravarCliente(Cliente*);

void excluirCliente(void);
char* telaExcluirCliente(void);
Cliente* buscarClienteCadastro(char*);