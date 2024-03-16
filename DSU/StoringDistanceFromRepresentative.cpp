vector<pair<int,int>>parent(n);
vector<int>rank(n);

void make_set(int n)
{
  for(int i=0;i<n;i++)
    {
      parent[i]= {i,0};
      rank[i]=0;
    }
}

pair<int,int>find_set(int i)
{
  if(parent[i].first!= i)
  {
    int len = parent[i].second;
    // if we do not store the length i.e the distance from the representative, then we have to make recursive calls
    // to find the distance from them
    return parent[i]= find_set(parent[i].first)
    parent[i].second+= len;
  }
  return parent[i];
}

void union_set(int a,int b)
{
  int a= find_set(a).first;
  int b= find_set(b).first;

  if(a!=b)
  {
    if(rank[a]<rank[b])
      swap(a,b);
    parent[b]= {a,1};
    if(rank[a]==rank[b])
      rank[a]++;
  }  
}
