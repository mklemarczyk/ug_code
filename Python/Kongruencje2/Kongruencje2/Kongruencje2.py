import math

# Funkcja mno??ca wiersz multiplyRow przez liczb? scale i dodaj?cy do sourceRow
def rowMultiplyAndSum(matrix, sourceRow, multiplyRow, scale):
    return rowSum(matrix[sourceRow], rowMultiply(matrix[multiplyRow], scale))
    pass

# Funkcja mno??ca wiersz przez liczb?
def rowMultiply(row, scale):
    r = []
    for ri in row: r.append(ri * scale)
    return r
    pass

# Funkcja sumujaca dwa wiersze
def rowSum(rowA, rowB):
    r = []
    for i in range(len(rowA)): r.append(rowA[i] + rowB[i])
    return r
    pass

def kongruencje2(a, b, n):
    if(a < b): (a, b) = (b, a)

    # Tworzymy macierz wg. schematu
    mat = [[a,1,0],
           [b,0,1]]
    r =    [1,1,1]

    # Obliczemy macierzowo NWD(a,b)
    while(r[0] != 0):
        i = len(mat)
        s = int(mat[i-2][0] / mat[i-1][0])
        r = rowMultiplyAndSum(mat, i-2, i-1, -s)
        if(r[0] != 0):
            mat.append(r)

    # Odczytujemy z macierzy wyniki NWD(a, b), wspó?czynniki (x, y)
    n0 = mat[len(mat)-1][0]
    x =  mat[len(mat)-1][1]
    y =  mat[len(mat)-1][2]

    # Sprawdzamy czy wszystkie operacje nie spowodowa?y b??du
    status = ""
    if(a * x + b * y != n0):
        status = " - error (" + str(a * x + b * y) + ")"

    print("{0} = {1}x + {2}y; x = {3}; y = {4}".format(n0, a, b, x, y) + status)

    # Sprawdzamy czy n jest liczb? naturaln? wi?ksz? od 1
    if(n == int(n) and n > 1):
        # Sprawdzamy czy jest mo?liwe otrzymanie rozwiazania uk?adu w liczbach ca?kowitych
        if(n % n0 != 0):
            print("Liczby nie sa wzglednie prierwsze oraz liczba n nie jest wielokrotno?ci? NWD(a,b)!")
        else:
            # Mno?ymy otrzymane wspó?czynniki przez n i dzielimy przez NWD(a,b)
            x = x * n / n0
            y = y * n / n0

            # Proces optymalizacji wyniku ( ciekawe czy mo?na to zapisac inaczej)
            while(x < 0):
                x = x + b
                y = y - a
            while(b < x):
                x = x - b
                y = y + a
            # Koniec procesu optymalizacji wyniku

            if(a * x + b * y != n):
                status = " - error (" + str(a * x + b * y) + ")"
            print("{0} = {1}x + {2}y; x = {3}; y = {4}".format(n, a, b, x, y) + status)
    pass

# Przyk?ady
# n = a * x + b * y

a = 12
b = 29
n = 6

kongruencje2(a,b,n)
print()

a = 24
b = 17
n = 3

kongruencje2(a,b,n)
print()

a = 20
b = 61
n = 8

kongruencje2(a,b,n)
print()

a = 25
b = 81
n = 6

kongruencje2(a,b,n)
print()

a = 50
b = 58
n = 8

kongruencje2(a,b,n)
