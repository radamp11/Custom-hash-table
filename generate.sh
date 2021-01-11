#!/bin/bash
truncate --size 0 generated.txt
./Generator 100 > generated.txt
