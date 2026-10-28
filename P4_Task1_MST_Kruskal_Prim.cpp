// ПРАКТИЧЕСКАЯ РАБОТА № 4 — ЗАДАНИЕ 1
// Конкретно: минимальное остовное дерево; алгоритмы Краскала и Прима.
// Стандарт языка: C++17. Исходные данные графа заданы в коде согласно отчёту.

#include <bits/stdc++.h>
using namespace std;
struct E{int u,v,w;};
struct DSU{vector<int>p,r;DSU(int n):p(n),r(n){iota(p.begin(),p.end(),0);}int find(int x){return p[x]==x?x:p[x]=find(p[x]);}bool unite(int a,int b){a=find(a);b=find(b);if(a==b)return false;if(r[a]<r[b])swap(a,b);p[b]=a;if(r[a]==r[b])r[a]++;return true;}};
int main(){vector<string>v={"A","B","C","D","E","F"};vector<E>e={{0,1,4},{0,2,7},{0,3,3},{1,2,5},{1,3,2},{1,4,6},{2,3,5},{3,4,2},{3,5,1},{4,5,9}};
 auto es=e;sort(es.begin(),es.end(),[](auto&a,auto&b){return a.w<b.w;});DSU d(v.size());int total=0;cout<<"Kruskal:\n";for(auto x:es)if(d.unite(x.u,x.v)){cout<<v[x.u]<<"-"<<v[x.v]<<" ("<<x.w<<")\n";total+=x.w;}cout<<"Вес MST = "<<total<<"\n\nPrim из A:\n";
 vector<bool>used(v.size());used[0]=true;int total2=0;for(int k=1;k<(int)v.size();k++){E best{-1,-1,INT_MAX};for(auto x:e)if(used[x.u]!=used[x.v]&&x.w<best.w)best=x;used[used[best.u]?best.v:best.u]=true;cout<<v[best.u]<<"-"<<v[best.v]<<" ("<<best.w<<")\n";total2+=best.w;}cout<<"Вес MST = "<<total2<<"\n";}
