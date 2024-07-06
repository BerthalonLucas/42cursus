#!/bin/bash

for i in {1..100}
do
    ./philo 6 200 100 100 15 | grep "died" | wc -l | grep -c "1"
done
