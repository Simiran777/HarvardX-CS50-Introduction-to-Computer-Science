import csv
import sys


def main():
    x = []
    status = 0
    sequence = []
    data = []
    result = ['No match']
    while status != 1:
        # TODO: Check for command-line usage
        if '.csv' in sys.argv[1] and '.txt' in sys.argv[2]:
            status += 1
        else:
            print('Usage: python dna.py data.csv sequence.txt')

        if status == 1:
            # TODO: Read database file into a variable
            with open(sys.argv[1], newline='') as f1:
                reader = csv.reader(f1)
                row1 = next(reader)
                for row in reader:
                    data.append(row)

                # TODO: Read DNA sequence file into a variable
                with open(sys.argv[2], 'r') as f2:
                    sequence = f2.read()

                    # TODO: Find longest match of each STR in DNA sequence
                    for i in range(1, len(row1)):
                        longest_run = longest_match(sequence, row1[i])
                        x.append(str(longest_run))

                # TODO: Check database for matching profiles
                for j in range(len(data)):
                    if data[j][1:] == x:
                        result.append(data[j][0])

    return print(result[-1])


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
