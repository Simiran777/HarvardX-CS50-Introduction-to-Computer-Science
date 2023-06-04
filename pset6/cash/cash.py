from cs50 import get_float

# Declare variable for keeping count
count = 0

# While change is NAN, prompt user
while True:
    cash = get_float("Change owed: ")
    if cash >= 0:
        cents = round(cash * 100)
        break

# While cents is greater than 0, take away largest coin possible  and increment count
while cents > 0:
    if cents >= 25:
        cents = cents - 25
        count = count + 1
    elif cents >= 10:
        cents = cents - 10
        count = count + 1
    elif cents >= 5:
        cents = cents - 5
        count = count + 1
    elif cents >= 1:
        cents = cents - 1
        count = count + 1

print(count)