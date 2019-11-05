to_stringify = input("Enter your string:\n")
for c in to_stringify:
    if (c == ' '):
        print("space", ", ", end='', sep='')
        continue
    if (c == '.'):
        print("period", ", ", end='', sep='')
        continue
    if (c == '('):
        print("bra", ", ", end='', sep='')
        continue
    if (c == ')'):
        print("ket", ", ", end='', sep='')
        continue
    print("'", c, "', ", end='', sep='')