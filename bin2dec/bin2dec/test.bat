@echo off

set	PROGRAM="%~1"

set OUT="%TEMP%\Out.txt"

echo Checking correct bin2dec
%PROGRAM% bin2dec.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% bin2dec-out.txt 
if ERRORLEVEL 1 goto err

echo Checking error without file
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% noFile-out.txt 
if ERRORLEVEL 1 goto err

echo Checking error empty file
%PROGRAM% empty.txt > %OUT%
if NOT ERRORLEVEL 2 goto err
fc %OUT% empty-out.txt 
if ERRORLEVEL 1 goto err

echo Checking error out of range
%PROGRAM% overRange.txt > %OUT%
if NOT ERRORLEVEL 3 goto err
fc %OUT% overRange-out.txt 
if ERRORLEVEL 1 goto err

echo Checking error letters in number
%PROGRAM% letterInNumber.txt > %OUT%
if NOT ERRORLEVEL 4 goto err
fc %OUT% letterInNumber-out.txt 
if ERRORLEVEL 1 goto err

echo Checking error uncorrect digit
%PROGRAM% uncorrectDigit.txt > %OUT%
if NOT ERRORLEVEL 4 goto err
fc %OUT% uncorrectDigit-out.txt 
if ERRORLEVEL 1 goto err


echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1