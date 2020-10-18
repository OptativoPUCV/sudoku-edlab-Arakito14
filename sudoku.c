#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h" 

typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}


bool comp_linea_columna(int i,int j,Node*n){
    
  int k;
  int f=0;
  for(k=0;k<9;k++){

    if(n->sudo[i][j]==n->sudo[k][j]){
      f++;
    }

    if(n->sudo[i][j]==n->sudo[i][k]){
      f++;
    }
  }
  printf("%d  ",n->sudo[i][j+1]);
  if(f<3){
    return true;
  }else{
    return false;
  }
}

bool  comp_cuadrante(int i,int j, Node* n){
  int k,l,cua,p,comp=0;
  for(cua=0;cua<9;cua++){
    for(p=0;p<9;p++){
      k=3*(cua/3) + (p/3) ;
      l=3*(cua%3) + (p%3) ;
      if(k==i && l==j){
        break;
      }
    }
  }

  for(k=3*(cua/3);k<3*(cua/3)+3;k++){
    for(l=3*(cua%3);l<3*(cua%3)+3;l++){
      if(n->sudo[i][j]==n->sudo[k][l]){
        comp++;
      }if(comp>=2){
        return false;
      }
    }
  }
  return true;
}

int is_valid(Node* n){
  int i;
  int j;
  for(i=1;i<9;i++){
    for(j=0;j<9;j++){
      if(true == comp_linea_columna(i,j,n) && true == comp_cuadrante(i,j,n)){
        return 1;
      }else{
        return 0;
      }
    }
  }
  return 0;
}


List* get_adj_nodes(Node* n){
  List* lista=createList();
  int k,l,cua,num,cont=0;
  for(cua=0;cua<9;cua++){
    for(k=3*(cua/3);k<3*(cua/3)+3;k++){
      for(l=3*(cua%3);l<3*(cua%3)+3;l++){
        if(n->sudo[k][l]==0){
          for(num=1;num<10;num++){
            n->sudo[k][l]=num;
            if(is_valid(n)){
              Node* aux = copy(n);
              pushBack(lista, aux);
              cont++;
            }
            if(cont>2){
              break;
            }
          }
        return lista;
        }
      }
    }
  }
  return lista;
}

int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/