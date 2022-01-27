https://www.baeldung.com/java-collections-complexity

###  Ordenar um vetor
```java
ArrayList<Transaction> transactions;
Collections.sort(transactions);
```

###  Ordenar um vetor de forma personalizada
```java
ArrayList<Transaction> transactions;
transactions.sort(this::compare);

private Integer compare(Transaction a, Transaction b) {
    if (isEquals(a, b)) {
        return a.getDate().compareTo(b.getDate());
    }

    return a.getKey().compareTo(b.getKey());
}
```

###  Ordenar um vetor dusando lambda
```java
ArrayList<String> oi = new ArrayList<>(Arrays.asList("oi", "aaa", "bbb"));
oi.sort((c1, c2) -> {
    if ("oi".equals(c1)) {
        return c1.compareTo(c2);
    }
    return c2.compareTo(c1);
});

oi.sort((c1, c2) -> c2.compareTo(c1));
```

###  vector com default value
```java
ArrayList<String> vec = new ArrayList<>(Arrays.asList("oi", "aaa", "bbb"));
```

###  push and pop vector
```java
ArrayList<Integer> vec = new ArrayList<>();
vec.add(1);
// remove indice específico
vec.remove(2);
// remove valor
oi.remove(Integer.valueOf(2));

// add with fixed size
List<Integer> a2 = new ArrayList<>(Collections.nCopies(10, -1));

// shuffle list
Collections.shuffle(list);
```

###  clear vector
```java
array.clear();
```

###  Filtrar um vetor
```java
ArrayList<Integer> oi = new ArrayList<>(Arrays.asList(1,2,3));
ArrayList<Integer> oii = oi.stream().filter((a) -> a >= 2).collect(Collectors.      toCollection(ArrayList::new));
// .collect(Collectors.toList());
```

###  string include substring
```java
String s1 = "oiie";
String s2 = "ii";
System.out.println(s1.contains(s2));
} 
```

###  string find substring
```java
String s1 = "oiie";
String s2 = s1.substring(1, 3);
// "ii"
} 
```

###  string find substring
```java
String s1 = "oiie";
String s2 = s1.substring(1, 3);
// "ii"
} 
```

###  Split de uma string
```java
String s1 = "oi tudo bem?";
List<String> s2 = Arrays.stream(s1.split(" ")).collect(Collectors.toList());

---

String s1 = "oi tudo bem?";
String[] s2 = s1.split(" ");
```

###  acessando tamanhos
```java
string -> lenght
array normal -> lenght()
listas -> size()
```

###  set
```java
Set<Integer> s = new TreeSet<>((a,b) -> b.compareTo(a));
s.add(2);
s.add(3);
s.add(4);
s.remove(3);

System.out.println(s.contains(2));

s.forEach(System.out::println);

new HashSet<>();
new LinkedHashSet<>();
```

###  map
```java
Map<String, Integer> s = new TreeMap<>((s1, s2) -> s1.compareTo(s2));
s.put("k1", 2);
s.put("k2", 3);
s.put("k3", 4);
s.remove("k2");

System.out.println(s.containsKey("k2"));
System.out.println(s.containsKey("k3"));

s.forEach((k, v) -> {
    System.out.println(k + " " + v);
});

Object[] keys = s.keySet().toArray();
System.out.println(s.get((String) keys[0]));

new HashMap<>();
new LinkedHashMap<>();
```

###  pilha
```java
Stack<Integer> s = new Stack<>();
s.push(3);
System.out.println(s.empty());
System.out.println(s.size());
System.out.println(s.peek());
System.out.println(s.pop());
System.out.println(s.size());
```

###  queue
```java
Queue<Integer> q = new LinkedList<>();
q.add(3);
System.out.println(q.peek());
System.out.println(q.size());
System.out.println(q.poll());
System.out.println(q.size());

Queue<Integer> q = new PriorityQueue<>();
q.add(3);
q.add(3);
q.add(2);
q.add(4);
System.out.println(q);
```

###  linkedList
```java
LinkedList<Integer> q = new LinkedList<>();
q.add(1);
q.add(2);
q.add(3);
q.add(4);
q.addFirst(4);
q.addLast(4);
System.out.println(q.getFirst());
System.out.println(q.getLast());
System.out.println(q.size());
System.out.println(q.removeFirst());
System.out.println(q.removeLast());
System.out.println(q);
```

###  comversão
```java
// string para int
int i = Integer.parseInt("1234");
Integer i = Integer.valueOf("123");

--
// int to string
String s = String.valueOf(123);
String s = Integer.valueOf(123).toString();

--
// char to int
String s = "4est";
int i = Integer.parseInt(String.valueOf(s.charAt(0)));
Integer i = s.charAt(0) - '0';
```

###  precisão float
```java
Double f = 3.4567;
String f2 = new DecimalFormat("0.00").format(f);
System.out.println(f2);
```

###  absolute value
```java
Math.abs(-1);
```

###  maximum and minimum values
```java
Integer.MAX_VALUE
Integer.MIN_VALUE
```

###  max and min
```java
Integer.max(3,4)
Integer.min(3,4)
```

## Object oriented Programing

### enum
```java
public enum AccountStatus{
  ACTIVE,
  CLOSED,
  CANCELED,
  BLACKLISTED,
  NONE
}
```

### enum with value
```java
public enum Face {
    ACE(1), DEUCE(2), THREE(3), FOUR(4), FIVE(5), SIX(6), SEVEN(7), EIGHT(8), NINE(9), TEN(10), JACK(10), QUEEN(
            10), KING(10);
    private final int value;

    private Face(int value) {
        this.value = value;
    }
    
    public int getValue() {
        return value;
    }
}
```

### abstract clas extend
```java
public abstract class Vehicle {
  private String licenseNumber;
  private final VehicleType type;
  private ParkingTicket ticket;

  public Vehicle(VehicleType type) {
    this.type = type;
  }

  public void assignTicket(ParkingTicket ticket) {
    this.ticket = ticket;
  }
}

public class Car extends Vehicle {
  public Car() {
    super(VehicleType.CAR);
  }
}

public class Van extends Vehicle {
  public Van() {
    super(VehicleType.VAN);
  }
}

public class Truck extends Vehicle {
  public Truck() {
    super(VehicleType.TRUCK);
  }
}
```