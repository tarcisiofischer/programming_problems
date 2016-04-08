import re

with open('names.txt', 'r') as f:
  names = re.findall('\w+', f.readline())
names.sort()
total_sum = 0
for i, name in enumerate(names):
  total_sum += sum([ord(letter) - 64 for letter in name]) * (i + 1)
print total_sum

