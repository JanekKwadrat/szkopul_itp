def hash29(s: str)->int:
    MOD = 4294967291
    P = 29
    ans = 0
    for c in s:
        x = ord(c) - ord('a') + 1
        ans = (ans * P + x) % MOD
    return ans

def get_hashed(text: str)->list[int]:
    text = ''.join(c for c in text if c.isalpha() or c == ' ')
    text = text.lower()

    words = text.split()
    hashed = [hash29(s) for s in words]
    return hashed

class Book:
    def __init__(self):
        self.text = None
        self.hashed = list()
        self.freqs = dict()
        self.probs = dict()
        self.image = list()

books = [Book() for i in range(3)]
with open('pis_dlazaw/Mickiewicz.txt', 'r') as f: books[0].text = f.read()
with open('pis_dlazaw/Prus.txt', 'r') as f: books[1].text = f.read()
with open('pis_dlazaw/Sienkiewicz.txt', 'r') as f: books[2].text = f.read()

for book in books:
    book.hashed = get_hashed(book.text)
    for h in book.hashed:
        if h in book.freqs: book.freqs[h] += 1
        else: book.freqs[h] = 1
    #for h in book.hashed: book.freqs[h] /= len(book.hashed)



