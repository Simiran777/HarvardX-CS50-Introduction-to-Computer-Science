from cs50 import get_string

while True:
    # Take user input
    text = get_string('Text: ')

    # If input is not an empty string, break
    if text != '':
        break


def main():
    if text != '':

        # Calculate letters in text
        letters = get_letters(text)

        # Calculate words in text
        words = get_words(text)

        # Calculate sentences in text
        sentences = get_sentences(text)

        L = round((letters/words) * 100, 2)

        S = round((sentences/words) * 100, 2)

        # Calculate Coleman-Liau Index
        index = round((0.0588 * L) - (0.296 * S) - 15.8)

        # Print the grade according to value of index
        if index < 1:
            print('Before Grade 1')
        elif index > 16:
            print('Grade 16+')
        else:
            print(f'Grade {index}')


def get_letters(text):
    letters = 0
    for i in range(len(text)):
        x = text[i]
        if x.isalpha() == True:
            letters += 1
    return letters


def get_words(text):
    words = 1
    for i in range(len(text)):
        x = text[i]
        if x.isspace() == True:
            words += 1
    return words


def get_sentences(text):
    sentences = 0
    for i in range(len(text)):
        x = text[i]
        if x == '.' or x == '!' or x == '?':
            sentences += 1
    return sentences


main()