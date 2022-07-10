factorial() {
	if [[ $1 -lt 1 ]]; then
		return 1
	else
		factorial $(($1 - 1))
		return $(($1 * $?))
	fi
}

echo "Enter a number: "
read number
factorial $number
echo "Factorial = $?"