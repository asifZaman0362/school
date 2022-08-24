#!/bin/bash

function factorial () {
    if (( $1 <= 2 )); then
        echo 2
    else
        last=$( factorial $(( $1 - 1 )) )
        echo $(( $1 * $last ))
    fi
}

echo "Enter a number: "
read number
result=$(factorial $number )
echo "$number! = $result"
