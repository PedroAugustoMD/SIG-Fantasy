typedef struct cliente Cliente;

struct cliente {
   char cpfCliente[12];
   char nomeCliente[51];
   char email[51];
   char fone[15];
   int quantidadeAlugueis;
   char status;
};



void moduloCliente(void);
char menuCliente(void);

Cliente* telaCadastrarCliente(void);
void cadastrarCliente(void);
void gravarCliente(Cliente*);


void telaPesquisarCliente(void);
void telaAtualizarCliente(void);
void telaExcluirCliente(void);