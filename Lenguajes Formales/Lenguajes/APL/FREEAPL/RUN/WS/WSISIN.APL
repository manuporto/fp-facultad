apl\11
fuzz 1e-13
origin 1
width 72
digits 9
MF WSISIN
WSISIN fn;i;a;n;m
i0 open fn
l1:ai read 6
(0=½a)/lend
n+/^\aΉ'0123456789'
(n=0)/lend
mna
a(na),i read m-6-n
('CNF'=1a)/l2,l3,l4
'WSISIN ERROR'
lend
l2:WSISIC 1a
l1
l3:WSISIN 1a
l1
l4:WSISIF 1a
l1
lend:iclose i
 MF WSISIC
WSISIC a;na;l;r;d
laΌ' '
na(l-1)a
ala
laΌ' '
rla
ala
l(' '=10a)/Ό10
dl[r]a
al[r]a
na,'d½a'
 MF WSISIN
WSISIN a;na;l;r;d;k
laΌ' '
na(l-1)a
ala
laΌ' '
rla
ala
l(' '=10a)/Ό10
dl[r]a
al[r]a
k0½0
l1:l―1(' '=100a)/Ό100
kk,la
ala
(0<½a)/l1
na,'d½k'
 MF WSISIF
WSISIF a;na;l;r;d
laΌ' '
na(l-1)a
ala
laΌ' '
rla
ala
l(' '=10a)/Ό10
dl[r]a
al[r]a
lfx d½a

 CH NAMELIST 2 5 10
WSISIN    WSISIC  WSISIN  WSISIF  NAMELIST
CH note 2 4 43
This workspace reads APL2/PC transfer filesprepared with WSISOUT.ATF and prepares themfor APLWin. Usage:                               WSISIN 'filename'                    
