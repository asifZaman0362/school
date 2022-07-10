add() {
	return $(( $1 + $2 ))
}

echo "Enter a number: "
read x
echo "Enter another number: "
read y
add $x $y
echo "$x + $y = $?"