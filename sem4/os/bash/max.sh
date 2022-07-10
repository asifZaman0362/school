max() {
	if [[ $1 -gt $2 ]]; then
		if [[ $1 -gt $3 ]]; then
			if [[ $1 -gt $4 ]]; then
				echo "$1 is greatest"
			else
				echo "$4 is greatest"
			fi
		else
			if [[ $3 -gt $4 ]]; then
				echo "$3 is greatest"
			else
				echo "$4 is greatest"
			fi
		fi
	else
		if [[ $2 -gt $3 ]]; then
			if [[ $2 -gt $4 ]]; then
				echo "$2 is greatest"
			else
				echo "$4 is greatest"
			fi
		else
			if [[ $3 -gt $4 ]]; then
				echo "$3 is greatest"
			else
				echo "$4 is greatest"
			fi
		fi
	fi 
}

echo "Enter first number: "
read first
echo "Enter second number: "
read second
echo "Enter third number: "
read third
echo "Enter fourth number: "
read fourth

max $first $second $third $fourth