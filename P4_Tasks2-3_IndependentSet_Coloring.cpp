// ПРАКТИЧЕСКАЯ РАБОТА № 4 — ЗАДАНИЯ 2 И 3
// Конкретно: задание 2 — приближённое максимальное независимое множество; задание 3 — раскраска графа алгоритмом Вельша—Пауэлла.
// Стандарт языка: C++17. Исходные данные графа заданы в коде согласно отчёту.

#include <bits/stdc++.h>
using namespace std;
int main(){vector<string>v={"A","B","C","D","E","F"};vector<pair<int,int>>edges={{0,1},{0,2},{0,3},{1,3},{1,4},{2,3},{2,4},{3,4},{4,5}};int n=v.size();vector<vector<int>>g(n,vector<int>(n));for(auto [a,b]:edges)g[a][b]=g[b][a]=1;
 vector<int>deg(n);for(int i=0;i<n;i++)deg[i]=accumulate(g[i].begin(),g[i].end(),0);vector<bool>removed(n),inSet(n);cout<<"Начальные степени: ";for(int i=0;i<n;i++)cout<<v[i]<<"="<<deg[i]<<" ";cout<<"\n";
 while(true){int pick=-1,best=INT_MAX;for(int i=0;i<n;i++)if(!removed[i]&&deg[i]<best){best=deg[i];pick=i;}if(pick==-1)break;cout<<"Выбираем "<<v[pick]<<" (степень "<<deg[pick]<<")\n";inSet[pick]=true;removed[pick]=true;for(int j=0;j<n;j++)if(g[pick][j]&&!removed[j]){removed[j]=true;cout<<"  удаляем соседнюю "<<v[j]<<"\n";}for(int i=0;i<n;i++)if(!removed[i]){deg[i]=0;for(int j=0;j<n;j++)if(!removed[j]&&g[i][j])deg[i]++;} }
 cout<<"Независимое множество: ";for(int i=0;i<n;i++)if(inSet[i])cout<<v[i]<<" ";cout<<"\n\nWelsh-Powell:\n";
 vector<int>order(n);iota(order.begin(),order.end(),0);sort(order.begin(),order.end(),[&](int a,int b){int da=accumulate(g[a].begin(),g[a].end(),0),db=accumulate(g[b].begin(),g[b].end(),0);return da!=db?da>db:v[a]<v[b];});cout<<"Порядок: ";for(int x:order)cout<<v[x]<<" ";cout<<"\n";vector<int>color(n,0);int c=0;for(int x:order)if(!color[x]){++c;color[x]=c;for(int y:order)if(!color[y]){bool ok=true;for(int z=0;z<n;z++)if(color[z]==c&&g[y][z])ok=false;if(ok)color[y]=c;}}
 for(int col=1;col<=c;col++){cout<<"Цвет "<<col<<": ";for(int i=0;i<n;i++)if(color[i]==col)cout<<v[i]<<" ";cout<<"\n";}cout<<"χ(G) по алгоритму = "<<c<<"\n";}
