#!/bin/bash

path="/Volumes/Programming/research/PM"
dataPath="${path}/DATA"

inputFileA="${dataPath}/unique0.edgesFinal"
inputFileB="${dataPath}/unique348.edgesFinal"

outputFileA="${dataPath}/Aalpha1.dat"
outputFileB="${dataPath}/Balpha1.dat"

cd $path

# compile
g++ make_graph.cpp random_order.cpp greedy_order.cpp win_prob.cpp count_violations.cpp position_move.cpp main.cpp -o main

# run
./main $inputFileA $outputFileA $inputFileB $outputFileB

# run python (create plot)
python3 ./plot.py $outputFileA $outputFileB $dataPath