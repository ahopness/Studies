arr = [[10, 12, 14], [16,18,20], [22, 24, 26]]

print("digite um numero")
num = int(input())

encontrou = False
for i in range(len(arr)):
    for j in range(len(arr[i])):
        if arr[i][j] == num:
            encontrou = True

if encontrou:
    print("esse numero esta presente no array!")
else:
    print("esse numero NÃO esta presente no array!")
