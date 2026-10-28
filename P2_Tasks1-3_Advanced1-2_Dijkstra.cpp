// ПРАКТИЧЕСКАЯ РАБОТА № 2 — АЛГОРИТМ ДЕЙКСТРЫ
// Конкретно: задания 1, 2, 3 и задания повышенной трудности 1, 2. Программа рассчитывает кратчайшие пути по заданным графам.
// Стандарт языка: C++17. Исходные данные графа заданы в коде согласно отчёту.

#include <bits/stdc++.h>
using namespace std;
using Edge = pair<int,int>;

void dijkstra(const string& title, const vector<string>& names,
              const vector<tuple<int,int,int>>& edges, int source, int target=-1) {
    int n=(int)names.size(); vector<vector<Edge>> g(n);
    for(auto [u,v,w]:edges) g[u].push_back({v,w});
    const long long INF=(1LL<<60); vector<long long>d(n,INF); vector<int>p(n,-1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    d[source]=0; pq.push({0,source});
    while(!pq.empty()) { auto [du,u]=pq.top();pq.pop(); if(du!=d[u])continue;
        for(auto [v,w]:g[u]) if(d[v]>du+w){d[v]=du+w;p[v]=u;pq.push({d[v],v});}
    }
    cout<<"\n"<<title<<"\n";
    for(int i=0;i<n;i++) cout<<names[source]<<" -> "<<names[i]<<": "<<(d[i]==INF?string("нет пути"):to_string(d[i]))<<"\n";
    auto printPath = [&](int v) {
        if(d[v]==INF){ cout << "нет пути"; return; }
        vector<int> path;
        for(int x=v; x!=-1; x=p[x]) path.push_back(x);
        reverse(path.begin(),path.end());
        for(int i=0;i<(int)path.size();i++){ if(i) cout << " -> "; cout << names[path[i]]; }
    };
    if(target>=0 && d[target]!=INF){ cout << "Кратчайший путь: "; printPath(target); cout << "; длина = " << d[target] << "\n"; }
    else if(target<0){
        cout << "Маршруты кратчайших путей от источника:\n";
        for(int i=0;i<n;i++){ cout << names[i] << ": "; printPath(i); cout << " (длина " << (d[i]==INF?string("∞"):to_string(d[i])) << ")\n"; }
    }
}
int main(){
    // Тетрадь 2, задание 1. Рёбра переписаны по рисунку; направление сохраняется.
    dijkstra("Тетрадь 2 — задание 1", {"1","2","3","4","5","6"},
      {{0,1,1},{1,2,4},{2,0,2},{0,3,7},{3,4,1},{4,5,5},{2,3,13},{4,2,12},{5,2,2}},0,5);
    // Тетрадь 2, задание 2: неориентированный граф, каждое ребро записано в обе стороны.
    dijkstra("Тетрадь 2 — задание 2", {"1","2","3","4","5","6"},
      {{0,1,3},{1,0,3},{1,2,1},{2,1,1},{0,3,7},{3,0,7},{0,4,8},{4,0,8},{1,3,4},{3,1,4},{3,2,2},{2,3,2},{2,5,3},{5,2,3},{3,5,4},{5,3,4},{4,3,3},{3,4,3},{4,5,9},{5,4,9}},0,5);
    // Тетрадь 2, задание 3.
    dijkstra("Тетрадь 2 — задание 3", {"S","A","B","C","T"},
      {{0,1,5},{0,2,10},{1,3,3},{1,4,12},{2,3,2},{3,4,4}},0,4);
    // Повышенная сложность 1.
    dijkstra("Тетрадь 2 — повышенная сложность 1", {"S","A","B","C","D","E","F","G"},
      {{0,1,10},{0,2,15},{1,3,12},{1,4,15},{2,5,10},{3,6,5},{4,6,10},{5,7,5},{6,7,10},{4,7,20}},0);
    // Повышенная сложность 2: неориентированный граф.
    vector<tuple<int,int,int>> e={{0,1,4},{1,0,4},{0,2,3},{2,0,3},{0,3,7},{3,0,7},{1,4,4},{4,1,4},{1,3,6},{3,1,6},{2,5,3},{5,2,3},{2,6,4},{6,2,4},{3,6,11},{6,3,11},{4,5,7},{5,4,7},{4,7,4},{7,4,4},{5,7,8},{7,5,8},{6,7,5},{7,6,5}};
    dijkstra("Тетрадь 2 — повышенная сложность 2", {"1","2","3","4","5","6","7","8"},e,0,7);
}
