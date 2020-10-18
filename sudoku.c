#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

bool comp_linea_columna(Node* n);
//bool  comp_cuadrante(Node* n);
int is_valid(Node* n);
int is_final(Node* n);
List* get_adj_nodes(Node* n);
Node* DFS(Node* initial, int* cont);

bool comp_linea_columna(Node* n){
  int i,j,num,k;//pos;
  int comp[10];
  for(i=0;i<9;i++){
    for(k=0;k<10;k++){
      comp[k]=0;
    }
    for(j=0;j<9;j++){
      for(num=1;num<10;num++){
	      if(num == n->sudo[i][j]){ //|| num == n->sudo[j][i]){
          //("%d-",num);
		      if(comp[num]==1){
            printf("fail %d -",num);
			      return false;
          }
		      else{
            //printf("suc %d -", num);
			      comp[num] = 1;
          }
        }
      }
		}
  }
  return true;
  //printf("%d  ",n->sudo[i][j]);
}

/*bool  comp_cuadrante(Node* n){
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
}*/

int is_valid(Node* n){
  if(true == comp_linea_columna(n)){
    return 1;
  }else{
    return 0;
  }
  /*&& true == comp_cuadrante(i,j,n)){*/
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
  /*Stack* S = createStack();
  push(S,initial);

  while(get_size(S)!=0){
    Node* n = (S);
    
    if(is_final(n)){
      return n;
    }
    
    List* adj = get_adj_nodes(n);
    Node* aux = first(adj);
    while(aux){
      push(S,aux);
      aux=next(adj);
    }
    
    free(n);
  }*/
  
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