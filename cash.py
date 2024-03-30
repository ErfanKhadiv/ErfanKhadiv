from cs50 import get_float


def main():
    while True:
        changes = get_float("Enter your change: ")
        if changes > 0:
            break
    cents = changes * 100
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    coins = quarters + dimes + nickels + pennies

    print(int(coins))


def calculate_quarters(cents):
    quarters = cents // 25
    return quarters


def calculate_dimes(cents):
    dimes = cents // 10
    return dimes


def calculate_nickels(cents):
    nickels = cents // 5
    return nickels


def calculate_pennies(cents):
    pennies = cents
    return pennies


main()
