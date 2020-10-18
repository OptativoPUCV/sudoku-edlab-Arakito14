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

/* StArT HeRe */

bool compare(Node* n);
int is_valid(Node* n);
int is_final(Node* n);
List* get_adj_nodes(Node* n);
Node* DFS(Node* initial, int* cont);

/*void print_test(Node* n){
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      printf("%d ",n->sudo[i][j]);
      if(j%9 == 8) printf("\n");
    }
  }
  printf("\n");
}*/

bool compare(Node* n){
  int i,j,num,k;//pos;
  int comp_linea[10];
  int comp_columna[10];
  //int comp_cuadrante[10];
  for(i=0;i<9;i++){
    for(k=0;k<10;k++){
      comp_linea[k]=0;
      comp_columna[k]=0;
      //comp_cuadrante[k]=0;
    }
    for(j=0;j<9;j++){
      for(num=1;num<10;num++){
	      if(num == n->sudo[i][j]){
		      if(comp_linea[num]==1){
			      return false;
          }
		      else{
			      comp_linea[num] = 1;
          }
        }
        if(num == n->sudo[j][i]){
          if(comp_columna[num]==1){
			      return false;
          }
		      else{
			      comp_columna[num]=1;
          }
        }
      }
		}
  }
  return true;
}

int is_valid(Node* n){
  if(true == compare(n)){
    return 1;
  }else{
    return 0;
  }
}


List* get_adj_nodes(Node* n){
  List* lista=createList();
  int i,j,num,cont=0;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        for(num=1;num<10;num++){
          n->sudo[i][j]=num;
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
      //printf("%d ",n->sudo[i][j]);
      //if(j%9 == 8) printf("\n");
    }
  }
  return lista;
}

int is_final(Node* n){
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        return 0;
      }
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack* S = createStack();
  push(S,initial);

  while(get_size(S)!=0){
    Node* n = top(S);
    pop(S);
    //push(S,n);
    
    if(is_final(n)){
      print_node(n);
      //printf("fail");
      return n;
    }
    
    List* adj = get_adj_nodes(n);
    Node* aux = first(adj);
    while(aux){
      push(S,aux);
      aux=next(adj);
    }
    
    cont++;
    free(n);
    free(aux);
  }
  
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