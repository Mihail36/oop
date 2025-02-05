@echo off

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

echo Checking multiplication by standard matrix
%PROGRAM% positiveMatrixFirst.txt positiveMatrixSecond.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% positiveMatrix-out.txt
if ERRORLEVEL 1 goto err

echo Checking multiplication by zero matrix
%PROGRAM% positiveMatrix.txt zeroMatrix.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% zeroMatrix.txt
if ERRORLEVEL 1 goto err

echo Checking multiplication by unix matrix
%PROGRAM% positiveMatrix.txt unixMatrix.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% positiveMatrix.txt
if ERRORLEVEL 1 goto err

echo Checking no arguments
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoFile-out.txt
if ERRORLEVEL 1 goto err

echo Checking not entered second file
%PROGRAM% positiveMatrix.txt > %OUT%
if NOT ERRORLEVEL 2 goto err
fc %OUT% NoSecondFile-out.txt
if ERRORLEVEL 1 goto err

echo Checking not exist second file
%PROGRAM% positiveMatrix.txt something.txt > %OUT%
if NOT ERRORLEVEL 3 goto err
fc %OUT% notExistSecond-out.txt
if ERRORLEVEL 1 goto err

echo Checking not exist first file
%PROGRAM% something.txt positiveMatrix.txt > %OUT%
if NOT ERRORLEVEL 3 goto err
fc %OUT% notExistFirst-out.txt
if ERRORLEVEL 1 goto err

echo Checking empty second file
%PROGRAM% positiveMatrix.txt emptyFile.txt > %OUT%
if NOT ERRORLEVEL 4 goto err
fc %OUT% emptySecond-out.txt
if ERRORLEVEL 1 goto err

echo Checking empty first file
%PROGRAM% emptyFile.txt positiveMatrix.txt > %OUT%
if NOT ERRORLEVEL 4 goto err
fc %OUT% emptyFirst-out.txt
if ERRORLEVEL 1 goto err


echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1