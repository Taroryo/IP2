# 課題2

a = [1,1,1]
a[0] = float( input('数値1:') )
a[1] = float( input('数値2:') )
a[2] = float( input('数値3:') )

sum = a[0]+a[1]+a[2]
ave = sum/3
for i in range(len(a)):
    for j in range(len(a) - i -1):
        if a[j] > a[j+1]:
            tmp = a[j]
            a[j] = a[j+1]
            a[j+1] = tmp

f = open('result.txt', 'w', encoding='utf-8')

f.write("大きい順")
for i in range(len(a)-1,-1,-1):
    f.write(' ')
    f.write(str(a[i]))
f.write('\n')
f.write("小さい順")
for i in range(len(a)):
    f.write(' ')
    f.write(str(a[i]))
f.write('\n')
f.write("平均値 ")
f.write('{:.1f}'.format( ave ))
f.write('\n')
f.close()
