int find_set(int a)
{
  if(a== parent[a])
    return a;
  return parent[a]= find_set(parent[a]);
}
//This is O(logn) approach to find the parent


//Now the easy trick to remember, the one which has got a bigger size or has more depth will remain as the 
//parent


//This is union by the size of a set
void make_set(int a)
{
  parent[a]=a;
  size[a]=1;
}

void union_set(int a,int b)
{
  a= find_set(a);
  b= find_set(b);

  if(a!=b)
  {
    if(size[a]<size[b])
      swap(a,b);
    parent[b]=a;
    size[a]+=size[b];
  }
}

//This is union by rank of a set
void make_set(int a)
{
  parent[a]=a;
  rank[a]=0;
}

void union_set(int a,int b)
{
  a= find_set(a);
  b= find_set(b);

  if(a!=b)
  {
    if(rank[a]<rank[b])
      swap(a,b);
    parent[b]=a;
    if(rank[a]==rank[b])
      rank[a]++;
  }
}


//combining both will give a constant time algorithm
