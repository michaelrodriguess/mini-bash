#!/bin/bash

make -C ../
bash < testing_my_shell.txt > out_bash.txt 
bash -c "../minishell < testing_my_shell.txt > out_mini.txt"
awk '!/microtano/' out_mini.txt > novo_out_mini.txt
awk '!/_=/' novo_out_mini.txt > new_out_mini.txt
awk '!/_=/' out_bash.txt > new_out_bash.txt
diff new_out_mini.txt new_out_bash.txt > diff.txt
rm novo_out_mini.txt out_mini.txt out_bash.txt
