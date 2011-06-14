"Preparations"
MCCacheRepository instVarNamed: 'default' put: nil.
!
"Refactoring"
Gofer new
	squeaksource: 'rb';
	package: 'AST-Core';
	package: 'AST-Semantic';
	package: 'Refactoring-Core';
	package: 'Refactoring-Spelling';
	load.
!
"OmniBrowser"
Gofer new
	renggli: 'omnibrowser';
	package: 'OmniBrowser';
	package: 'OB-Standard';
	package: 'OB-Morphic';
	package: 'OB-Shout';
	package: 'OB-Refactory';
	package: 'OB-Regex';
	package: 'OB-SUnitIntegration';
	load.
!
"Tools"
Gofer new
	renggli: 'unsorted';
	package: 'Shout';
	package: 'ShoutWorkspace';
	package: 'RoelTyper';
	package: 'ECompletion';
	package: 'ECompletionOmniBrowser';
	load.
!
"Select Tools"
SystemBrowser default: (Smalltalk at: #OBSystemBrowserAdaptor).

!
"Clear Author"
Author reset.
!
"Clear Monticello Caches"
MCCacheRepository instVarNamed: 'default' put: nil.
MCFileBasedRepository flushAllCaches.
MCMethodDefinition shutDown.
MCDefinition clearInstances.
!
"Cleanup Smalltalk"
Smalltalk flushClassNameCache.
Smalltalk organization removeEmptyCategories.
Smalltalk allClassesAndTraitsDo: [ :each |
	each organization removeEmptyCategories; sortCategories.
	each class organization removeEmptyCategories; sortCategories ].
!
"Cleanup System Memory"
Smalltalk garbageCollect.
Symbol compactSymbolTable.
!
"Save and Quit"
WorldState addDeferredUIMessage: [
	SmalltalkImage current snapshot: true andQuit: true ].
!
