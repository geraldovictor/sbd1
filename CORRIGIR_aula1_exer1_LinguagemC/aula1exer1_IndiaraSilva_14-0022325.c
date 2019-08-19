#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char modelo[20];
    char marca[20];
    char renavam[11];
    char cor[10];
}carro;

typedef struct{
    char nome[35];
    char cpf[11];
    char data_nascimento[9];
    carro Carro;
} proprietario;

void abre(FILE **arq){
    *arq = fopen("cadastro.txt", "a");
    if (*arq == NULL){
       printf("Problemas na abertura do arquivo\n");
       return;
    }
}

void apaga(FILE **arq){
  *arq = fopen("cadastro.txt","w");
  if (*arq == NULL){
     printf("Problemas na abertura do arquivo\n");
     return;
  }
}

void mostra(FILE **arq){
  char Linha[100];
  char *result;
  *arq = fopen("cadastro.txt", "rt");
  if (*arq == NULL){
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  while (!feof(*arq)){
    result = fgets(Linha, 100, *arq);
    if (result)
    printf("%s",Linha);
  }
  fclose(*arq);
}

void menu(){
  printf("*** Menu ***\n");
  printf("1) Cadastrar Carro.\n");
  printf("2) Exibir Cadastros.\n");
  printf("3) Apagar (isso apagará todo conteúdo do arquivo).\n");
  printf("4) Sair.\n");
}

int main(void){

  int i = 0, n = 1, j=0;
  int opc_num;
  proprietario *p;
  p = malloc(n*sizeof(proprietario));
  proprietario *p;
  c = malloc(n*sizeof(carro));
  int qtd_carro;
  FILE *arq = NULL;
  char opc_letra;

    do{
      menu();
      scanf("%d",&opc_num);
      if(opc_num<0||opc_num>4){
        printf("Digite uma opção válida!!!\n");
      }
      if(opc_num==1){
        abre(&arq);
        printf("Insira nome do proprietário: ");
        scanf(" %[^\n]", p[j].nome);
        scanf("%*[^\n]"); scanf("%*c");
        printf("Insira o CPF do proprietário: ");
        scanf(" %s", p[j].cpf);
        printf("Insira a data de nascimento do proprietário: ");
        scanf(" %s", p[j].data_nascimento);
        printf("Quantos carros deseja cadastrar: ");
        scanf("%d",&qtd_carro);
        fprintf(arq, "Nome do proprietário: %s\nCPF do proprietário: %s\nData de nascimento do proprietário: %s\n", p[j].nome, p[j].cpf, p[j].data_nascimento);
        fprintf(arq, "----------------\n");
        printf("Cadastro do carro:\n");
        for(i = 0; i < qtd_carro; i++){
          printf("Insira o modelo do carro nº %d: ", i+1);
          scanf(" %s", c[i].modelo);
          printf("Insira a marca do carro nº %d: ",i+1);
          scanf(" %s", c[i].marca );
          printf("Insira a cor do carro nº %d: ",i+1);
          scanf(" %s", c[i].cor);
          printf("Insira o renavam do carro nº %d: ",i+1);
          scanf(" %s: ", c[i].renavam );
          fprintf(arq, "\n");
          fprintf(arq, "Carro nº:%d\nCor:%s\nMarca:%s\nModelo:%s\nRenavam:%s\n", i+1, c[j].cor, c[j].marca, c[j].modelo, c[j].renavam);
          fprintf(arq, "----------------\n");
        }
        printf("Dados salvos no arquivo com sucesso!\n");
        fclose(arq);
        n++;

        // p = realloc(p, j*sizeof(struct proprietario));
        // c = realloc(c, j*sizeof(struct proprietario));

      }
      if(opc_num==2){
        mostra(&arq);
      }
      if(opc_num==3){
        printf("Deseja remover todo conteúdo do arquivo?: [s/n]\n");
        scanf(" %c",&opc_letra);
        while (opc_letra!='s'&&opc_letra!='n') {
          printf("Insira 's' ou 'n'\n");
          scanf(" %c",&opc_letra);
        }
        if(opc_letra=='s'){
          apaga(&arq);
        }
      }
    }while(opc_num!=4);
    return 0;
}
