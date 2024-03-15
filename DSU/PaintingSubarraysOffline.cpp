//Problem-
//We have a segment of length  
//L , each element initially has the color 0. We have to repaint the subarray  
//[l, r] with the color  
//c  for each query  
//(l, r, c) . At the end we want to find the final color of each cell. 
//We assume that we know all the queries in advance, i.e. the task is offline.


// 1)Here the parent of a indice is the first next indice which is not painted yet
// 2)We will start from the last query, so that in each query we encounter, we have to paint only the 
// indices that are left in the subarray (l,r)
// 3)Here we will not use union by size/rank

void make_set(int n)
{
  parent[n]=n;
}

void paint()
{
  for(int i=q;i>=0;i--)
    {
      int l= query[i].l;
      int r= query[i].r;
      int c= query[i].c;
      for(int v=find_set(l);v<=r;v=find_set(v))
        {
          color[v]= c;
          parent[v]= v+1;
        }
      
    }
}
