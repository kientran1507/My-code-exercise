# Function to convert a number to its word representation
def number_to_words(n):
    units = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    teens = ["", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    tens = ["", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
    
    if 1 <= n <= 9:
        return units[n]
    elif 11 <= n <= 19:
        return teens[n - 10]
    elif 21 <= n <= 99:
        return tens[n // 10] + units[n % 10]
    elif n == 1000:
        return "onethousand"
    
    words = ""
    
    if n >= 100:
        words += units[n // 100] + "hundred"
        if n % 100 != 0:
            words += "and"
    
    if n % 100 <= 9:
        words += units[n % 100]
    elif 11 <= n % 100 <= 19:
        words += teens[n % 100 - 10]
    else:
        words += tens[(n % 100) // 10] + units[n % 10]
    
    return words

# Calculate the total number of letters used for numbers from 1 to 1000
total_letters = 0
for number in range(1, 1001):
    word = number_to_words(number)
    total_letters += len(word)

print("Total letters used for numbers from 1 to 1000:", total_letters)
