### 图Demo

> 图的构造比较麻烦,全部采用伪代码形. 

* 试设计一个算法，判断一个无向图G是否为一棵树。若是一棵树，则算法返回true,否则返回false

  > ``` c
  > //一个无向图G是树的条件是:没有回路的连通图或者是边数为n-1的连通图.
  > //那么可以使用深度优先遍历(DFS),如果一次遍历就能访问到全部的顶点和n-1条边的话,那么就是树
  > bool isTree(Graph G){
  >  	bool visited[G.vexCnt+1];	//访问标记初始化
  > 	for(int i=1;i<=G.vexCnt;i++){
  >   	visited[i]=FALSE;
  > 	}
  >  	int vNum=0,eNum=0;	//记录顶点和边的个数
  >     DFS(G,1,&vNum,&eNum,visited);
  >     //如果访问的顶点数和图的顶点树相同,并且由于是无向图,邻接点的边数是顶点数减1的两倍,
  >     //因为一对邻接点进行访问时,之间的边会访问两次
  >     if(vNum==G.vexCnt&&eNum==2*(G.vexCnt-1)){
  >         return TRUE;
  >     }else{
  >         return FALSE;
  >     }
  > }
  > 
  > void DFS(Graph G, int v, int *vNum, int *eNum, bool *visited){
  >     visited[v]=TRUE;*vNum+=1;	//设置顶点被访问,并且顶点数加一
  >     int w = firstNeighbor(G,v);	//获取与V邻接的第一顶点
  >     while(w!=-1){
  >         *eNum+=1;	//顶点存在,边数加一
  >         if(!visited[w]){
  >             DFS(G,w,vNum,eNum,visited);	//顶点还没被访问,继续递归进行遍历
  >         }
  >         w = nextNeighbor(G,v,w);	//获得下一个邻接点
  >     }
  > }
  > 
  > ```

* 写出图的深度优先搜索$DFS$算法的非递归算法（图采用邻接表形式)

  > ```c
  > //由于使用了栈,这种深度优先遍历是从右到左的
  > void DFSTraverse(Graph G, int v){
  >     int w;	//顶点序号
  >     initStack(S);	//初始化栈
  >     for(int i=0;i<G.vexNum;i++){
  >         visited[i]=FALSE;	//初始化访问标记
  >     }
  >     push(S,v);	//第一个顶点入栈
  >     while(!isEmpty(S)){
  >         int k = pop(S);	//栈中第一个结点出栈
  >         visit(k);visited[k]=TRUE;	//访问并设置访问标记
  >         //依次访问邻接点
  >         for(w = firstNeighbor(G,k);w!=-1;w = nextNeihtbor(G,k,w)){
  >             if(!visited[w]){	//没有访问过的结点,访问,进栈
  >                 visit(w);visited[w]=TRUE;
  >                 push(S,w);
  >             }
  >         }
  >     }
  > }
  > ```

* 分别采用基于深度优先遍历和广度优先遍历算法判别以邻接表方式存储的有向图中是否存在由顶点$v_i$到顶点$v_j$的路径($i \neq j$).注意,算法中涉及的图的基本操作必须在此存储结构上实现。

  > ```c
  > //不管是BFS还是DFS都是直接从i开始遍历然后如果能找到j顶点,那么有路径,否则没有
  > int visited[MAXSIZE]={0};	//初始化标记数组
  > int checkByDFS(Graph G, int i, int j){
  >     if(i==j){
  >         return 1;
  >     }
  >     int w,result=0;
  >     visited[i]=1;	//设置i被访问
  >     for(w = firstNeighbor(G,i);w!=-1;w = nextNeighbor(G,i,w)){
  >         if(visited[w]&&checkByDFS(G,w,j)){	//邻接结点未被访问并且邻接结点有到j的路径
  >             result = 1;
  >         }
  >     }
  >     return result;
  > }
  > 
  > int checkByBFS(Graph G, int i, int j){
  >     initQueue(Q);enQueue(Q,i);	//初始化队列,并且将顶点入队
  >     while(!isEmpty(Q)){
  >         int node = deQueue(Q);
  >         visited[node]=1;	//设置结点被访问
  >         for(int w = firstNeighbor(G,node);w!=-1;w = nextNeighbor(G,node,w)){	//检查所有邻接点
  >             if(w==j){	//找到j结点,直接返回
  >                 return 1;
  >             }
  >             if(!visited[w]){	//如果结点没有被访问就入队
  >                 enQueue(Q,w);
  >             }
  >         }
  >     }
  > }
  > ```

* 假设图用邻接表表示，设计一个算法，输出从顶点$V_i$到顶点$V_j$的所有简单路径。

  > ```c
  > //简单路径就是要求顶点不重复的路径,采用递归的深度优先遍历来找到路径,并用一个path[]数组来记录路径,和len长度来记录路径的长度
  > int visited[MAXSIZE]={0};	//初始化标记数组
  > void printPath(ALGraph G, int i, int j, int path[], int len){
  >     ArcNode* p = NULL;	//邻接顶点
  >     path[len++]=i;	//将当前顶点添加到路径数组中,并且路径长度加一
  >     visited[i]=1;	//设置当前顶点已被访问,保证每次递归的时候顶点不会被重复访问
  >     if(i==j){
  >         print(path,len);	//找到路径,进行输出并返回上一层
  >         return;
  >     }
  >     p = G.vertices[i].first;
  >     while(p!=NULL){
  >         if(visited[p.adjvex]==0){	//如果顶点没有被访问过就继续递归
  >             printPath(G,p.adjvex,j,path,len);
  >         }
  >         p = p.next;
  >     }
  >     visited[i]=0;	//回溯,邻接点全部递归完成后,设置顶点可被访问,以便上层递归的顶点继续遍历到
  > }
  > ```
