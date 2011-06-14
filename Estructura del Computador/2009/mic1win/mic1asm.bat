@echo off
rem
rem
rem  mic1asm.bat
rem

rem  This batch file sets the environment variables by running
rem  env.bat, then starts the mic1 assembler

call env.bat
java gmic1asm
