def computer_to_phone(numbers):
    return numbers.translate(numbers.maketrans('123789','789123'))