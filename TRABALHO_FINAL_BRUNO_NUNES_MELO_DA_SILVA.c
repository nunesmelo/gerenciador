#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100


struct matricula
{
    long int matricula;                                 
    char nome[81];
    char curso[10]; 
     long int medias;
     long int faltas;
     long int nota, a, b, c;      
    struct matricula *next;  
}; struct matricula *raiz;

  

void adiciona(){


    struct matricula *novoreg=(struct matricula*)malloc(sizeof(struct matricula));
    if(novoreg==NULL){printf("Memoria insuficiente!"); exit(1);}
    printf("\nInforme a matricula do aluno: ");
    scanf("%d",&novoreg->matricula);
    getchar();
    printf("Informe o nome: ");
    gets(novoreg->nome);    
    printf("\nInforme seu curso:");
    gets(novoreg->curso);
    novoreg->next=raiz->next;
    raiz->next=novoreg;

   
}

void inser_nota(){
     int nota,a,b,c,medias;
     
     struct matricula *nov_nota=(struct matricula*)malloc(sizeof(struct matricula));
     if(nov_nota==NULL){printf("Memoria insuficiente!"); exit(1);}
     printf("informe a nota:");
     scanf("%d%d%d",&nov_nota->a,&nov_nota->b,&nov_nota->c);
     getchar();
     medias = (a*4+b*5+c*6)/15;
     printf(" media: %d\n",medias);
     
    nov_nota->next=raiz->next;
     raiz->next=nov_nota;

}

void inser_faltas(){
     
     struct matricula *nov_falta=(struct matricula*)malloc(sizeof(struct matricula));
     if(nov_falta==NULL){printf("Memoria insuficiente!"); exit(1);}
     printf("informe o numero de faltas:");
     scanf("%d",&nov_falta->faltas);
     getchar();
    
    nov_falta->next=raiz->next;
     raiz->next=nov_falta;

}



void exclui()
{
    struct matricula *mat_atual, *mat_ant;
    long int matric;
    mat_atual=raiz->next;
    mat_ant = raiz;   
    printf("\nInforme a matricula do funcionario que sera excluido: ");
    scanf("%d",&matric);    
    while(mat_atual!=NULL)
    {
        if(matric==mat_atual->matricula)
        {
            mat_ant->next=mat_atual->next;
            printf("\nMatricula excluida com sucesso!");
            free(mat_atual);
            return;
        }
        mat_ant = mat_atual;
        mat_atual=mat_atual->next;
    }       
    printf("Matricula nao encontrada!\n");
}




void imp_lista()
{
    struct matricula *lista;
    lista=raiz->next;
    
    if(lista==NULL)
    {
        printf ("\n\n\a\a\a\a\tLista Vazia\n");
    
        system ("pause");
        exit(1);
    }
    else
    {
        while(lista!=NULL )
        {
            printf("\nMatricula: %d",lista->matricula);
            printf("\naluno: %s",lista->nome);
            printf("\ncurso:%s",lista->curso);
            printf("\nfaltas:%d",lista->faltas);
            printf("\nmedia:%d",lista->medias);
                      
            lista=lista->next;
        }
    }
}

void imp_medias(){
     struct matricula *media;
    
     media=raiz->next;
     
       if(media==NULL)
    {
        printf ("\n\n\a\a\a\a\tinsira a media dos alunos!\n");
    
        system ("pause");
        exit(1);
    }
    else
    {
        while(media!=NULL)
        {
     if (media->matricula>=7){
            
            printf("\nmedia:%d",media->matricula);
            printf("\naprovado!!:)");          
            media=media->next;
            }if(media->matricula<7 && media->matricula>3){           
            printf("\nmedia:%d",media->matricula);
            printf("\nrecuperaçao");          
            media=media->next;    
            }else printf("REPROVADO\n");
            media=media->next;       
       
       
        }
    }

}


void apro_medias(){
     struct matricula *media;
    
     media=raiz->next;
     
       if(media==NULL)
    {
        printf ("\n\n\a\a\a\a\talunos aprovados!\n");
    
        system ("pause");
        exit(1);
    }
    else
    {
        while(media!=NULL)
        {
     if (media->matricula>=7){
            
            printf("\nmedia:%d",media->matricula);
            printf("\naprovado!!:)");          
            media=media->next;
            }else 
            media=media->next;       
       
       
        }
    }

}


void repro_medias(){
     struct matricula *media;
    
     media=raiz->next;
     
       if(media==NULL)
    {
        printf ("\n\n\a\a\a\a\tinsira a media dos alunos!\n");
    
        system ("pause");
        exit(1);
    }
    else
    {
        while(media!=NULL)
        {
     if (media->matricula<=3){
            printf("REPROVADO :(\n");
            media=media->next;       
       
       
        }
    }

}


}

int main(int argc, char *argv[])
{
  char disciplina[max],op1,op2,horario[14];
  char carga_horaria[max],professor[20],sala[20];
  char aluno[max][3],nome[max],curso[10],lista[max];
  int num,i,j,matricula;
  int op=3,nota,a,b,c;
  raiz=(struct matricula *)malloc(sizeof (struct matricula));
  if(raiz==NULL) exit(1);
  raiz->next=NULL;
  
          
           printf(" - - - SISTEMA DE GERENCIAMENTO DE TURMA - - - \n\n\n");
           printf(" [CADASTRAMENTO DE TURMA]\n\n");
           printf("nome do professor:");
           scanf("%s",professor);
           fflush(stdin);
           printf("Nome da Disciplina:");
           scanf("%s",disciplina);
           fflush(stdin);        
           printf("sala,ex:LCM/3H7:");
           scanf("%s",sala);
           fflush(stdin);
           printf("Carga Horária (Horas):");
           scanf("%d",&carga_horaria);
           fflush(stdin);
           printf("Horario(ex.:24M12):"); 
           scanf("%s",horario);
           fflush(stdin);
do{
      printf("----------MENU DE GERENCIAMENTO-----------\n\n\n");
  
      printf("1-GERENCIAR INFORMACOES DA TURMA;\t5-INSERIR FALTAS;\n2-CADASTRAR ALUNO;\t\t\t6-INSERIR NOTAS;\n3-REMOVER ALUNO;\t\t\t7-LISTAR ALUNOS;\n4-EDITAR INFORMACOES DO ALUNO;\t\t8-SAIR DO PROGRAMA.\n\n\n");
  
  
      while(op1 != '8'){
            scanf("%c",&op1); 
            fflush(stdin);  

    switch (op1){
                   case '1':
            printf("novo professor:");
            scanf("%s",professor);
            fflush(stdin);  
            printf("novo nome da disciplina:");
            scanf("%s",disciplina);
            fflush(stdin);
            printf("novo horario:");
            scanf("%s",horario);
            fflush(stdin);
            printf("nova carga horaria:");
            scanf("%d",&carga_horaria);           
            fflush(stdin);
            printf("nova sala,ex:LCM/3H7:");
            scanf("%s",sala);
            fflush(stdin);                             break;
             
                   case '2': 
            printf("caro professor informe o numero de alunos a serem cadastrados:");
            scanf("%d",&num);
            fflush(stdin);
            for(i=0;i<num;i++){
            adiciona();
            }
                  
                 
                                                       break;
           
                   case '3':
                    
                    while(op!=3){
                      
                       printf("DIGITE: 1 para excluir, 2 para listar os alunos a serem removidos e 3 para sair: ");
        scanf("%d",&op);
        
        if(op==1)exclui();
        else if(op==2)imp_lista();
        else if(op==3)exit(1);
        printf("\n");    
        free(raiz);
        }                                                  break;
                  
                  
                  
                   case '4':
                       
                        printf("EDITAR INFORMAÇOES DA TURMA\n\n");                    
                        
                        
                         do{
                       printf("Digite 1 para adicionar uma nova matricula, 2 para excluir, 3 para listar e 4 para sair: ");
        scanf("%d",&op);
        if(op==1)adiciona();
        else if(op==2)exclui();
        else if(op==3)imp_lista();
        else if(op==4)exit(1);
        printf("\n");
    }while(op!=4);
    free(raiz);                                        break;
    
                   case '5': 
                        do{
                        printf("1-inserir faltas sequencialmente:\t\t2-listar alunos\t\t3-sair");
                   
                        scanf("%d",&op);
                         if(op==1) inser_faltas();
                         else if(op==2) imp_lista();
                         else if(op==3)exit(1);
                         printf("\n");
                         }while(op!=4);
                         free(raiz);                   break;
                        
                        
                          
                   case '6':
                       
                  
                        do{
                    
                       printf("Digite 1 para adicionar notas sequencialmente, 2 para excluir, 3 para listar e 4 para sair: ");
        scanf("%d",&op);
        if(op==1)inser_nota();
        else if(op==2)exclui();
        else if(op==3)imp_lista();
        else if(op==4)exit(1);
        printf("\n");
    }while(op!=4);
    free(raiz);                                        break;
                           
                        
                   case '7':
                        
                        while(op!=6){
                    
printf("1-para listar todos os alunos (matricula/nome/curso)\n 2-listar todos os alunos (matricula,nome,media,situaçao[aprovado|reprovado|recuperacao]\n 3-listar todos os alunos com suas respectivas faltas\n 4-listar alunos reprovados por media\n 5-listar alunos aprovados por media\n 6-sair");



        scanf("%d",&op);
        if(op==1)imp_lista();
        else if(op==2)imp_medias();
        else if(op==3)imp_lista();
        else if(op==4)repro_medias();
        else if(op==5)apro_medias();
       
        else if(op==6)exit(1);
        printf("\n");
        
}free(raiz);                                           break;
                          
                 case '8':break;
  
  
  default:  printf("((%s)) - %s - %d - %s - \n",disciplina,horario,carga_horaria,sala);
            printf("%s\n\n",professor);
           
          
          printf("----------MENU DE GERENCIAMENTO-----------\n\n\n");
          printf("1-GERENCIAR INFORMACOES DA TURMA;\t5-INSERIR FALTAS;\n2-CADASTRAR ALUNO;\t\t\t6-INSERIR NOTAS;\n3-REMOVER ALUNO;\t\t\t7-LISTAR ALUNOS;\n4-EDITAR INFORMACOES DO ALUNO;\t\t8-SAIR DO PROGRAMA.\n\n\n");
          break;                                           
                         } 
                                          
        } 
  
}while(op1 != '8');
  
  
  printf("REFERENCIA BIBLIOGRAFICA :   http://lucianasondermann.blogspot.com/2011/05/lista-encadeada-em-c-matricula-e-nome.html\n");
  printf("Programação de Computadores I ||Faculdade de Computação || UFMS");
   
  system("PAUSE");	
  return 0;
}














