
X = [90,95,97,98,100,60]

Y = [60,70,80,60,90,75]

sum_1 = 0
for i in X: 
    sum_1 += i

print("SUM_X:", sum_1)

sum_2 = 0
for i in range(len(X)):
    sum_2 += X[i] * Y[i]

print("SUM_X*SUM_Y:", sum_2)