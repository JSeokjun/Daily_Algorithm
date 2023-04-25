h1, m1, s1 = map(int, input().split(":"))
h2, m2, s2 = map(int, input().split(":"))

if s1>s2:
    s2+=60
    m2-=1
s=s2-s1

if m1>m2:
    m2+=60
    h2-=1
m=m2-m1

if h1>h2:
    h2+=24
h=h2-h1

print("%02d:%02d:%02d" %(h, m, s))