from sys import stdin

# ada(m), asia, kamil(a), kasia

stan_0 = 0
stan_a = 1
stan_ad = 2
stan_ada = 3 # akceptujacy
stan_adam = 4 # koncowy
stan_as = 5
stan_asi = 6
stan_asia = 7 # koncowy
stan_k = 8
stan_ka = 9
stan_kas = 10
stan_kasi = 11
stan_kasia = 12 # koncowy
stan_kam = 13
stan_kami = 14
stan_kamil = 15 # akceptujacy
stan_kamila = 16 # koncowy
stan_blad = 17

znak_blad = 0
znak_a = 1
znak_d = 2
znak_m = 3
znak_s = 4
znak_i = 5
znak_k = 6
znak_l = 7

funkcja = [
	[stan_blad,	stan_a, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_k,		stan_blad],	#Stan 0
	[stan_blad,	stan_blad, 	stan_ad,	stan_blad,	stan_as,	stan_blad,	stan_blad,	stan_blad],	#Stan a
	[stan_blad,	stan_ada, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad],	#Stan ad
	[stan_blad,	stan_a, 	stan_blad,	stan_adam,	stan_blad,	stan_blad,	stan_k,		stan_blad],	#Stan ada
	[stan_blad,	stan_a, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_k,		stan_blad],	#Stan adam
	[stan_blad,	stan_blad, 	stan_blad,	stan_blad,	stan_blad,	stan_asi,	stan_blad,	stan_blad],	#Stan as
	[stan_blad,	stan_asia, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad],	#Stan asi
	[stan_blad,	stan_a, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_k,		stan_blad],	#Stan asia
	[stan_blad,	stan_ka, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad],	#Stan k
	[stan_blad,	stan_blad, 	stan_blad,	stan_kam,	stan_kas,	stan_blad,	stan_blad,	stan_blad],	#Stan ka
	[stan_blad,	stan_blad, 	stan_blad,	stan_blad,	stan_blad,	stan_kasi,	stan_blad,	stan_blad],	#Stan kas
	[stan_blad,	stan_kasia, stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad],	#Stan kasi
	[stan_blad,	stan_a, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_k,		stan_blad],	#Stan kasia
	[stan_blad,	stan_blad, 	stan_blad,	stan_blad,	stan_blad,	stan_kami,	stan_blad,	stan_blad],	#Stan kam
	[stan_blad,	stan_blad, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_kamil],#Stan kami
	[stan_blad,	stan_kamila, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_k,		stan_blad],	#Stan kamil
	[stan_blad,	stan_a, 	stan_blad,	stan_blad,	stan_blad,	stan_blad,	stan_k,		stan_blad],	#Stan kamila
]

def klasa(p):
	znak = znak_blad
	if(p == 'a'):
		znak = znak_a
	if(p == 'd'):
		znak = znak_d
	if(p == 'm'):
		znak = znak_m
	if(p == 's'):
		znak = znak_s
	if(p == 'i'):
		znak = znak_i
	if(p == 'k'):
		znak = znak_k
	if(p == 'l'):
		znak = znak_l
	return znak

def pokaz_blad(stan, p):
	if(stan == stan_0):
		print('Niedozwolony znak, mialo byc a lub k, a jest', p)
	if(stan == stan_a):
		print('Niedozwolony znak, mialo byc d lub s, a jest', p)
	if(stan == stan_ad):
		print('Niedozwolony znak, mialo byc a, a jest', p)
	if(stan == stan_ada):
		print('Niedozwolony znak, mialo byc a lub k lub m, a jest', p)
	if(stan == stan_adam):
		print('Niedozwolony znak, mialo byc a lub k, a jest', p)
	if(stan == stan_as):
		print('Niedozwolony znak, mialo byc i, a jest', p)
	if(stan == stan_asi):
		print('Niedozwolony znak, mialo byc a, a jest', p)
	if(stan == stan_asia):
		print('Niedozwolony znak, mialo byc a lub k, a jest', p)
	if(stan == stan_k):
		print('Niedozwolony znak, mialo byc a, a jest', p)
	if(stan == stan_ka):
		print('Niedozwolony znak, mialo byc s lub m, a jest', p)
	if(stan == stan_kas):
		print('Niedozwolony znak, mialo byc i, a jest', p)
	if(stan == stan_kasi):
		print('Niedozwolony znak, mialo byc a, a jest', p)
	if(stan == stan_kasia):
		print('Niedozwolony znak, mialo byc a lub k, a jest', p)
	if(stan == stan_kam):
		print('Niedozwolony znak, mialo byc i, a jest', p)
	if(stan == stan_kami):
		print('Niedozwolony znak, mialo byc l, a jest', p)
	if(stan == stan_kamil):
		print('Niedozwolony znak, mialo byc a lub k, a jest', p)
	if(stan == stan_kamila):
		print('Niedozwolony znak, mialo byc a lub k, a jest', p)
	if(stan == stan_blad):
		print('Niedozwolony znak')

def pokaz_leksem(stan, p, leksem, nowy_stan): #YODO
	if(stan == stan_ada and czy_poczatkowy(nowy_stan)):
		print('Leksem:', leksem)
		return True
	if(stan == stan_kamil and czy_poczatkowy(nowy_stan)):
		print('Leksem:', leksem)
		return True
	if(stan == stan_adam):
		print('Leksem:', leksem)
		return True
	if(stan == stan_asia):
		print('Leksem:', leksem)
		return True
	if(stan == stan_kasia):
		print('Leksem:', leksem)
		return True
	return False

def czy_poczatkowy(stan):
	return (stan == stan_0 or stan == stan_a or stan == stan_k)

def czy_koncowy(stan):
	return (stan == stan_adam or stan == stan_asia or stan == stan_kamila or stan == stan_kasia)

def czy_akceptujacy(stan):
	return (czy_koncowy(stan) or stan == stan_ada or stan == stan_kamil)

def analiza(p):
	stan = stan_0
	leksem = ''
	for c in p:
		if(c == ' '):
			continue
		if(c == '\n'):
			czy_koniec = czy_akceptujacy(stan)
			if(czy_koniec):
				if(not czy_drukowano):
					print('Leksem:', leksem)
			else:
				pokaz_blad(stan, '[koniec]')
			break
		znak = klasa(c)
		nowy_stan = funkcja[stan][znak]
#BeginFix 'Rozwiazanie niedeterministycznego automatu'
		if(stan == stan_kamila):
			if(nowy_stan == stan_blad and funkcja[stan_a][znak] != stan_blad):
				print('Leksem: kamil') # Drukowane w przypadku, gdy po 'kamil' jest imie na a
				leksem = 'a'
				nowy_stan = funkcja[stan_a][znak]
			else:
				print('Leksem: kamila') # Drukowane w przypadku pewnosci, ze chodzi o 'kamila'
				leksem = ''
#EndFix
		if(nowy_stan == stan_blad):
			pokaz_blad(stan, c)
			break
		czy_drukowano = pokaz_leksem(stan, c, leksem, nowy_stan)
		if(czy_drukowano):
			leksem = ''
		leksem += c
		stan = nowy_stan

for p in stdin:
	analiza(p)
