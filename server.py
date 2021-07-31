from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes
from Crypto.Hash import HMAC, SHA256
import sys
import base64

flag = b"kurenaifCTF{POOOOOOOOOOOOOOOOOOOOODLE}"

def add_digest(b, secret):
    h = HMAC.new(secret, digestmod=SHA256)
    h.update(b)
    return b + h.digest()

def check_digest(b, mac, secret):
    h = HMAC.new(secret, digestmod=SHA256)
    h.update(b)
    return h.digest() == mac
    try:
        h.verify(mac)
        return True
    except ValueError:
        return False

def comm():
    ### input prefix###
    prefix = int(input())
    prefix = b" " * prefix

    ### input suffix ###
    suffix = int(input())
    suffix = b" " * suffix

    ### make cipher ###
    message = prefix + flag + suffix

    key = get_random_bytes(16)
    message = add_digest(message, key)
    cipher = AES.new(key, AES.MODE_CBC)
    iv = cipher.iv
    c = cipher.encrypt(pad(message, AES.block_size))

    print(len(c), flush=True)
    for i in range(len(c)):
        print(c[i], end='' if i == len(c) - 1 else ' ')
    print('', flush=True)

    ### validate ###
    c = bytes(list(map(lambda x: int(x), input().strip().split())))
    message = add_digest(message, key)
    cipher = AES.new(key, AES.MODE_CBC, iv=iv)
    message = cipher.decrypt(c)
    message = message[:-message[-1]]
    message, mac = message[:-32], message[-32:]
    if check_digest(message, mac, key):
        print("result:ok", flush=True)
    else:
        print("result:ng", flush=True)

while True:
    comm()
