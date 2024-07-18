@echo off

REM Set default build type
set BUILD_TYPE=Debug

REM Parse command-line arguments
:parse_args
if "%1" == "" goto end_parse_args
if "%1" == "-b" (
    set BUILD_TYPE=%2
    shift
    shift
    goto parse_args
)
:end_parse_args

echo %BUILD_TYPE%

REM Generate build files
cmake -S . -B .\build -DCMAKE_BUILD_TYPE=%BUILD_TYPE%

REM Build the project
cmake --build .\build --config %BUILD_TYPE%
