@echo off
IF %1.==. GOTO ERROR_MSG

git pull
git add -A
git commit -m %*
git config --global credential.helper wincred
git push origin master
git pull

GOTO END

:ERROR_MSG
ECHO: Please Specify a Commit Msg

:END