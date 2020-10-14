#include <stdio.h>
#include <stdlib.h>
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

/*int comp_linea_columna(int i,int j,Node* n){    
  int k;
  int f=0;
  for(k=0;k<9;k++){
    if(n[i][j]==n[k][j]){
      f++;
    }
    if(n[i][j]==n[i][k]){
      f++;
    }
  }

  if(f<=2){
    return 0;
  }else{
    return 1;
  }

}*/

int is_valid(Node* n){
  /*int i;
  int j;
  int valido=0;
    
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      valido=valido+comp_linea_columna(i,j,n);
      valido=valido+comp_cuadrante(i,j,n);
      if(valido>=1){
        return 0;
      }
    }
  }*/
  return 1;
}


List* get_adj_nodes(Node* n){
  List* lista=createList();
  int i,j;
  int num;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        for(num=1; num <=9; num++){
          n->sudo[i][j]=num;
          if(is_valid(n)){
            Node* aux = copy(n);
            pushBack(lista, aux);
          }
        }
        n->sudo[i][j] = 0;
        return lista;
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