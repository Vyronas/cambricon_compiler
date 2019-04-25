import re
import numpy as np

with open("mnist_low_IR.txt",'r') as file:
    data = file.read()

print()


matches = re.findall(r'\= [a-z]*',data)
a=np.array(matches)

print(np.unique(a))
