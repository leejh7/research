# f = open('/Volumes/Programming/PositionMove/DATA/orialpha1.dat', 'r', encoding='utf-8')

# data = f.read()
# print(data)

# f.close()

from turtle import color
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

original_a = [1070, 663, 615]
position_move_a = [450, 451, 450]

original_b = [1440, 1210, 1220]
position_move_b = [1010, 1010, 1010]

ticks = ['a', 'a', 'a', 'b', 'b', 'b']
algorithms = ['Random', 'WP', 'GO']

df = pd.DataFrame(
  {
    'Original_a' : original_a, 'PM_a' : position_move_a,
    'Original_b' : original_b, 'PM_b' : position_move_b
  }, index = algorithms)


# 그림 사이즈, 바 굵기 조정
fig, ax = plt.subplots(figsize=(12,6))
bar_width = 0.25

# 연도가 4개이므로 0, 1, 2, 3 위치를 기준으로 삼음
index_a = np.arange(3)
index_b = np.arange(bar_width, 3+bar_width)
index = np.concatenate((index_a, index_b))

# 각 연도별로 3개 샵의 bar를 순서대로 나타내는 과정, 각 그래프는 0.25의 간격을 두고 그려짐
b1 = plt.bar(index_a, df['Original_a'], bar_width, alpha=0.4, color='red', label='Original')

b2 = plt.bar(index_a, df['PM_a'], bar_width, alpha=0.4, color='blue', label='PM')

b3 = plt.bar(index_b, df['Original_b'], bar_width, alpha=0.4, color='red')

b4 = plt.bar(index_b, df['PM_b'], bar_width, alpha=0.4, color='blue')

# x축 위치를 정 가운데로 조정하고 x축의 텍스트를 year 정보와 매칭
plt.xticks(index, ticks)

# x축, y축 이름 및 범례 설정
plt.xlabel('Random', loc='left')
plt.ylabel('Number of Violations', size = 13)
plt.legend()
plt.show()
