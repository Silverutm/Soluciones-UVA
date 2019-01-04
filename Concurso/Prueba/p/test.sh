#!/bin/sh

lang="$1"
printf "Generating interactive files...\n"
java -jar libinteractive.jar generate guessnum.idl cpp $lang --makefile
printf "\nTesting...\n"
make run < test.in
