# 遊び方

```
mkfifo pipe
mkfifo pipe2
python3 server.py > pipe < pipe2
./a.out < pipe > pipe2
```