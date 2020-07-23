
typedef struct Funcionario funcionario;

typedef struct no No;

typedef struct   lista Lista;


void menufuncionario();

void menualteradadosfuncionario();

void menuoperacao();

void mestrabalhado();

void diasemana();

void lerfuncionario(funcionario *f);

void inseri_inicio(Lista *lista, funcionario dado);

void inseri_fim(Lista *lista, funcionario dado);

void mostra(Lista *lista);

void deletacodigo(Lista *lista,int cod);

void deletalista(Lista *lista);

void pesquisar(Lista lista, int cod);

No* alteradados(Lista *lista, int codigo);

void tamanhoarquivo(Lista *lista);

Lista criarlista(int n);

void ordenar(Lista *lista);

void salvalista(Lista lista);

Lista lerarquivo();

void valorpordiaria(funcionario *f);

void diatrabalhado(funcionario *f,int dia);

void totaldiastrabalhado(funcionario *f);

void aumento_salario(funcionario *f);

void main_funcionario();

