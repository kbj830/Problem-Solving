a, b = input().split()
e = (len(a) -1) - a.find('.')
a = a.replace('.', '')
result = str(int(a) ** int(b))
e *= int(b)
if len(result) < e:
    result = '0'*(e-len(result)) + result

result = result[:-e] + '.' + result[-e:]

if result[0] == '.':
    print('0' + result)
else:
    print(result)