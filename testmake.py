import random
import string

def write_to_file(filename, data):
    with open(filename, "w") as text_file:
        text_file.write(data)

pattern = ''.join(random.choices(string.ascii_uppercase + string.digits, k=100))
write_to_file('pattern.txt', pattern)

data1000 = ''.join(random.choices(string.ascii_uppercase + string.digits, k=1000-100))+pattern
write_to_file('data1000.txt', data1000)
                  
data10000 = ''.join(random.choices(string.ascii_uppercase + string.digits, k=10000-100))+pattern
write_to_file('data10000.txt', data10000)
                   
data100000 = ''.join(random.choices(string.ascii_uppercase + string.digits, k=100000-100))+pattern
write_to_file('data100000.txt', data100000)
                   
data1000000 = ''.join(random.choices(string.ascii_uppercase + string.digits, k=1000000-100))+pattern
write_to_file('data1000000.txt', data1000000)