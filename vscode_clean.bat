::@echo off 

@for /d /r %%c in (.pio,.vscode,Debug,settings,Release,Output,DebugConfig) do @if exist %%c ( rd /s /q "%%c" & echo     删除目录%%c) 

@for /r  %%c in (*.gitignore,*.tmp,*.bak ,*.dep,*.sfr,Backup* ) do del "%%c"
pause