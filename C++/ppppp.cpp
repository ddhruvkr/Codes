#include <stdio.h>
#include <string.h>

#define MAXN 10003
#define min(a,b) (((a)<(b))?(a):(b))

typedef struct{
  int deg;
  int adj[MAXN];
} Node;
int size;
Node alist[MAXN];
int val[MAXN];
int id;

void addEdge(int x, int y){
  alist[x].adj[alist[x].deg++] = y;
  alist[y].adj[alist[y].deg++] = x;
}

void clearList(){
  memset(alist, 0, sizeof(alist));
}

int visit(int x, int root){
  int i, y, m, res, child = 0;

  res = val[x] = ++id;
  for(i = 0; i < alist[x].deg; i++){
    y = alist[x].adj[i];
    if(!val[y]){
      if(root && ++child > 1) size++;
      m = visit(y, 0);
      res = min(res, m);
      if(m >= val[x] && !root) size++;
    } else {
      res = min(val[y], res);
    }
  }
  return res;
}

void articulate(int n){
  int i;

  //memset(ART, 0, sizeof(ART));
  memset(val, 0, sizeof(val));
  for(id = i = 0; i < n; i++)
    if(!val[i]) visit(i, 1);
}

int main(){
	size=0;
  int i, n, m, x, y, found,ans;
  scanf("%d %d", &n, &m);
  /* Read in number of vertices, number of edges */
  while( n&&m){

    /* Read in edge between node x and node y */
    for(i = 0; i < m; i++){
      scanf("%d %d", &x, &y);
      addEdge(x-1,y-1);
    }

    /* Find articulation points */
    articulate(n);
     printf("%d\n",size) ;
    scanf("%d %d", &n, &m);

    clearList();
  }
  return 0;
}




