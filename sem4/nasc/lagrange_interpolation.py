def lagrange_interpolation_y(x, y, y_approx) -> float:
    x_approx = 0
    if len(x) != len(y): 
        raise Exception("There are unbalanced number of data points on both axes!")
        return False
    for i in range(len(x)):
        prod = 1
        for j in range(len(x)):
            prod *= (y_approx - y[j]) / (y[i] - y[j]) if i != j else 1
        x_approx += prod * x[i]
    return x_approx

def lagrange_interpolation_x(x, y, x_approx) -> float:
    y_approx = 0
    if len(x) != len(y):
        raise Exception("There are unbalanced number of data points on both axes!")
        return False
    for i in range(len(x)):
        prod = 1
        for j in range(len(x)):
            prod *= (x_approx - x[j]) / (x[i] - x[j]) if i != j else 1
        y_approx += prod * y[i]
    return y_approx


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
