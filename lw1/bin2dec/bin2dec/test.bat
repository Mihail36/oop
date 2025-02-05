@echo off

set	PROGRAM="%~1"
set OUT="%TEMP%\Out.txt"

echo Checking number zero
%PROGRAM% 0 > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% zero-out.txt 
if ERRORLEVEL 1 goto err

echo Checking number one
%PROGRAM% 1 > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% numberOne-out.txt 
if ERRORLEVEL 1 goto err

echo Checking without arguments
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% argumentsNotFound-out.txt 
if ERRORLEVEL 1 goto err

echo Checking over range
%PROGRAM% 10101101011010110101101011010111 > %OUT%
if NOT ERRORLEVEL 2 goto err
fc %OUT% overRange-out.txt 
if ERRORLEVEL 1 goto err

echo Checking letterInNumber
%PROGRAM% 1001b10 > %OUT%
if NOT ERRORLEVEL 3 goto err
fc %OUT% letterInNumber-out.txt 
if ERRORLEVEL 1 goto err

echo Checking uncorrect digit found
%PROGRAM% 101010019101 > %OUT%
if NOT ERRORLEVEL 3 goto err
fc %OUT% uncorrectDigitFound-out.txt 
if ERRORLEVEL 1 goto err


echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1