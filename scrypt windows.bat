@echo off
cls
@ECHO.%date:~0,10%
@ECHO.%time:~0,8%
echo compilando programa...
make cleanW
make
echo ejecutando programa....
puzzle8.exe
@ECHO.%date:~0,10%
@ECHO.%time:~0,8%