apl\11
fuzz 1e-13
origin 1
width 72
digits 9
MF ANG
Z�ANG A;S                              
Z�0                                    
�(S=A[1;2]+S��/1 1�|A)/0               
Z�((��2)-�3�(A[1;1]-A[2;2])�2�A[1;2])�2
 DF AT
Y�P AT X          
Y�(X�.*�1+��P)+.�P
 MF AVE
M�AVE A        
M�(+�A)�(�A)[1]
 DF BACKSUB
Z�S BACKSUB A                                
Z�(0,S^.=S+A[;1��A])�0                       
�(1=1��A)/0                                  
�(S^.=S+A[;1])/J                             
Z�S BACKSUB 1 1�A                            
Z�(((�1�A[1;])-(�1�1�A[1;])+.�Z)�A[1;1]),[1]Z
�0                                           
J:Z�0,[1]S BACKSUB 0 1�A                     
�(0=1��Z)/0                                  
Z�(1,1�Z[;1]),Z                              
 MF CANFORM
Z�CANFORM A                      
Z�3 INTINV 1��A                  
Z��0.5+(Z[1;;]+.�A+.�Z[2;;]),[1]Z
 DF CENTSECT
Z�E CENTSECT I;X;Y      
L:Y�FCN X�5 CHOP I      
I�X[�1 0+((�Y)��Y[1])�1]
�(0=�Z�(E>|Y)/X)/L      
 DF CHOP
X�N CHOP AB           
X�AB[1]+(0,�N)�--/AB�N
 DF DBLSHFT
Z�B DBLSHFT A;I                                 
Z�((B[1;]-.ײB[2;])�I)+A+.�A-(+/1 1�B)�I�ID 1��A
 NF DESCRIBE
DESCRIBE                                 
'The functions in this workspace are'    
'described in the book'                  
'  APPLIED LINEAR ALGEBRA WITH APL'      
'by Professor Garry Helzer of the'       
'University of Maryland.'                
'This college level textbook is to be'   
'published in early 1983.'               
' '                                      
'The programs in this workspace are '    
'Copyright (c) 1983, by Garry D. Helzer.'
'All rights reserved; Little, Brown,'    
'and Co., Boston, MA 02106'              
 MF DET
Z�DET A;R                         
A�(R�SPRFLCTR A[;1])+.�A          
Z�A[1;1]ׯ1*(�1+1��A)ן/,R�ID 1��A
�(1=1��A)/0                       
Z�Z�DET 1 1�A                     
 MF DFCN
Z�DFCN X          
Z�2 2�2 8 2 �2�X,X
 MF DIAG
Z�DIAG V                  
Z�(���V)�(2��V)�((�V)*2)�V
 MF ECHELON
Z�ECHELON A    
Z�(GAUSS A)+.�A
 MF ECHFORM
Z�ECHFORM A     
Z�4 INTINV 1��A 
Z��0.5+(Z+.�A),Z
 DF EVALAT
Z�C EVALAT T                  
Z�((T*3),T�T�.-(1�T),�1�T)+.�C
 MF FCN
Z�FCN X                          
Z�(2 3�1 4 �16 1 �1 �1)+.�(X,1)*2
 MF FIB
Z�FIB N   
Z�N�1 1   
�(N�2)/0  
Z�FIB N-1 
Z�Z,+/�2�Z
 MF GAUSS
G�GAUSS A;S;P;L;T;B;V;K;R                      
S��/,|A                                        
P�L�0                                          
T��A                                           
A�A,ID 1�T                                     
CYCLE:V�+�B�|(L,P)�T�A                         
�((�V)<K�(S�S+V)�1)/END                        
R�B[;K]��/B[;K]                                
A�((L+1),P+K)LDR((L+1),P+K)PIVOT(L+1,R)SWITCH A
�CYCLE,(L�L+1),P�P+K                           
END:G�(-T[1 1])�A                              
 NF GETTFNS
GETTFNS;S;D;B;I;LIM;X;Y                                           
� Get all functions in an APL*PLUS/80 workspace.  JMS.  12-17-82. 
� Requires subroutine GETTRS.                                     
S��GETTRS '��NL 3'D�GETTRS ',�NL 3'D�S�D                        
B�D[;�8]�.�'MOVET2I 'D�B/[1]D                                    
'Functions to bring:'DI�1LIM�1��D                              
LP:��(X�� DEF GETTRS '�VR''',(Y�(' '�D[I;])/D[I;]),''''),' '      
�(X�.�(�X)�Y)�LP'defined.'�(LIM�I�I+1)�LP                       
'Functions defined:'D                                            
 MF GETTRS
Z�GETTRS DATA                                                  
� GET DATA FROM APL*PLUS/80 SYSTEM.  JMS.  12-17-82.           
L:�('OKAY'�.�4���1 1 0 0 1 100 7� ARBIN ��'READY?  ',�TC BEL)�L
Z��DL 1Z�1 1 0 0 60 10000 7� ARBIN DATA,�TC BEL               
Z�(~Z��TC LF,�TC NUL,�TC DEL,�TC BEL)/Z                        
 DF HHLDR
Q�B HHLDR A;Q1;q          
A�(B�.�B+A)/A             
Q�ID 1��A                 
�(0=1��A)/0               
Q1�SPRFLCTR A[;1]         
q�B HHLDR 1 1�Q1+.�A      
Q�Q1+.�((1+1��q)�1),[1]0,q
 MF HILB
Z�HILB N      
Z��Z�.+�1+Z��N
 MF HSHLDR
Q�HSHLDR A      
Q�(�/,|A)HHLDR A
 MF ID
Z�ID N     
Z�(�N)�.=�N
 DF INTINV
Z�S INTINV N;K;V;W;I             
Z�(2,N,N)�I�ID N                 
K�1                              
L:V�(-S-1)+?N�S                  
Z[1;;]�Z[1;;]+.�I+(V�~W)�.�W�K=�N
Z[2;;]�(I-(V�~W)�.�W)+.�Z[2;;]   
�(N�K�K+1)/L                     
Z��0.5+Z                         
 MF JACFIND
Z�JACFIND A;B      
B��/,A�|A�~ID 1��A 
Z�1 2�(0=B)/0     
Z�Z,A[Z�(�/A)�B;]�B
 MF JACOBI
Z�JACOBI A;B;I;K;Q   
Z�I�ID 1��A          
B��/,|A              
L:K�JACFIND A        
�(B=B+A[K[1];K[2]])/0
Q�I                  
Q[K;K]�ROT ANG A[K;K]
A�(�Q)+.�A+.�Q       
Z�Z+.�Q              
�L                   
 DF LDR
Z�X LDR A                     
A[X[1];]�A[X[1];]�A[X[1];X[2]]
Z�A                           
 MF MATBLD
Z�MATBLD N;T 
Z�(0,N)�0    
L:T��        
�(0=�T)/0    
Z�Z,[1]N�T�L
 MF MAX
T�MAX A;M;N;I;J;K;P;S     
K�0�(M�(�A)[1])�N�(�A)[2] 
A��/,|T�A                 
L:J�T[M;]��/�1�T[M;]      
�(A�A+T[M;J])/0           
�(0=�P�(A<A+T[�M;J])/�M)/0
I�P[S��/S��/T[P;N,J]]     
T�(I,J)LDR(I,J)PIVOT T    
�(10>K�K+1)/L             
 DF NEWTON
Z�N NEWTON X0                      
Z�(1,�,X0)�X0                      
�(N=0)/0                           
Z�(N-1)NEWTON X0                   
Z�Z,[1]Z[N;]-(FCN Z[N;])�DFCN Z[N;]
 MF ORTHO
Z�ORTHO A;R;B          
B��/,|A�((�A),�1=��A)�A
R�(�Z�B HHLDR A)+.�A   
Z�Z[;�+/(B+R)�.�B]     
 MF PERP
Z�PERP A;R;B           
B��/,|A�((�A),�1=��A)�A
R�(�Z�B HHLDR A)+.�A   
Z�(0,+/(B+R)�.�B)�Z    
 DF PIVOT
Z�X PIVOT A;P;N                                      
P�ID N�1��A                                          
P[(X[1]��N)/�N;X[1]]�(X[1]��N)/-A[;X[2]]�A[X[1];X[2]]
Z�P+.�A                                              
 DF POLYAT
Z�A POLYAT X                        
Z��0                                
�(0=�X)/0                           
Z�(DET A-(1�X)�ID 1��A),A POLYAT 1�X
 MF PRAXES
Z�PRAXES P                
P�P-(P+.�1��P)�.+(�P)[2]�0
Z�JACOBI P�P+.׳P         
Z�Z[;�1 1�(�Z)+.�P+.�Z]   
 DF QR
Z�S QR A;N;B;Q;K;C                                
Z�STRT A                                          
�(2�N�1��Z)/0                                     
�(S^.=S+,A)/0                                     
C�1                                               
L:A�(�Q)+.�A+.�Q�S HHLDR 4 SCPOW(�2 �2�A)DBLSHFT A
Z�Z+.�Q                                           
�(10=C�C+1)/0                                     
�(N=K�(1 1��^��^\S=S+1 �1�A)�1)/L                 
Z�Z+.�((N,K)�S QR(K,K)�A),(-N,K-N)�S QR(K,K)�A    
 MF RANK
Z�RANK A;S           
S��/,|A              
Z�+/(S+ECHELON A)�.�S
 MF ROT
Z�ROT X        
Z�2 1�.�X+0,��2
 DF SCPOW
Z�P SCPOW A         
Z�A                 
�(P=0)/0            
A�A+.�A�(P-1)SCPOW A
Z�A�(|,A)+.��,A     
 MF SD
S�SD A                    
S�(AVE(A-(�A)�AVE A)*2)*�2
 DF SETUP
A�X SETUP Y;H                
A�(2�(�1�H)+1�H),[1.5]1�H�� X
A�A,6ב(� Y)�H               
 DF SPLINE
CF�X SPLINE Y;S;H                     
S�0,(TRIDI X SETUP Y),0               
CF�((1�S),[1.5]-�1�S)�6�H�H,[1.5]H�� X
CF�CF,(((1�Y),[1.5]-�1�Y)�H)-(H*2)�CF 
 MF SPRFLCTR
Z�SPRFLCTR V;L             
Z�ID�V                     
L�(V+.*2)*�2               
�((L=0)�L^.=L+1�V)/0       
V[1]�V[1]+L�(V[1]�0)-V[1]<0
Z�(2�V�.�V�V+.*2)-Z        
 MF STRT
Z�STRT A;T;D;S                        
Z�ID 1��A                             
�(4��A�,A)/0                          
�(0>D�(((T�-/A[1 4])*2)+4��/A[2 3]))/0
Z��Z                                  
�(S=A[2]+S��/,|A)/0                   
Z�ROT �3�(-T+((T�0)-T<0)�D*�2)�2�A[2] 
 DF SWITCH
Z�X SWITCH A    
A[X;]�A[X[2 1];]
Z�A             
 DF TOTHE
Z�A TOTHE N      
Z�ID 1��A        
�(N=0)/0         
Z�A+.�A TOTHE N-1
 MF TRIDI
Z�TRIDI A                               
Z��/A[1;3 1]                            
�(1=1��A)/0                             
A[2;1 3]�A[2;1 3]-A[1;2 3]�A[1;2]�A[1;1]
Z�TRIDI 1 0�A                           
Z�((A[1;3 2]�A[1;1])+.�1,-1�Z),Z        
 MF ZSCORE2
Z�ZSCORE2 A               
Z�(A-(�A)�AVE A)�(�A)�SD A
 MF �
Z�� X;K      
K���1+�X     
Z�X[K+1]-X[K]
 MF ZSCORE
Z�ZSCORE A;MEANS;sd    
MEANS�(+�A)�(�A)[1]    
A�A-(�A)�MEANS         
sd�((+�A*2)�(�A)[1])*�2
Z�A�(�A)�sd            
 