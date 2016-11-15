from sys import stdin

stan_0 = 0
stan_a = 1
stan_ab = 2
stan_aba = 3
stan_cyfra = 4
stan_blad = 5

znak_blad = 0
znak_a = 1
znak_b = 2
znak_cyfra = 3

funkcja = [
	[stan_blad,	stan_a, 	stan_blad,	stan_cyfra],	#Stan 0
	[stan_blad,	stan_blad,	stan_ab,	stan_blad],		#Stan a
	[stan_blad,	stan_aba,	stan_blad,	stan_blad],		#Stan ab
	[stan_blad,	stan_a,		stan_blad,	stan_cyfra],	#Stan aba
	[stan_blad,	stan_a,		stan_blad,	stan_cyfra],	#Stan cyfra
	[stan_blad,	stan_blad,	stan_blad,	stan_blad],		#Stan blad
]

def klasa(p):
	znak = znak_blad
	if(p == 'a'):
		znak = znak_a
	if(p == 'b'):
		znak = znak_b
	if(p >= '0' and p <= '9'):
		znak = znak_cyfra
	return znak

def pokaz_blad(stan, p):
	if(stan == stan_0):
		print('Niedozwolony znak, mialo byc a lub cyfra, a jest', p)
	if(stan == stan_a):
		print('Niedozwolony znak, mialo byc b, a jest', p)
	if(stan == stan_ab):
		print('Niedozwolony znak, mialo byc a, a jest', p)
	if(stan == stan_aba):
		print('Niedozwolony znak, mialo byc a lub cyfra, a jest', p)
	if(stan == stan_blad):
		print('Niedozwolony znak')
	if(stan == stan_cyfra):
		print('Niedozwolony znak, mialo byc a lub cyfra, a jest', p)

def pokaz_leksem(stan, p, leksem, nowy_stan):
	if(nowy_stan == stan_a and stan == stan_cyfra):
		print('Leksem:', leksem)
		return True
	if(nowy_stan == stan_aba):
		print('Leksem: aba')
		return True
	return False

def sprawdz_koniec(stan):
	return (stan == stan_0 or stan == stan_aba or stan == stan_cyfra)

def analiza(p):
	stan = stan_0
	leksem = ''
	for c in p:
		if(c == ' '):
			continue
		znak = klasa(c)
		nowy_stan = funkcja[stan][znak]
		if(c == '\n'):
			czy_koniec = sprawdz_koniec(stan)
			if(czy_koniec):
				if(not czy_drukowano):
					print('Leksem:', leksem)
			else:
				pokaz_blad(stan, '[koniec]')
			break
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
