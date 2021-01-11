#!/bin/bash
truncate --size 0 generated.txt
./Generator >> generated.txt
