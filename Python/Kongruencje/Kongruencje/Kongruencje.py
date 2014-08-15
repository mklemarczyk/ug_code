def odwrotnosc_mod(a, b):
    for i in range(b):
        x = (i * a) % b
        if(x == 1):
            return i
    pass

# x mod k1 = r1
# x mod k2 = r2
# x mod k3 = r3
# ...

k = [3, 5, 7] # klasy abstrakcji (musza byc cialem, czyli liczbami pierwszymi)
r = [2, 3, 5] # reprezentanci klas abstrakcji

#Obliczenie ilosci kombinacji
ilosc_kombinacji = 1
for ki in k:
    ilosc_kombinacji = ilosc_kombinacji * ki

#Obliczanie wspólczynników m
m = []
for ki in k:
    m.append(ilosc_kombinacji / ki)

#Odwrotnosc liczby m w modulo k (n = 1/m)
n = []
for i in range(len(r)):
    n.append(odwrotnosc_mod(m[i], k[i]))

#Zsumowanie iloczynów r * m * n
x = 0
for i in range(len(k)):
    x = x + (r[i] * m[i] * n[i])

#Obliczenie x mod ilosc_kombinacji
x = x % ilosc_kombinacji

print('Rozwiazaniem jest: ' + str(x))
