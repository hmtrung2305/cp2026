s = input()

q = []
for i in range(len(s)):
    if s[i] == '?':
        q.append(i)

ans = -10**6
for x in range(10):
    for y in range(10):
        t = list(s)
        if 0 < len(q):
            t[q[0]] = chr(ord('0') + x)
        if 1 < len(q):
            t[q[1]] = chr(ord('0') + y)
        ans = max(ans, eval(' '.join(t)))
print(ans)