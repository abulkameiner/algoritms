// ПРАКТИЧЕСКАЯ РАБОТА № 4 — ЗАДАНИЕ ПОВЫШЕННОЙ ТРУДНОСТИ 1
// Конкретно: модель Барабаши—Альберт (предпочтительное присоединение), построение сети и поиск пяти наиболее крупных хабов.
// Стандарт языка: C++17. Исходные данные графа заданы в коде согласно отчёту.

#include <bits/stdc++.h>
using namespace std;
int main(){const int m0=3, added=1000, m=2;mt19937 rng(42);int n=m0+added;vector<vector<int>>g(n);vector<int>deg(n,0);auto add_edge=[&](int u,int v){g[u].push_back(v);g[v].push_back(u);deg[u]++;deg[v]++;};add_edge(0,1);add_edge(0,2);add_edge(1,2);
 for(int v=m0;v<n;v++){set<int>chosen;while((int)chosen.size()<m){long long sum=0;for(int u=0;u<v;u++)sum+=deg[u];uniform_int_distribution<long long>dist(1,sum);long long ticket=dist(rng);int target=-1;for(int u=0;u<v;u++){ticket-=deg[u];if(ticket<=0){target=u;break;}}if(target>=0)chosen.insert(target);}for(int u:chosen)add_edge(v,u);}
 vector<pair<int,int>>ranked;for(int i=0;i<n;i++)ranked.push_back({deg[i],i});sort(ranked.rbegin(),ranked.rend());cout<<"Всего вершин: "<<n<<"\nТоп-5 хабов (вершина: степень):\n";for(int i=0;i<5;i++)cout<<ranked[i].second+1<<": "<<ranked[i].first<<"\n";}
