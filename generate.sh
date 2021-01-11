#!/bin/bash
python3 text_cleaner.py
truncate --size 0 generated.txt
./Generator 100000 > generated.txt
