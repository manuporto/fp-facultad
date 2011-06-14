@echo off
rem
rem  env.bat
rem 

rem  This batch file sets the environment variables necessary for running
rem  the mic1 software.

rem  1) comment out the following 4 commands

echo   NOTE: YOU NEED TO EDIT THE FILE ENV.BAT BEFORE YOUR mic1 
echo   SOFTWARE will WORK CORRECTLY.
pause
goto end

rem  2) Set the path to point to the bin directory of the JDK

path C:\jdk1.2\bin;%path%

rem  3) Set the classpath to point to the classes.zip file from the mic1
rem     distribution

set CLASSPATH=C:\mic1\classes.zip

:end
