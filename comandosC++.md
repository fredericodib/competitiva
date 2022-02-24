https://github.com/UnBalloon/programacao-competitiva/blob/master/STL/README.md

###  Ordenar um vetor
```cpp
sort(v.begin(), v.end());
```


###  Ordenar um vetor de struct
```cpp
bool compareByLength(const data &a, const data &b) {
    return a.word.size() < b.word.size();
}

sort(info.begin(), info.end(), compareByLength);

// usando lambda
sort(info.begin(), info.end(), [](const data &a, const data &b) {return a.word.size() < b.word.size();});

sort(info.begin(), info.end(), [](int a, int b) {return a < b.word.size();});
```


###  Ordenar um vetor de strings
```cpp
bool compare(string a, string b){
    return (a.compare(b) < 0);
}

sort (myvector.begin(), myvector.end(), compare);
```


###  push and pop vector
```cpp
vector<int> vec;
vec.push_back(2);
vec.pop_back();
```

###  clear vector
```cpp
vector<int> oi = {1, 2, 3};
oi = {};
```


###  Filtrar um vetor
```cpp
vector<int> filteredVector;

for (int i=0;i<originalVec.size();i++) {
  if (condition) {
    filteredVector = originalVec[i];
  }
}
```


###  string include substring
```cpp
string str ("There are two needles in this haystack.");
string str2 ("needle");

if (str.find(str2) != string::npos) {
//.. found.
} 
```

###  string erase substring
```cpp
s.erase(index, size);
} 
```


###  string find substring
```cpp
s.substr(index, size);
} 
```


###  Split de uma string
```cpp
var names = 'Harry Trump ;Fred Barney; Helen Rigby ; Bill Abel ;Chris Hand ';

var re = /\s*;\s*/;
var nameList = names.split(re);

--

var myString = 'Hello World. How are you doing?';
var splits = myString.split(' ', 3);

console.log(splits);
```


###  Pair
```cpp
pair<int,int> p1 = make_pair(0,1);
pair<int,int> p2 = make_pair(1,0);
```


###  set
```cpp
set<int> conj;
conj.insert(1);
conj.insert(1);
conj.erase(1);

if(conj.count(1)){// retorna 1 se tiver o elemento
	// faça algo
}
int x = conj.size(); // x = 3

for(int elem : conj){
	printf("%d\n",elem);
}
```


###  Map
```cpp
map<string,int> meu_mapa;
// o acesso é como o de um vetor, mas o índice tem o tipo da chave.

mapa["Deivis"] = 2;

cout << mapa["Sei la"] << endl;

--

int size = meu_mapa.size();

for(auto& p : mapa){
	printf("%d %d",p.first,p.second);
}

--

if ( m.find("f") == m.end() ) {
  // not found
}

--

// acessar o primeiro elemento
m.begin()->first // key
m.begin()->second // value
```


###  unsorted
```cpp
unordered_set<int> conj;
unordered_map<int,int> mapa;
```


###  pilha
```cpp
stack<int> pilha;
for(int i=0;i<10;i++){
    pilha.push(i);
}
cout << pilha.top() << endl;
pilha.pop();
cout << pilha.top() << endl;
for(int i=0;i<9;i++){
    pilha.pop();
    if(pilha.empty()){
        cout << "Fiquei vazia na iteração: " << i+1 << endl;
    }
}
```


###  fila
```cpp
queue<int> fila;
for(int i=0;i<10;i++){
  fila.push(i);
}
cout << fila.front() << endl;
cout << fila.pop() << endl;
cout << fila.front() << endl;

for(int i=0;i<9;i++){
  fila.pop();
  if(fila.empty()){
    cout << "Vazio na iteração " << i+1 << endl;
  }
}
```

###  priority queue
```cpp
auto comp = []( adjist a, adjlist b ) { return a.second > b.second; };
priority_queue< adjlist_edge , vector<adjlist_edge>, decltype( comp )> adjlist_pq(comp);
priority_queue<int , vector<int>, greater<int>> pq;

priority_queue<int> fila;
for(int i=0;i<10;i++){
  fila.push(i);
}
cout << fila.top() << endl;
cout << fila.pop() << endl;
cout << fila.top() << endl;

for(int i=0;i<9;i++){
  fila.pop();
  if(fila.empty()){
    cout << "Vazio na iteração " << i+1 << endl;
  }
}
```

###  lista
```cpp
list<int> l;
l.push_back(1);
l.push_front(1)
l.pop_back();
l.pop_front();
l.back();
l.front();
```


###  comversão
```cpp
string para int
int oi = atoi(n.c_str());

--
int to string
to_string(sum)

--
char to int
sum += c - 48;
```


###  precisão float
```cpp
double positive = 0;
printf("%.6f\n", positive / arr.size());
```


###  absolute value
```cpp
cout << abs(-5);
```

###  maximum and minimum values
```cpp
numeric_limits<int>::min()
numeric_limits<int>::max()

INT_MIN
INT_MAX
```

###  memorization
```cpp
memset(memorization, -1, sizeof(memorization));
```
