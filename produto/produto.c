
typedef struct Produto produto;

typedef struct noproduto Noproduto;

typedef struct  listaproduto Listaproduto;

void menu();

void compra();

void lerproduto(produto *p);

void inseri_produto_inicio(Listaproduto *listaproduto, produto dado);

void inseri_produto_fim(Listaproduto *listaproduto, produto dado);

void mostraproduto(Listaproduto *listaproduto);

void deleta_produto_final(Listaproduto *listaproduto);

void deletaprodutocodigo(Listaproduto *listaproduto, int cod);

void deletalistaproduto(Listaproduto *listaproduto);

void pesquisarproduto(Listaproduto *listaproduto, int cod);

Noproduto* alteradadosproduto(Listaproduto *listaproduto, int codigo);

void tamanhoarquivoproduto(Listaproduto *listaproduto);

Listaproduto criarlistaproduto(int n);

void ordenarproduto(Listaproduto *listaproduto);

void salvalistaproduto(Listaproduto *listaproduto);

Listaproduto lerarquivoproduto();

Noproduto* produtocompra(Listaproduto *listaproduto, int cod);

void main_produto();