// ПРАКТИЧЕСКАЯ РАБОТА № 4 — ЗАДАНИЕ ПОВЫШЕННОЙ ТРУДНОСТИ 2
// Конкретно: распределение переменных по минимальному числу регистров через точную раскраску графа несовместимости.
// Стандарт языка: C++17. Исходные данные графа заданы в коде согласно отчёту.

#include <bits/stdc++.h>
using namespace std;
int main(){vector<string>v={"x1","x2","x3","x4","x5","x6"};vector<pair<int,int>>e={{0,1},{0,2},{0,3},{1,2},{1,4},{2,5},{3,4},{3,5},{4,5}};int n=v.size();bool a[6][6]={};for(auto [u,w]:e)a[u][w]=a[w][u]=true;
 for(int k=1;k<=n;k++){vector<int>c(n,0);function<bool(int)>dfs=[&](int pos){if(pos==n)return true;for(int col=1;col<=k;col++){bool ok=true;for(int j=0;j<pos;j++)if(a[pos][j]&&c[j]==col){ok=false;break;}if(ok){c[pos]=col;if(dfs(pos+1))return true;c[pos]=0;}}return false;};if(dfs(0)){cout<<"Минимальное число регистров: "<<k<<"\n";for(int col=1;col<=k;col++){cout<<"Регистр "<<col<<": ";for(int i=0;i<n;i++)if(c[i]==col)cout<<v[i]<<" ";cout<<"\n";}return 0;}}
}
