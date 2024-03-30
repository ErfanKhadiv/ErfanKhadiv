def main():
    text = input("Enter your text: ")

    words = words_count(text)
    letters = letters_count(text)
    sentances = sentances_count(text)

    L = letters / words * 100
    S = sentances / words * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    result = round(index)

    if result < 1:
        print("Before Grade 1")
    elif 1 < result < 16:
        print(f"Grade {result}")
    else:
        print("Grade 16+")


def words_count(text):
    n = len(text)
    space = ' '
    count = 0
    for i in range(n):
        if text[i] == space:
            count += 1
    words = count + 1
    return words


def letters_count(text):
    n = len(text)
    space = ' '
    count = n
    for i in range(n):
        if text[i] == space or text[i] == '.' or text[i] == ',' or text[i] == '!' or text[i] == '?' or text[i] == "'":
            count -= 1
    return count


def sentances_count(text):
    n = len(text)
    count = 0
    for i in range(n):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            count += 1
    return count


main()
