#!/bin/bash

file=$1

prev_line_start_lower=false

while read line; do
    if [[ $line =~ ^[a-z].* ]]; then
        if ! $prev_line_start_lower; then
            echo -n "$line"
        else
            echo -n " $line"
        fi
        prev_line_start_lower=true
    else
        echo
        echo -n "$line"
        prev_line_start_lower=false
    fi
done < $file