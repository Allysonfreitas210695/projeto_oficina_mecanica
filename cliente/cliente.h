



typedef struct Cliente cliente;

typedef struct nocliente Nocliente;

typedef struct listacliente Listacliente;


void menualteradados();

void menucliente();

void lercliente(cliente *c);

void mostralista(Listacliente *listacliente);

void inseri_cliente_inicio(Listacliente *listacliente, cliente dadocliente);

void inseri_cliente_fim(Listacliente *listacliente, cliente dadocliente);

void pesquisarcliente(Listacliente *listacliente, int codigo);

void removelistacliente(Listacliente *listacliente);

void removeporcodigo(Listacliente *listacliente, int codigo);

Nocliente* alteracliente(Listacliente *listacliente, int codigo);

void tamanhoarquivocliente(Listacliente *listacliente);

Listacliente criarlistacliente(int n);

void ordenarlistacliente(Listacliente *listacliente);

void salvacliente(Listacliente *listacliente);

Listacliente lerarquivocliente();

void maincliente();

