cls
rem @echo off
SET program="%1"
if %program% == "" goto err

%program% test/input1.txt > test/output1.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\output1.txt test\reference\output1.txt
if ERRORLEVEL 1 goto testFailed

%program% test/inputEmpty.txt > test/outputEmpty.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\outputEmpty.txt test\reference\outputEmpty.txt
if ERRORLEVEL 1 goto testFailed

%program% test/inputIncorrect.txt > test/outputIncorrect.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\outputIncorrect.txt test\reference\outputIncorrect.txt
if ERRORLEVEL 1 goto testFailed

%program% test/inputNegativData.txt > test/outputNegativData.txt
if ERRORLEVEL 1 goto testFailed
fc /b test\outputNegativData.txt test\reference\outputNegativData.txt
if ERRORLEVEL 1 goto testFailed  

echo OK
exit /b

:testFailed
echo Testing failed
exit /b

:err
echo Usage: test.bat <Path to program>
