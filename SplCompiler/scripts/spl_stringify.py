to_stringify = input("Enter your string:\n")
print("ASCII variable declarations:")
print("space, period, bra, ket, plus, carot OF TYPE CHARACTER;")
print("\n")
print("ASCII variable definitions:")
print("32 -> space;")
print("46 -> period;")
print("40 -> bra;")
print("41 -> ket;")
print("94 -> carot;")
print("43 -> plus;")
print("\n")
print("WRITE(", end='', sep='')
for c in to_stringify:
    if (str.isdigit(c)):
        print(c, ", ", end='', sep='')
        continue
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
    if (c == '+'):
        print("plus", ", ", end='', sep='')
        continue
    if (c == "^"):
        print("carot", ", ", end='', sep='')
        continue
    print("'", c, "', ", end='', sep='')
print(");", end='', sep='')