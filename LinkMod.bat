@echo off

cd /D "%~dp0"

IF exist "P:\NPCPro\" (
	echo Removing existing link P:\NPCPro
	rmdir "P:\NPCPro\"
)

echo mklink /J "P:\NPCPro\" "%~dp0"
mklink /J "P:\NPCPro\" "%~dp0"

echo Done
