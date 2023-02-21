@echo off

set	PROGRAM="%~1"

set OUT="%TEMP%\Out.txt"

echo Checking equal files
%PROGRAM% equal1.txt equal2.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% equal-out.txt 
if ERRORLEVEL 1 goto err

echo Checking empty files
%PROGRAM% empty1.txt empty2.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% empty-out.txt 
if ERRORLEVEL 1 goto err

echo Checking russian symbols
%PROGRAM% russianEqual1.txt russianEqual2.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% russianEqual-out.txt 
if ERRORLEVEL 1 goto err

echo Checking first bigger file than second
%PROGRAM% bigger.txt smaller.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% bigger-smaller-out.txt 
if ERRORLEVEL 1 goto err

echo Checking first longer file than second
%PROGRAM% longer.txt shorter.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% longer-shorter-out.txt 
if ERRORLEVEL 1 goto err

echo Checking without files
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 2 goto err
fc %OUT% noFiles-out.txt 
if ERRORLEVEL 1 goto err

echo Checking without second file
%PROGRAM% oneFile.txt > %OUT%
if NOT ERRORLEVEL 3 goto err
fc %OUT% oneFile-out.txt 
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1