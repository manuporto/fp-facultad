@echo off
rem
rem  ijvmasm.bat
rem

rem  This batch file sets environment variables by running env.bat, then
rem  starts the GUI front-end of the IJVM Assembler

call env.bat
java gijvmasm
