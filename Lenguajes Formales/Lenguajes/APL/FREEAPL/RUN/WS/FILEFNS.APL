apl\11
fuzz 1e-13
origin 1
width 72
digits 9
DF filevar
v filevar fn;fd;rc
fd�0 �creat fn
rc��close fd
fd�1 �open fn
rc�fd �write v
rc��close fd
 MF readcvar
z�readcvar fn;fd;rc
fd�0 �open fn
z�fd �read 32000
rc��close fd
 MF readnvar
z�readnvar fn
z��float readcvar fn
 CH note 2 4 50
This workspace contains three functions:          rc�var filevar 'filename' � saves var in file     var�readcvar 'filename' � reads char var from filevar�readnvar 'filename' � reads num var from file 
