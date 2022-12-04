certUtil -hashfile "C:\Users\Cou\VirtualBox VMs\Debian3\Debian3.vdi" sha1  > .\signature_tmp.txt
SET COUNT=0
SET DATA=""
FOR /F "" %%i IN (signature_tmp.txt) DO @CALL :MYSET %%i
ECHO %DATA% > .\rep\signature.txt
EXIT /B

:MYSET
SET /A COUNT=%COUNT%+1
@REM 1行目だったらDATAへSET
IF %COUNT%==2 SET DATA=%1
@REM EXIT /B で呼び出し元へ戻る
EXIT /B