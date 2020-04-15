---
layout: post
title:  "Forritunarreglur"
date:   2020-01-27 14:24:34 +0000
author: "Reyn Alpha"
---

## Almennt

Kóðinn í þessu verkefni er skrifaður í C++ og notast við VEXcode V5 Text þróunarumhverfið.

## Breytur

Breytur skulu nefndar lýsandi nöfnum á ensku og skal notast við `camelCase` þar sem öll orð nema það fyrsta er látið byrja á hástaf. Nöfn á föstum (`const` eða `#define`) skulu vera alfarið í hástöfum og með undirstriki (`_`) milli orða. `Iterator`-breytur í lykkjum skulu kallaðar `i`. Sé um hreiðraðar lykkjur að ræða skal nota `j` í innri lykkjuna, þá `k` og svo koll af kolli í stafrófsröð.

## Skynjarar

Nöfn á skynjurum og tækjum sem tengd eru við VEX-heilann skulu rituð í `PascalCase` þar sem öll orð byrja á hástaf.

## Föll

Föll lúta sömu nafnareglum og breytur. Hvert fall skal aðeins gera einn hlut og gera hann vel. Tilgangur falla á að koma fram í nafninu og þau eiga ekki að hafa neinar óvæntar hliðarverkanir.

## Klasar

Klasar skulu nefndir lýsandi nöfnum á ensku og notast við `PascalCase` þar sem öll orð byrja á hástaf. Klasar skulu hafa smiði (constructors) sem taka við þeim gögnum sem ætlast er til að klasarnir innihaldi, auk `default constructor` sem núllstillir öll eigindi séu engin gögn sett inn. Notast skal við falin (`private`) eigindi og fela innri virkni frá utanaðkomandi kóða. Heiti á `private` eigindum skulu byrja á undirstriki (`_`). Notast skal við `getter`/`setter` aðferðir til að lesa og skrifa í klasabreytur. Dæmi:

```cpp
class MyClass {
private:
    int _a;
    int _b;
public:
    MyClass() : _a(0), _b(0) {}
    MyClass(int a, int b) : _a(a), _b(b) {}
    int getA() {
        return this->_a;
    }
    int getB() {
        return this->_b;
    }
    void setA(int a) {
        this->_a = a;
    }
    void setB(int b) {
        this->_b = b;
    }
};
```

### Erfðir

Erfi klasi frá öðrum klasa skal meginreglan gilda að nota `public` erfðir. Dæmi:

```cpp
class MyClass {
private:
    int _a;
    int _b;
public:
    MyClass() : _a(0), _b(0) {}
};

class MySubclass: public MyClass {
private:
    int _c;
public:
    MySubclass() : MyClass(), _c(0) {}
};
```

## Kóðauppsetning

### Slaufusvigar

Opnun slaufusviga sem afmarka kóðablokkir skal rita í sömu línu og `if`-setningar, lykkjusetningar, skilgreiningar falla, klasa, struct o.s.frv. Slaufusviganum skal loka á nýrri línu. Dæmi:

```cpp
struct MyStruct {
    int a;
    int b;
};

int main(int argc, const char * argv[]) {
    int a = 5;

    if (a == 5) {
        std::cout << "a is equal to 5\n";
    } else if (a == 3) {
        std::cout << "a is equal to 3\n";
    } else {
        std::cout << "a is not equal to 5 or 3\n";
    }

    for (int i = 0; i < a; i++) {
        std::cout << i << '\n';
    }

    return 0;
}
```

### Inndráttur og bil

Draga skal inn kóða sem tilheyrir kóðablokkum sem afmarkaðar eru af slaufusvigum. Einnig skal draga inn innihald `switch/case` setninga og skilgreiningar á klasabreytum en lykilorð svo sem `private` og `public` skal ekki draga inn. Einn inndráttur samanstendur af fjórum bilum. Ekki skal nota <kbd>Tab</kbd>-stafi fyrir inndrátt.

```cpp
int a = 5;
switch (a) {
    case 1:
        doSomething();
        break;
    case 2:
        doSomethingElse();
        break;
    default:
        abortMission();
}
```

Bil skal rita á undan svigum með skilyrðum í `if`-setningum, `switch`-setningum og lykkjum. Ekki skal rita bil á undan færibreytulistum falla. Dæmi:

```cpp
bool isEqualTo5(int n) {
    return n == 5;
}

int main(int argc, const char * argv[]) {
    int a = 5;

    while (a != 5) {
        a++;
    }
    if (isEqualTo5(a)) {
        std::cout << "a is equal to 5\n";
    } else {
        std::cout << "a is not equal to 5\n";
    }

    return 0;
}
```

### Skrár

Brjóta skal upp kóða. Stærri og flóknari klasa og fasta sem eiga alltaf við skal geyma í header-skrám (`.h`) og útfærslur í `.cpp` kóðaskrám. Alltaf skal skrifa `#include` setningar fyrir þær header skrár sem þarf hverju sinni í öðrum header skrám.
