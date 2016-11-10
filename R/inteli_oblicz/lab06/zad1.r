P.buys.yes = 4/7
P.buys.no = 3/7

P.u40.yes = 2/4
P.u40.no = 1/3
P.ilow.yes = 1/4
P.ilow.no = 2/3
P.sno.yes = 3/4
P.sno.no = 1/3
P.crfair.yes = 2/4
P.crfair.no = 2/3

P.Y.yes= P.u40.yes * P.ilow.yes * P.sno.yes * P.crfair.yes
P.Y.no = P.u40.no * P.ilow.no * P.sno.no * P.crfair.no

P.yes.Y = P.Y.yes * P.buys.yes
P.no.Y = P.Y.no * P.buys.no

P.yes.Y
P.no.Y

#Kupi bo: P.yes.Y > P.no.Y
