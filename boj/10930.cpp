import hashlib
data = input();
data = data.encode('utf-8')
hash_object = hashlib.sha256(data);
hex_dig = hash_object.hexdigest()
print(hex_dig)
