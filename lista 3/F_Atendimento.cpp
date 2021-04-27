#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define ii pair<int, int>

// struct funcionario {
//   int value, free = 0, id;
// };

// bool compare(struct funcionario e1, struct funcionario e2) {
//   if (e1.free != e2.free)
//     return (e1.free > e2.free);
//   return (e1.id > e2.id);
// }

int main() {
  int m, n, i, aux;
  set<ii> funcionarios;
  ii funcionario_aux;
  map<int, int> mp;

  vi clientes;

  cin >> n >> m;

  for (i = 0; i < n; i++) {
    cin >> aux;
    funcionario_aux = make_pair(0, i);
    mp[i] = aux;
    funcionarios.insert(funcionario_aux);
  }

  for (i = 0; i < m; i++) {
    cin >> aux;
    clientes.push_back(aux);
  }

  for (i = 0; i < m; i++) {
    auto funcionario_ite = funcionarios.begin();
    funcionarios.erase(funcionarios.begin());

    aux = funcionario_ite->first + clientes[i] * mp[funcionario_ite->second];

    funcionarios.insert(make_pair(aux, funcionario_ite->second));
  }

  cout << funcionarios.rbegin()->first << endl;

  return 0;
}