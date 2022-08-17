import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

output_a_path = sys.argv[1]
output_b_path = sys.argv[2]
data_path = sys.argv[3]

algorithms = ['Random', 'WP', 'GO']

f = open(output_a_path, 'r', encoding='utf-8')
data_a = list(map(int,list(map(lambda x: x[:-1].split()[1], f.readlines()))))

original_a = data_a[:(len(algorithms))]
position_move_a = data_a[(len(algorithms)):]

f.close()

f = open(output_b_path, 'r', encoding='utf-8')
data_b = list(map(int,list(map(lambda x: x[:-1].split()[1], f.readlines()))))

original_b = data_b[:(len(algorithms))]
position_move_b = data_b[(len(algorithms)):]

f.close()

ticks = ['a', 'a', 'a', 'b', 'b', 'b']

df = pd.DataFrame(
  {
    'Original_a' : original_a, 'PM_a' : position_move_a,
    'Original_b' : original_b, 'PM_b' : position_move_b
  }, index = algorithms)


fig, ax = plt.subplots(figsize=(12,6))
bar_width = 0.25

index_a = np.arange(3)
index_b = np.arange(bar_width, 3+bar_width)
index = np.concatenate((index_a, index_b))

b1 = plt.bar(index_a, df['Original_a'], bar_width, alpha=0.4, color='red', label='Original',
edgecolor='black', linewidth=1)

b2 = plt.bar(index_a, df['PM_a'], bar_width, alpha=0.4, color='blue', label='PM',
edgecolor='black', linewidth=1, hatch='/')

b3 = plt.bar(index_b, df['Original_b'], bar_width, alpha=0.4, color='red',
edgecolor='black', linewidth=1)

b4 = plt.bar(index_b, df['PM_b'], bar_width, alpha=0.4, color='blue',
edgecolor='black', linewidth=1, hatch='/')

plt.xticks(index, ticks)

plt.xlabel('''Random                                                        GO                                               WP''', size=13)
plt.ylabel('Number of Violations', size = 13)
plt.legend()
# plt.show()

plt.savefig(data_path + '/myfigure.pdf', dpi=500)