#!/bin/bash
readonly N=100000
python3 text_cleaner.py
truncate --size 0 generated.txt
./Generator $N > generated.txt
