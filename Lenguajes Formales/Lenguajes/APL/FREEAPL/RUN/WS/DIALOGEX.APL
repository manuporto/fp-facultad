apl\11
fuzz 1e-13
origin 1
width 72
digits 9
DA l 2 9 9
       @      D@      D@     @_@      S@      Y@                              Y@      @      @      I@      ,@      �                              �?      N@      @      N@      ,@      Y@              I@      �?      Y@      @      6@      I@      ,@      �      I@                      �?      N@      6@      N@      ,@     @Y@      I@      I@      �?      Y@      @     �C@      I@      ,@      �      Y@                      �?      N@     �C@      N@      ,@     �Y@      Y@      I@      �?       @      1@      L@      >@      .@      �?     �b@                      @     �P@      L@      >@      .@       @     �b@                CH r 2 9 50
Address Query                                     Name                                              Willy Willysen                                    Street Address                                    4, Long street                                    ZIP and City                                      55566 Somewhere                                   &OK                                               &Cancel                                           
CH countries 2 15 14
Austria       Belgium       Denmark       Finland       France        Germany       Greece        Italy         Ireland       Luxemburg     Netherlands   Portugal      Spain         Sweden        United Kingdom
DA lempty 2 1 9
              4@      4@      i@      i@                                CH rempty 2 1 7
Caption
DA ll 2 23 9
      6@      4@      4@      i@      i@      Y@                              Y@      $@      $@     �V@      ,@      �                              �?      Y@      $@     �V@      ,@      Y@              I@      �?      Y@      $@      >@     �V@      ,@      �      I@                      �?      Y@      >@     �V@      ,@     @Y@      I@      I@      �?      Y@      $@      I@     �V@      ,@      �      Y@                      �?      Y@      I@     �V@      ,@     �Y@      Y@      I@      �?      Y@      $@     �Q@     �V@      ,@      �     �b@                      �?      Y@     �Q@     �V@      ,@     �Y@     �b@      I@      �?      Y@      $@     �V@     �V@      ,@      �      i@                      "@      Y@     �V@     �V@     �F@      Z@      i@      I@      �?      Y@      $@     �[@     �V@      ,@      �     @o@                      Y@      $@      ^@     �V@      ,@      �     @o@                      "@      Y@      ^@     �V@     �F@     @Z@     @o@      I@      �?      Y@      $@     �a@      D@      ,@      �     �r@                      �?      I@     �a@      D@      ,@     �Z@     �r@      D@      �?      @      $@      d@     @U@      9@     �Z@     �u@      �?      �?      @      .@     @e@     �A@      ,@      [@      y@                      @     �K@     @e@     �A@      ,@     @[@      y@                      @      Y@     �a@     �V@      M@     �[@      |@      @      �?      @     �[@     �b@     �Q@      ,@     �[@      |@                      @     �[@     `d@     �Q@      ,@      \@      |@                      @     �[@     @f@     �Q@      ,@     @\@      |@                CH rr 2 23 23
Caption                Your name:                                    Street address:                               City:                                         ZIP Code:                                     Country:               countries              Additional information:Education:             education              Age:                                          Sex                    &Male                  &Female                Other                  &Confidential          &Technical info        &Non-member            
CH education 2 12 16
Astronomy       Biology         Chemistry       Computer scienceEconomics       History         Law             Mathematics     Medicine        Physics         Social sciences Theology        
CH note 2 10 45
This ws contains examples of �dialog use.    Variables l, ll and lempty are left, r, rr   and rempty right arguments. Example of use:       result�l �dialog r                      Variables countries and education are text   matrices for use with combobox (and listbox).                                             Niladic function update shows how data storedin workspace variables may be updated using  �dialog.                                     
NF update
update;i;z
i�0
l1:�((1��name)<i�i+1)/l2
r[3;]�name[i;]
r[5;]�addr[i;]
r[7;]�zip[i;]
z�l �dialog r
name[i;]�z[1;]
addr[i;]�z[2;]
zip[i;]�z[3;]
�l1
l2:
 CH name 2 3 50
John Johnson                                      Carl Carlson                                      Willy Willysen                                    
CH addr 2 3 50
1, Main Street                                    9, Home Street                                    4, Long street                                    
CH zip 2 3 50
00055 Biigcity                                    99999 Nowhere                                     55566 Somewhere                                   
