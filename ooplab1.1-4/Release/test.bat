cls
@echo off
SET program="%1"
if %program% == "" goto err

%program% > out.txt
if not ERRORLEVEL 1 goto testFailed

%program% input1.txt > out.txt
if not ERRORLEVEL 1 goto testFailed

%program% input1.t output.txt > out.txt
if not ERRORLEVEL 1 goto testFailed

%program% input1.txt output.txt word1 word2 word3 > out.txt
if not ERRORLEVEL 1 goto testFailed 

%program% input1.txt output.txt ma > out.txt
if not ERRORLEVEL 1 goto testFailed    

%program% input1.txt output.txt ma 14 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt output1True.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit 

:testFailed
echo Testing failed
exit 

:err
echo Usage: test.bat <Path to program>
