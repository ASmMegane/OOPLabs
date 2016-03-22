cls
@echo off
SET program="%1"
if %program% == "" goto err

%program% > out.txt
if not ERRORLEVEL 1 goto testFailed

%program% 300 > out.txt
if not ERRORLEVEL 1 goto testFailed

%program% -1 > out.txt
if not ERRORLEVEL 1 goto testFailed

%program% fail > out.txt
if not ERRORLEVEL 1 goto testFailed

%program% 6 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt output1True.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit 

:testFailed
echo Testing failed
exit 

:err
echo Usage: test.bat <Path to program>
