apl\11
fuzz 1e-13
origin 1
width 72
digits 9
MF ABCHECK
R�ABCHECK T;M;N
M�(�T)[1]-1
N�(�T)[2]-1
R�(+/T[�M;N+1])�+/T[M+1;�N]
 MF AM
Z9�AM Y9
Z9�(+/Y9)��Y9
 DF ANOVA
R�C ANOVA A;E;I;T
R�0 2�0
LOOP:I�C�','
R�R,[1]((I-1)�C)DFSSC A
�(0<�C�I�C)/LOOP
T�1 DFSS,A
E�T-+�R
R�(R,�/�R),[1](E,�/�E+E[1]=0),[0.5]T,0

 DF CHISQ
Z9�X9 CHISQ Y9
Z9�+/,((X9-Y9)*2)�X9
 MF AOVALL
R�AOVALL A;I;L;S;T
T��0 1�TT��A
T�T[;�+�T]
L�0 10�' '
R�0 2�0
LOOP:I�T[;1]/���A
L�L,[1]10�'ABCDEFGH'[I]
R�R,[1]I DFSS A
�(0<�1��T�0 1�T)/LOOP
S�+�R
R�R,�/�R
R�L,5 0 13 5 13 5�R
R�R,[1](10�'TOTAL'),31�5 0 13 5�S
 DF AOVTABLE
R�L AOVTABLE T;I
R��0
LOOP:I�L�','
R�R ON(I-1)�L
�(0<�L�I�L)/LOOP
R�R ON 'ERROR' ON 'TOTAL'
R�(T[;1]�0)�R,5 0 13 5 13 5�T
R[(�R)[1];(�R)[2]-0,�12]�' '

 DF AOVPOOLED
R�M AOVPOOLED A;T
T�AOVMODEL M
R�(DRB T[1;]AOVTABLE(DRB T[2;])ANOVA A

 DF AOVCROSSED
R�M AOVCROSSED A
R�M AOVTABLE M ANOVA A

 MF AP
Z9�AP Y9
Z9�Y9[1]+Y9[2]�0,�Y9[3]-1
 MF AVG
Z9�AVG Y9
Z9�(+�COL Y9)�1��Y9
 MF AXIS
Z9�AXIS Y9
Z9�' ' BY((1+5חY9�5)�'װ���')BY ' '
 DF BARCHART
Z9�X9 BARCHART Y9
Z9�(5 0�((�Y9),1)�Y9)BY(AXIS�Y9)BY X9 BARS Y9
 DF BARS
Z9�X9 BARS Y9
Z9��((0=X9=0)/'''.�''[1+ Y9 �.�(�/ Y9 )�(� X9 )� X9 ]'),(0�X9=0)/'(�/ Y9 ) BARS  Y9 '
 DF BASICLOOP
R�X BASICLOOP V;J;K;P;Q
R�1+X�,�1+1�V
P�1+X��1+1�V
Q�2 0�0
K�1
LOOP:J�P[K;]�R[K;(�R)[2]]
�((�R)[2]<J)/BACK
R�R,P[;J]
P�(J��(�P)[2])/P
K�(2 1)[K]
�((K=2)^=/R[2;1,(�R)[2]])/END
�LOOP
BACK:Q�Q,R[;(�R)[2]]
R�0 �1�R
K�(2 1)[K]
�LOOP
END:R�1+X�R-1
 MF AOVMODEL
R�AOVMODEL M;F;I;J;L
L��0
F��0
LOOP:I�M�':'
L�L,',',(I-1)�M
M�I�M
J�M�','
F�F,',',(J-1)�M
�(0<�M�J�M)/LOOP
R�0 1�L ON F

 DF BC
Z9�X9 BC Y9
Z9�Y9!X9
 DF BD
Z9�X9 BD Y9
Z9�(X9[1]BC Y9)�(X9[2]*Y9)�(1-X9[2])*X9[1]-Y9
 DF BY
R�A BY B
A�((��/�A)�2�(�A),1 1)�A
B�((��/�B)�2�(�B),1 1)�B
�((1�0�,A)=1�0�,B)/l1
A��A
B��B
l1:R�(((1 0׽B)��A)�A),((1 0׽A)��B)�B
 MF CM
Z9�CM Y9
Z9�RCDIAG VC Y9
 MF CMLIST
R�CMLIST X;I;J;N;V
N�(�X)[1]
V�,(�N)�.<�N
I�V/,�(N,N)��N
J�I+1
R�'    I    J    R(I,J)'
R�R ON 5 0 5 0 10 5�I BY J BY V/,X
 MF COL
Z9�COL Y9
Z9�((��/�Y9)�2�(�Y9),1 1)�Y9
 DF CORR
Z9�X9 CORR Y9
Z9�-�/(,1 0�2 2��Y9[X9;X9])*1 0.5 0 0.5
 MF CVARIATION
R�CVARIATION T;BASIS;BETA;BL;BR;C;IL;IR;J;M;N;X;XB;ZERO;ZMC
ZERO�1E�6
M�(�T)[1]-1
N�(�T)[2]-M+3
BASIS�T[1+�M;N+M+2]
XB�T[1+�M;N+M+3]
BETA�T[1+�M;N+1+�M]
C�T[1;�N]
ZMC�(C[BASIS]+.�BETA+.�T[1+�M;�N])-C
R�(3 1�' ')ON '               VARIATIONS IN COSTS' ON ' '
R�R ON '   VAR.    L.B.         COST       U.B.'
J�1
LOOP:�(C[J]=0)/END
�(J�BASIS)/L1
R�R ON(5 0�J),(13�' '),13 5�C[J],C[J]+ZMC[J]
�END
L1:X�BETA[BASIS�J;]+.�T[1+�M;�N]
IL�((~(�N)�BASIS)^X>ZERO)/�N
IR�((~(�N)�BASIS)^X<-ZERO)/�N
BL�C[J]+�/-ZMC[IL]�X[IL]
BL�13�13 5�(BL>�0.00001)/BL
BR�C[J]+�/-ZMC[IR]�X[IR]
BR�13�13 5�(BR<1000000)/BR
R�R ON(5 0�J),BL,(13 5�C[J]),BR
END:(N�J�J+1)/LOOP
 MF CT
Z9�CT Y9
Z9�(CTE Y9)CHISQ Y9
 MF CTE
Z9�CTE Y9
Z9�((+/Y9)�.�+�Y9)�+/,Y9
 DF DFSS
Z9�X9 DFSS Y9
Z9��((0=' '=0\0/X9)/'(�/(� Y9 )[ X9 ]-1), X9  SS  Y9 '),(0�' '=0\0/X9)/'(('' ABCDEFGH ''� X9 )/�8) DFSS  Y9 '
 DF DELTA
Z9�X9 DELTA Y9
Z9��((0=0=�X9)/' (1� X9 ) DELTA (�(1� X9 )���� Y9 ) DELTA1  Y9 '),(0�0=�X9)/' Y9 '
 DF DELTA1
Z9�X9 DELTA1 Y9
Z9�(Y9�(�Y9)[X9[1]])-X9�(�Y9)[X9]�+�(�X9)�Y9
 MF DEVIATES
Z9�DEVIATES Y9
Z9�Y9-(�Y9)�AVG Y9
 DF DFSSC
Z9�X9 DFSSC Y9
Z9��((0=0=�X9)/'((((, X9 )�''+'')� X9 ) DFSSC  Y9 )+((�1+(, X9 )�''+'')� X9 ) DFSS  Y9 '),(0�0=�X9)/'0 '
 DF DIFF
Z9�X9 DIFF Y9
Z9��((0=X9=0)/'( X9 -1) DIFF (1� Y9 )-�1� Y9 '),(0�X9=0)/' Y9 '
 DF DIGRAM
Z9�X9 DIGRAM Y9
Z9�X9 BARCHART FV Y9
 MF DIS
Z9�DIS Y9
Z9�(NUB Y9)�.=Y9
 MF DRB
Z9�DRB Y9
Z9��DLB�Y9
 MF DLB
Z9�DLB Y9
Z9�(�1+(Y9=' ')�0)�Y9
 MF FV
Z9�FV Y9
Z9�((0,��/Y9)�ONUB Y9)\OFR Y9
 DF DUAL
R�S DUAL T;bc;C;I;M;N;X
M�(�T)[1]-1
N�(�T)[2]-1
C�,T[�M;�N]
bc�1+(M,N)�S[2;]-1
R�0,�0.5+C[S[2;]]�0 1�(bc[1;]�.=�M),bc[2;]�.=�N
X�(,R[�M]�.+R[M+�N])-C
�(0=�I�((X=�/X)^X>0)/��X)/0
R�1�I
 DF HISTOGRAM
Z9�Y9 HISTOGRAM X9
Z9�(10 2�COL AP(1 0.5+.�2�X9),1�X9)BY(�1�4�X9)BARCHART X9 SFV Y9
 MF GF
Z9�GF Y9
Z9�Y9[;2]CHISQ Y9[;1]
 MF GM
Z9�GM Y9
Z9�(�/Y9)*��Y9
 MF LPS
R�LPS A;T
T�RSIMPLEX A
R�OPTSOLN((�A)[1],�2)�T
�(T[1;(�T)[2]-1]�O)/0
R�R ON CVARIATION T
R�R ON BVARIATION T

 MF HM
Z9�HM Y9
Z9��AM�Y9
 DF LI
Z9�X9 LI Y9
Z9�Y9[�X9]+(Y9[�X9]-Y9[�X9])�1|X9
 MF LP
R�LP A
R�OPTSOLN((�A)[1],�2)�RSIMPLEX A

 MF MEANSQ
Z9�MEANSQ Y9
Z9�(+/,Y9*2)��/�Y9
 MF MEDIAN
Z9�MEDIAN Y9
Z9�0.5�+/Y9[(�Y9)[�0 0.5+(�Y9)�2]]
 MF MODE
Z9�MODE Y9
Z9�(�ODIS OFR Y9)[1;]/ONUB Y9
 DF NEWSOLN
R�S NEWSOLN T;I;K;P;THETA
I�S[2;]�(�1+�T)BASICLOOP S[2;]
K�((�I)�0 1)/I
THETA��/S[1;K]
P�K[S[1;K]�THETA]
S[1;I]�S[1;I]+THETA�(�I)�1 �1
R�(P��(�S)[2])/S
 MF NDP
Z9�NDP Y9
Z9�+/�/0�(8�10)��0.5+100000000�1|,Y9
 MF NWCR
R�NWCR T;AC;bc;M;N;X
M�(�T)L1]-1
N�(�T)[2]-1
AC�+\0.001+T[�M;N+1]
bc�+\T[M+1;�N-1],T[M+1;N]+0.001�M
X��1�(AC,bc)[�AC,bc]
R��0.5+1 DIFF 0,X
R�R,[0.5](�M+N-1)++\(�1�0,X�AC)\N-1
 MF ODIS
Z9�ODIS Y9
Z9�(ONUB Y9)�.=Y9
 MF NUB
Z9�NUB Y9
Z9�((Y9�Y9)=��Y9)/Y9
 DF ON
R�A ON B
A�((��/�A)ׯ2�1 1,(�A))�A
B�((��/�B)ׯ2�1 1,(�B))�B
�((1�0�,A)=1�0�,B)/l1
A��A
B��B
l1:R�(((0 1׽B)��A)�A),[�io]((0 1׽A)��B)�B
 DF NFV
Z9�X9 NFV Y9
Z9�(�Y9)�1 DIFF 0,(SND((AP X9+0 0 1)-AM Y9)�SD Y9),1
 MF OFR
Z9�OFR Y9
Z9�+/ODIS Y9
 MF OPTSOLN
R�OPTSOLN S
�(2 4 3)[S[1;1]+2]
�0,�R�'NO FEASIBLE SOLUTION'
�0,�R�'UNBOUNDED SOLUTION'
R�'          MAXIMUM VALUE',12 5�S[1;2]
R�R ON ' ' ON '   VAR.     LEVEL'
R�R ON 5 0 13 5�1 0�S

 DF OPTSOLNTR
R�S OPTSOLNTR T;C;C12;C3;C4;C5;D;N;M
�(3=1��S)/SOLN
R�'AVAILABILITIES AND REQUIREMENTS HAVE DIFFERENT TOTALS'
�0
SOLN:M�(�T)[1]-1
N�(�T)[2]-1
C�,T[�M;�N]
D�0,S[3;]
R�'      ORG.    DEST.    AMT.  U. COST.  COST' ON ' '
S�S[;�S[2;]]
C12��1+(M,N)�S[2;]-1
C3�S[1;]
C4�C[S[2;]]
C5�C3�C4
R�R ON 8 0�C12,C3,C4,[1.5]C5
R�R ON(36�' '),'----'
R�R ON(20�' '),'MINIMUM COST',8 0�+/C5
R�R ON 2 1�' '
R�R ON 'OPTIMAL DUAL SOLUTION:'
R�R ON '  ORIGINS        ',3 0�D[�M]-�/D[�M]
R�R ON '  DESTINATIONS   ',3 0�D[M+�N]+�/D[�M]
 MF ONUB
Z9�ONUB Y9
Z9�SORT NUB Y9
 DF PD
Z9�X9 PD Y9
Z9�((*-X9)�X9*Y9)�!Y9
 MF RANGE
Z9�RANGE Y9
Z9�(�/Y9)-�/Y9
 DF QTILES
Z9�X9 QTILES Y9
Z9�(0.5+(�Y9)�(�X9-1)�X9)LI SORT Y9
 MF QUARTILES
Z9�QUARTILES Y9
Z9�4 QTILES Y9
 MF RANKS
Z9�RANKS Y9
Z9�(DIS Y9)TIES��Y9
 DF REG
R�V REG DATA;B;F;K;MSE;MSR;N;RSQ;SEB;SSE;SSR;SST;T;X;Y;YEST;VC
X�1,DATA[;�1�V]
Y�,DATA[;�1�V]
N�(�X)[1]
K�(�X)[2]-1
B�Y�X
YEST�X+.�B
SST�+/(Y-(+/Y)�N)*2
SSE�+/(Y-YEST)*2
SSR�SST-SSE
MSR�SSR�K
MSE�SSE�N-K+1
F�MSR�MSE
VC�(�(�X)+.�X)�MSE
SEB�(1 1�VC)*0.5
T�B�SEB
RSQ�SSR�SST
R�'            REGRESSION COEFFICIENTS' ON ' '
R�R ON '             COEFF.      S.E.       T'
R�R ON 8 0 11 5 10 5 10 2�(0,�1�V)BY B BY SEB BY T
R�R ON(2 1�' ')ON '            ANALYSIS OF VARIANCE' ON ' '
R�R ON '                    D.F.    S.S.        M.S.       F'
R�R ON 'REGRESSION',12 0 12 5 12 5 8 2�K,SSR,MSR,F
R�R ON 'ERROR',17 0 12 5 12 5�(N-K+1),SSE,MSE
R�R ON 'TOTAL',17 0 12 5�(N-1),SST
R�R ON 'S. E. OF ESTIMATE',17 5�MSE*0.5
R�R ON 'R-SQUARED',25 5�RSQ
 MF VC
Z9�VC Y9
Z9�(TRP DEVIATES Y9)��1+1��Y9
 MF RCDIAG
Z9�RCDIAG Y9
Z9�Y9�((1 1�Y9)�.�1 1�Y9)*0.5
 DF RHO
Z9�X9 RHO Y9
Z9�(RANKS X9)RHOR RANKS Y9
 DF RHOR
Z9�X9 RHOR Y9
Z9�1-(6�+/(X9-Y9)*2)��/�1 0 1+�Y9
 MF ROW
Z9�ROW Y9
Z9�((��/�Y9)ׯ2�1 1,(�Y9))�Y9
 MF RSIMPLEX
R�RSIMPLEX A;B;I;K;L;M;N;P;S;T;V;X;XB;Z;ZERO
ZERO�1E�6
M�(�A)[1]-1
N�(�A)[2]-1
T�((1 0�A),[1](-A[1;]),[0.5]-+�1 0�A),(�M+2)�.=�M+2
B�N+�M
P�M+2
LOOP:XB�T[�M;N+1]
P�P-(P=M+2)^T[P;N+1]�-ZERO
S�P-M+1
Z�T[P;N+1+�M+2]+.�T[;(~(�N)�B)/�N]
�(^/Z�-ZERO)/END
K�((~(�N)�B)/�N)[Z��/Z]
X�T[;N+1+�M+2]+.�T[;K]
V�((�2�X)>ZERO)/�M
�(0=�V)/UNBOUNDED
L�V[(XB[V]�X[V])��/XB[V]�X[V]]
T[L;N׼M+3]�T[L;N׼M+3]�X[L]
I�(L��M+2)/�M+2
T[I;N׼M+3]�T[I;N+�M+3]-X[I]�.�T[L;N+�M+3]
B[L]�K
�LOOP
UNBOUNDED:S��1
END:R�(A,0,[1]T[�B;N+1+�M]),(S,T[P;N+1]),[1]B[�B],[1.5]XB[�B]

 DF SCALE
Z9�X9 SCALE Y9
Z9��(Y9-X9[1])�X9[2]
 MF SORT
Z9�SORT Y9
Z9�Y9[�Y9]
 DF SIGMA
Z9�X9 SIGMA Y9
Z9��((0=0=�X9)/'(�1� X9 ) SIGMA +/[�1� X9 ] Y9 '),(0�0=�X9)/' Y9 '
 MF SD
Z9�SD Y9
Z9�(VAR Y9)*0.5
 DF SFV
Z9�X9 SFV Y9
Z9�FV X9 SCALE Y9
 MF SND
Z9�SND Y9
Z9�|(-Y9>0)+0.5�(1+((|Y9)�.*�6)+.�SNDC)*�16
 NF SNDC
Z9�SNDC
Z9�0.049867347 0.0211410061 0.0032776263 0.000380036 0.0000488906 5.383E�6
 DF SS
Z9�X9 SS Y9
Z9�(MEANSQ((~(���Y9)�X9)/���Y9)SIGMA X9 DELTA Y9)��/�Y9
 MF SUMMARY
R�SUMMARY X;D;F;M;N;Q;V
F�8 0+NDP X
R�'SAMPLE SIZE',11 0�N��D�SORT X
R�R ON 'MINIMUM',(F+7 0)�D[1]
R�R ON 'MAXIMUM',(F+7 0)�D[N]
R�R ON 'RANGE',(F+9 0)�-/D[N,1]
R�R ON 'MEAN',(F+13 2)�AM X
R�R ON 'VARIANCE',(F+12 5)�V�VAR X
R�R ON 'ST. DEVIATION',(F+7 5)�V*0.5
R�R ON 'MEDIAN',(F+10 1)�MEDIAN X
R�R ON 'MODE',(N>�M)/(F+10 0)�M�MODE X
R�R ON 'LOWER QUARTILE',F�1�Q�QUARTILES X
R�R ON 'UPPER QUARTILE',F��1�Q
 DF TIES
Z9�X9 TIES Y9
Z9�((X9+.�Y9)�+/X9)+.�X9
 MF TRP
Z9�TRP Y9
Z9�(�Y9)+.�Y9
 DF TO
Z9�X9 TO Y9
Z9��((0=X9>Y9)/' X9 +0,� Y9 - X9 '),(0�X9>Y9)/'� Y9  TO  X9 '
 MF TRANS
R�TRANS T;D;S
�(S�ABCHECK T)/END
S�NWCR T
LOOP:D�S DUAL T
�(0=1�D)/END
S�((0,D),S)NEWSOLN T
�LOOP
END:R�(S,[1]1�D)OPTSOLNTR T

 MF TT
Z9�TT Y9
Z9�(Y9�2)�0,��1+2*Y9
 MF TWTAB
Z9�TWTAB Y9
Z9�(�/Y9)�1�FV 1+(�/Y9)�Y9-1
 MF VAR
Z9�VAR Y9
Z9�(+/(Y9-AM Y9)*2)��1+�Y9
 