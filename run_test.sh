#!/bin/bash

./a.out < input.txt > output.txt

diff gen_output.txt output.txt

rm output.txt