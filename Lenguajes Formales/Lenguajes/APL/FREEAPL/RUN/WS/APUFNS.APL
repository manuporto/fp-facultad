apl\11
fuzz 1e-13
origin 1
width 72
digits 9
DF alle
z�a alle b;c
a�(�2�1 1,�a)�a
b�(�2�1 1,�b)�b
c�(�1��a)��1��b
z�(((1��a),c)�a),[�io]((1��b),c)�b
 DF Cc
Z�A Cc B;I
Z�,B
I�(Z=A[�io])/��Z
Z[I]�A[�io+1]
Z�(�B)�Z
 DF BEs
Z�X BEs Y;C;RA;RB
��CATENATES MATRICES ALONG THE LAST DIMENSION
�X AND Y CAN ALSO BE VECTORS
X�(RA��2�1 1,�X)�X
Y�(RB��2�1 1,�Y)�Y
C�1�RA�RB
X�(RA�C,0)�X
Y�(RB�C,0)�Y
Z�X,Y
 DF CEn
Z�W CEn D;I
�CENTERS D IN MATRIX Z OF WIDTH W
D�(�2�1 1,�D)�D
Z�((1��D),W)�D
I�-�0.5�+/^\' '=�Z
Z�I�Z
 MF CLm
Z�CLm X
�RESHAPES VECTOR X INTO A ONE COLUMN MATRIX
�(1���Z�X)/0
Z�((�X),1)�X
�840801 08.14
 MF DBr
Z�DBr X
Z�(�/X�' ')/[1]X
 MF DLb
Z�DLb X
�DELETES LEADING BLANKS FROM VECTOR X
Z�(~^\X=' ')/X
 MF DTb
Z�DTb X;Y
�DROPS TRAILING BLANKS
Z�(��\���(�2�1 1,�Y)�Y�' '�X)/X
 MF DTBa
Z�DTBa X
�DROPS TRAILING BLANKS FROM AN ARRAY X
Z�((-��X)��/(1��Z)�Z�,1-(X=' ')�1)�X
�840619 12.32
 DF FLEFt
Z�W FLEFt D               
�LEFT ADJUSTS D TO WIDTH W
D�(�2�1 1,�D)�D           
D�((1��D),W)�D            
Z�(+/^\D=' ')�D            DF FRIGHt
Z�W FRIGHt D
�RIGHT ADJUSTS D TO WIDTH W 
D�(�2�1 1,�D)�D             
D�((1��D),W)�D              
Z�(((D�' ')�.׼Z)-Z��1��D)�D MF KASVU
R�KASVU X;MX;n;i                          
� MATRIISIN X LOGARITMINEN KASVUTRENDISARAKE  
MX�(�2�1,�X)�X                                
i�0                                           
R�((n�1��MX),1)�0                             
L0:�(n<i�i+1)/L1                              
R[i;1]�100�(*�1�(�MX[i;])�1,[1.1]�(�MX[i;]))-1
�L0                                           
L1:�(1=��X)/'R�,R'
 MF LOWEr
Z�LOWEr X;A;B;D                  
A�'ABCDEFGHIJKLMNOPQRSTUVWXYZ���'
B�'abcdefghijklmnopqrstuvwxyz���'
Z�,X                             
D�(Z�A)/��Z                      
Z[D]�B[A�Z[D]]                   
Z�(�X)�Z                          MF UPPEr
Z�UPPEr X;A;B;D                  
B�'ABCDEFGHIJKLMNOPQRSTUVWXYZ���'
A�'abcdefghijklmnopqrstuvwxyz���'
Z�,X                             
D�(Z�A)/��Z                      
Z[D]�B[A�Z[D]]                   
Z�(�X)�Z                          DF viereen
z�a viereen b;c
a�(2�(�a),1 1)�a
b�(2�(�b),1 1)�b
c�(1��a)�1��b
z�((c,1��a)�a),(c,1��b)�b DF �abs
M�N �abs X;MX                                                   
� MATRIISIN X ABSOLUUTTISET EROTUKSET RIVEITTAIN SARAKEVALEIN N 
MX�(�2�1,(�X))�X                                                
M�((0,N)�MX)-(0,-N)�MX                                          
�(1=��X)/'M�,M'                                                 
 DF �pros
M�N �pros X;MX;MXA                                                
� MATRIISIN X PROSENTUAALISET EROTUKSET RIVEITTAIN SARAKEVALEIN N 
MX�(�2�1,(�X))�X                                                  
MXA�N�MX                                                          
MX�(0,-N)�MX                                                      
MXA�(0,-N)�MXA                                                    
M�((MXA�MX)-1)�100                                                
�(1=��X)/'M�,M'                                                   
 