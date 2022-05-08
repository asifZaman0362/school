def lagrange_interpolation_y(x, y, y_approx) -> float:
    x_approx = 0
    if len(x) != len(y): 
        raise Exception("There are unbalanced number of data points on both axes!")
        return False
    for i in range(len(x)):
        xp = 1
        yp = 1
        for j in range(len(x)):
            xp *= y_approx - y[j] if i != j else 1
            yp *= y[i] - y[j] if i != j else 1
        x_approx += xp / yp * x[i]
    return x_approx

if __name__ == "__main__":
    try:
        count = int(input("Enter the number of samples: "))
        x, y = [], []
        for i in range(count):
            x.append(float(input(f"x{i}: ")))
            y.append(float(input(f"y{i}: ")))
        target_y = float(input("Enter the target y value to be approximated for: "))
        approx = lagrange_interpolation_y(x, y, target_y)
        print(f"Approximated value for {target_y} = {approx}")
    except ValueError as error:
        print(error)
