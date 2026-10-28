// ПРАКТИЧЕСКАЯ РАБОТА № 5 — ЗАДАНИЯ 1–3
// Конкретно: задание 1 — DFS и BFS; задание 2 — компоненты связности и проверка двудольности; задание 3 — топологическая сортировка и кратчайший путь в невзвешенном графе.
// Стандарт языка: C++17. Исходные данные графа заданы в коде согласно отчёту.

#include <bits/stdc++.h>
using namespace std;
void dfs(int u,const vector<vector<int>>&g,vector<int>&vis,vector<int>&order){vis[u]=1;order.push_back(u);for(int v:g[u])if(!vis[v])dfs(v,g,vis,order);} 
vector<int>bfs_order(int s,const vector<vector<int>>&g){vector<int>vis(g.size());queue<int>q;vector<int>o;q.push(s);vis[s]=1;while(!q.empty()){int u=q.front();q.pop();o.push_back(u);for(int v:g[u])if(!vis[v])vis[v]=1,q.push(v);}return o;}
int main(){
 // Задание 1, граф 1..10
 vector<vector<int>>g(11);vector<pair<int,int>>e={{1,2},{1,3},{2,4},{2,5},{4,8},{5,8},{3,6},{3,7},{6,9},{7,9},{8,10},{9,10}};for(auto [u,v]:e)g[u].push_back(v),g[v].push_back(u);for(auto&x:g)sort(x.begin(),x.end());vector<int>vis(11),o;dfs(1,g,vis,o);cout<<"Задание 1\nDFS: ";for(int x:o)cout<<x<<" ";cout<<"\nBFS: ";for(int x:bfs_order(1,g))cout<<x<<" ";cout<<"\n";
 // Задание 2: компоненты и двудольность; вершины A..L нумеруются 0..11.
 vector<string>names={"A","B","C","D","E","F","G","H","I","J","K","L"};vector<vector<int>>h(12);auto ae=[&](int a,int b){h[a].push_back(b);h[b].push_back(a);};ae(0,1);ae(0,2);ae(1,2);ae(2,3);ae(4,5);ae(5,6);ae(8,9);ae(9,10);ae(10,11);ae(11,8);
 vector<int>seen(12),col(12,-1);cout<<"Задание 2\n";for(int i=0;i<12;i++)if(!seen[i]){vector<int>comp;queue<int>q;q.push(i);seen[i]=1;col[i]=0;bool bip=true;while(!q.empty()){int u=q.front();q.pop();comp.push_back(u);for(int v:h[u])if(!seen[v])seen[v]=1,col[v]=1-col[u],q.push(v);else if(col[v]==col[u])bip=false;}cout<<"Компонента: {";for(int j=0;j<(int)comp.size();j++){if(j)cout<<", ";cout<<names[comp[j]];}cout<<"}; двудольная: "<<(bip?"да":"нет (содержит треугольник)")<<"\n";}
 // Задание 3: DAG, топологическая сортировка DFS и BFS shortest path A->H.
 vector<string>nv={"A","B","C","D","E","F","G","H"};vector<vector<int>>dag(8);auto de=[&](int u,int v){dag[u].push_back(v);};de(0,1);de(0,2);de(1,3);de(1,4);de(2,4);de(2,5);de(3,6);de(4,6);de(4,7);de(5,6);de(6,7);for(auto&x:dag)sort(x.begin(),x.end());vector<int>state(8),top;function<void(int)>tdfs=[&](int u){state[u]=1;for(int v:dag[u])if(!state[v])tdfs(v);top.push_back(u);};for(int i=0;i<8;i++)if(!state[i])tdfs(i);reverse(top.begin(),top.end());cout<<"Задание 3\nТопологический порядок: ";for(int x:top)cout<<nv[x]<<" ";cout<<"\n";vector<int>p(8,-1);queue<int>q;q.push(0);p[0]=0;while(!q.empty()){int u=q.front();q.pop();for(int v:dag[u])if(p[v]==-1)p[v]=u,q.push(v);}vector<int>path;for(int x=7;x!=0;x=p[x])path.push_back(x);path.push_back(0);reverse(path.begin(),path.end());cout<<"Кратчайший путь A-H: ";for(int i=0;i<(int)path.size();i++){if(i)cout<<" -> ";cout<<nv[path[i]];}cout<<"; длина = "<<path.size()-1<<"\n";
}
