// ПРАКТИЧЕСКАЯ РАБОТА № 3 — МАКСИМАЛЬНЫЙ ПОТОК
// Конкретно: задания 1, 2, 3 и задания повышенной трудности 1–4. Реализация алгоритма Эдмондса—Карпа.
// Стандарт языка: C++17. Исходные данные графа заданы в коде согласно отчёту.

#include <bits/stdc++.h>
using namespace std;
struct EdmondsKarp {
    int n; vector<vector<long long>> cap; vector<vector<int>> adj;
    EdmondsKarp(int n):n(n),cap(n,vector<long long>(n)),adj(n){}
    void add(int u,int v,long long c){ if(!cap[u][v] && !cap[v][u]){adj[u].push_back(v);adj[v].push_back(u);} cap[u][v]+=c; }
    long long run(int s,int t, bool show=false, const vector<string>& names={}){ long long ans=0; int iteration=0;
        while(true){vector<int>p(n,-1);queue<int>q;q.push(s);p[s]=s;
            while(!q.empty()&&p[t]==-1){int u=q.front();q.pop();for(int v:adj[u])if(p[v]==-1&&cap[u][v]>0){p[v]=u;q.push(v);}}
            if(p[t]==-1) break;
            long long add=LLONG_MAX;
            for(int v=t;v!=s;v=p[v]) add=min(add,cap[p[v]][v]);
            for(int v=t;v!=s;v=p[v]){int u=p[v];cap[u][v]-=add;cap[v][u]+=add;}
            ans+=add;iteration++;if(show){vector<int>path;for(int v=t;v!=s;v=p[v])path.push_back(v);path.push_back(s);reverse(path.begin(),path.end());cout<<"  Итерация "<<iteration<<": ";for(int i=0;i<(int)path.size();i++){if(i)cout<<" -> ";if(!names.empty())cout<<names[path[i]];else cout<<path[i];}cout<<", прирост "<<add<<", суммарно "<<ans<<"\n";}
        } return ans;
    }
};
void run_case(string title, vector<string>names,vector<tuple<int,int,int>>edges,int s,int t,bool show=false){EdmondsKarp ek(names.size());for(auto [u,v,c]:edges)ek.add(u,v,c);cout<<"\n"<<title<<"\n";long long value=ek.run(s,t,show,names);cout<<"Максимальный поток = "<<value<<"\n";}
int main(){
 run_case("Тетрадь 3 — задание 1",{"1","2","3","4","5","6"},{{0,1,3},{0,3,5},{3,1,4},{1,2,5},{2,5,5},{2,4,6},{3,4,2},{4,5,7}},0,5,true);
 run_case("Тетрадь 3 — задание 2",{"S","A","B","C","D","E","F","T"},{{0,1,10},{0,2,5},{1,3,8},{2,4,6},{3,4,3},{3,5,6},{4,6,5},{5,6,8},{6,7,10}},0,7,true);
 run_case("Тетрадь 3 — задание 3",{"S","A","B","C","D","E","F","T"},{{0,1,12},{0,2,7},{1,3,5},{2,3,3},{3,4,10},{3,5,6},{4,5,5},{4,6,4},{5,6,5},{6,7,7}},0,7,true);
 run_case("Тетрадь 3 — повышенная сложность 1",{"1","2","3","4","5","6","7","8","9"},{{4,0,41},{0,1,28},{1,2,23},{2,4,23},{2,3,19},{3,4,46},{4,8,21},{3,5,12},{5,8,17},{1,6,5},{2,6,47},{6,7,11},{7,8,43}},0,8,true);
 run_case("Тетрадь 3 — повышенная сложность 2",{"S","A","B","C","D","E","F","G","T"},{{0,1,9},{0,2,7},{1,3,4},{3,5,8},{2,4,6},{4,5,5},{5,6,7},{6,7,6},{7,8,10}},0,8,true);
 run_case("Тетрадь 3 — повышенная сложность 3",{"S","A","B","C","D","E","F","G","H","I","J","K","T"},{{0,1,10},{0,2,15},{1,3,10},{1,4,5},{2,4,10},{2,5,10},{3,6,10},{4,6,10},{4,7,5},{5,7,10},{5,8,5},{6,9,10},{7,9,10},{7,10,5},{8,10,10},{9,11,15},{9,12,5},{10,11,10},{10,12,7},{11,12,10}},0,12,true);
 run_case("Тетрадь 3 — повышенная сложность 4 (Эдмондс–Карп)",{"S","A","B","C","D","T"},{{0,1,10},{0,2,5},{1,3,9},{2,3,4},{2,4,8},{3,5,10},{4,5,10}},0,5,true);
}
