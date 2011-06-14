
Gofer new
	squeaksource: 'MetacelloRepository';
	package: 'ConfigurationOfPharo';
	load.

((Smalltalk at: #ConfigurationOfPharo) project version: '1.0-rc2.10508') load.

Gofer new
	squeaksource: 'ImageForDevelopers';
	package: 'ImageForDevelopers-pharo';
	load.

(Smalltalk classNamed: #DEVImageCreator) default install.

