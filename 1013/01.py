# 課題1
number = int( input('n = ? ') )
for i in range(1,number+1,1):
    answer = 1
    for j in range(1,i+1,1):
        answer = answer * (j)
    print(i,'!= ',answer,sep='')
